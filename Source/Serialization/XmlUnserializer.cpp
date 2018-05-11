#include "ToyUtility/Serialization/XmlUnserializer.h"

#include <exception>
#include "rapidxml/rapidxml_print.hpp"
#include "ToyUtility/Log/Logger.h"
#include "ToyUtility/Math/Vector3.h"
#include "ToyUtility/Math/Vector2.h"


namespace ToyUtility
{


using namespace rapidxml;


XmlUnserializer::XmlUnserializer(DataStream & stream)
    :
    m_Buffer(nullptr),
    m_BufferLength(0),
    m_CurrNode(nullptr),
    Unserializer(stream)
{
    if (stream.IsReadable() == false)
    {
        TOY_RAW_LOG_ERR << "XmlUnserializer data stream is not readable.\n";
        return;
    }

    m_BufferLength = stream.Size();
    m_Buffer = new char[m_BufferLength + 1];
    auto realReadBytes = m_Stream.Read(m_Buffer, m_BufferLength);
    if (realReadBytes != m_BufferLength)
    {
        TOY_RAW_LOG_ERR << "XmlUnserializer: realReadBytes != m_BufferLength\n";
    }
    m_Buffer[realReadBytes] = '\0';

    try
    {
        m_Doc.parse<0>(m_Buffer);
    }
    catch (rapidxml::parse_error e)
    {
        TOY_RAW_LOG_ERR << "XmlUnserializer: m_Doc.parse throw exception: " << e.what() << "\n";
        return;
    }

    m_CurrNode = &m_Doc;
    _GotoNextNode();
}

XmlUnserializer::~XmlUnserializer()
{
    if (m_Buffer != nullptr)
    {
        delete[] m_Buffer;
        m_Buffer = nullptr;
    }

    m_Doc.clear();
}

#define TOY_XML_UNSERIALIZER_STR_TO_INT_HELPER(StrToNumberFuncName)                         \
if (m_CurrNode == nullptr)                                                                  \
{                                                                                           \
    TOY_RAW_LOG_ERR << "XmlUnserializer: m_CurrNode == nullptr\n";                          \
    return;                                                                                 \
}                                                                                           \
size_t endPos;                                                                              \
auto res = StrToNumberFuncName(m_CurrNode->value(), &endPos, 0);                            \
if (endPos != m_CurrNode->value_size())                                                     \
{                                                                                           \
    TOY_RAW_LOG_ERR << "XmlUnserializer: Format error: " << m_CurrNode->value() << "\n";    \
}                                                                                           \
v = res;                                                                                    \
_GotoNextNode();

void XmlUnserializer::Pop(const String & fieldName, uint8 & v)
{
    TOY_XML_UNSERIALIZER_STR_TO_INT_HELPER(std::stoul);
}

void XmlUnserializer::Pop(const String & fieldName, int8 & v)
{
    TOY_XML_UNSERIALIZER_STR_TO_INT_HELPER(std::stoi);
}

void XmlUnserializer::Pop(const String & fieldName, uint16 & v)
{
    TOY_XML_UNSERIALIZER_STR_TO_INT_HELPER(std::stoul);
}

void XmlUnserializer::Pop(const String & fieldName, int16 & v)
{
    TOY_XML_UNSERIALIZER_STR_TO_INT_HELPER(std::stoi);
}

void XmlUnserializer::Pop(const String & fieldName, uint32 & v)
{
    TOY_XML_UNSERIALIZER_STR_TO_INT_HELPER(std::stoul);
}

void XmlUnserializer::Pop(const String & fieldName, int32 & v)
{
    TOY_XML_UNSERIALIZER_STR_TO_INT_HELPER(std::stoi);
}

void XmlUnserializer::Pop(const String & fieldName, bool & v)
{
    if (m_CurrNode == nullptr)
    {
        TOY_RAW_LOG_ERR << "XmlUnserializer: m_CurrNode == nullptr\n";
        return;
    }

    v = String(m_CurrNode->value()) == "true";
    _GotoNextNode();
}

void XmlUnserializer::Pop(const String & fieldName, float & v)
{
    if (m_CurrNode == nullptr)
    {
        TOY_RAW_LOG_ERR << "XmlUnserializer: m_CurrNode == nullptr\n";
        return;
    }

    size_t endPos;
    auto res = std::stof(m_CurrNode->value(), &endPos);
    if (endPos != m_CurrNode->value_size())
    {
        /*TODOM */
    }
    v = res;
    _GotoNextNode();
}

void XmlUnserializer::Pop(const String & fieldName, double & v)
{
    if (m_CurrNode == nullptr)
    {
        TOY_RAW_LOG_ERR << "XmlUnserializer: m_CurrNode == nullptr\n";
        return;
    }

    size_t endPos;
    auto res = std::stod(m_CurrNode->value(), &endPos);
    if (endPos != m_CurrNode->value_size())
    {
        /*TODOM */
    }
    v = res;
    _GotoNextNode();
}

void XmlUnserializer::Pop(const String & fieldName, String & v)
{
    if (m_CurrNode == nullptr)
    {
        TOY_RAW_LOG_ERR << "XmlUnserializer: m_CurrNode == nullptr\n";
        return;
    }

    v = String(m_CurrNode->value());
    _GotoNextNode();
}

void XmlUnserializer::Pop(const String & fieldName, Vector2 & v)
{
    if (m_CurrNode == nullptr)
    {
        TOY_RAW_LOG_ERR << "XmlUnserializer: m_CurrNode == nullptr\n";
        return;
    }

    size_t begin = 0;
    size_t end;
    float f;

    _ConsumeCharacter(m_CurrNode->value(), m_CurrNode->value_size(), begin, &end, '(');
    if (end == begin)
    {
        TOY_RAW_LOG_ERR << "XmlUnserializer: Format error: " << String(m_CurrNode->value()) << "\n";
        return;
    }

    begin = end;
    _ConsumeFloat(m_CurrNode->value(), m_CurrNode->value_size(), begin, &end, &f);
    if (begin == end)
    {
        TOY_RAW_LOG_ERR << "XmlUnserializer: Format error: " << String(m_CurrNode->value()) << "\n";
        return;
    }
    v.x = f;

    begin = end;
    _ConsumeCharacter(m_CurrNode->value(), m_CurrNode->value_size(), begin, &end, ',');
    if (end == begin)
    {
        TOY_RAW_LOG_ERR << "XmlUnserializer: Format error: " << String(m_CurrNode->value()) << "\n";
        return;
    }

    begin = end;
    _ConsumeFloat(m_CurrNode->value(), m_CurrNode->value_size(), begin, &end, &f);
    if (begin == end)
    {
        TOY_RAW_LOG_ERR << "XmlUnserializer: Format error: " << String(m_CurrNode->value()) << "\n";
        return;
    }
    v.y = f;

    begin = end;
    _ConsumeCharacter(m_CurrNode->value(), m_CurrNode->value_size(), begin, &end, ')');
    if (end == begin)
    {
        TOY_RAW_LOG_ERR << "XmlUnserializer: Format error: " << String(m_CurrNode->value()) << "\n";
        return;
    }
    
    _GotoNextNode();
}

void XmlUnserializer::Pop(const String & fieldName, Vector3 & v)
{
    if (m_CurrNode == nullptr)
    {
        TOY_RAW_LOG_ERR << "XmlUnserializer: m_CurrNode == nullptr\n";
        return;
    }

    size_t begin = 0;
    size_t end;
    float f;

    _ConsumeCharacter(m_CurrNode->value(), m_CurrNode->value_size(), begin, &end, '(');
    if (end == begin)
    {
        TOY_RAW_LOG_ERR << "XmlUnserializer: Format error: " << String(m_CurrNode->value()) << "\n";
        return;
    }

    begin = end;
    _ConsumeFloat(m_CurrNode->value(), m_CurrNode->value_size(), begin, &end, &f);
    if (begin == end)
    {
        TOY_RAW_LOG_ERR << "XmlUnserializer: Format error: " << String(m_CurrNode->value()) << "\n";
        return;
    }
    v.x = f;

    begin = end;
    _ConsumeCharacter(m_CurrNode->value(), m_CurrNode->value_size(), begin, &end, ',');
    if (end == begin)
    {
        TOY_RAW_LOG_ERR << "XmlUnserializer: Format error: " << String(m_CurrNode->value()) << "\n";
        return;
    }

    begin = end;
    _ConsumeFloat(m_CurrNode->value(), m_CurrNode->value_size(), begin, &end, &f);
    if (begin == end)
    {
        TOY_RAW_LOG_ERR << "XmlUnserializer: Format error: " << String(m_CurrNode->value()) << "\n";
        return;
    }
    v.y = f;

    begin = end;
    _ConsumeCharacter(m_CurrNode->value(), m_CurrNode->value_size(), begin, &end, ',');
    if (end == begin)
    {
        TOY_RAW_LOG_ERR << "XmlUnserializer: Format error: " << String(m_CurrNode->value()) << "\n";
        return;
    }

    begin = end;
    _ConsumeFloat(m_CurrNode->value(), m_CurrNode->value_size(), begin, &end, &f);
    if (begin == end)
    {
        TOY_RAW_LOG_ERR << "XmlUnserializer: Format error: " << String(m_CurrNode->value()) << "\n";
        return;
    }
    v.z = f;

    begin = end;
    _ConsumeCharacter(m_CurrNode->value(), m_CurrNode->value_size(), begin, &end, ')');
    if (end == begin)
    {
        TOY_RAW_LOG_ERR << "XmlUnserializer: Format error: " << String(m_CurrNode->value()) << "\n";
        return;
    }

    _GotoNextNode();
}

void XmlUnserializer::BeginDictionary(const String & name)
{
    _GotoNextNode();
}

void XmlUnserializer::EndDictionary()
{
    // Nothing
}

void XmlUnserializer::BeginArray(const String & name)
{
    BeginDictionary(name);
}

void XmlUnserializer::EndArray()
{
    EndDictionary();
}

void XmlUnserializer::_GotoNextNode()
{
    if (m_CurrNode == nullptr)
    {
        TOY_RAW_LOG_ERR << "XmlUnserializer::_GotoNextNode: m_CurrNode == nullptr\n";
        return;
    }

    if (m_CurrNode->first_node() != nullptr)
    {
        m_CurrNode = m_CurrNode->first_node();
    }
    else
    {
        if (m_CurrNode->next_sibling() != nullptr)
        {
            m_CurrNode = m_CurrNode->next_sibling();
        }
        else
        {
            while (m_CurrNode->next_sibling() != nullptr)
            {
                m_CurrNode = m_CurrNode->parent();
                if (m_CurrNode == nullptr)
                {
                    break;
                }
            }
        }
    }
}

void XmlUnserializer::_ConsumeFloat(const char * str, size_t strLen, size_t begin, size_t * end, float * value)
{
    if (str == nullptr)
    {
        *end = begin;
        return;
    }

    size_t i = begin;
    for (; i < strLen; ++i)
    {
        if (str[i] == ' ' || str[i] == '\t')
        {
            continue;
        }
        else
        {
            break;
        }
    }

    char* end_position;
    errno = 0;
    float v = std::strtof(str + i, &end_position);
    if (str + i == end_position)
    {
        // Invalid argument
        *end = begin;
        return;
    }
    if (errno == ERANGE)
    {
        // Out of range
        *end = begin;
        return;
    }
    
    *end = end_position - str;
    *value = v;
}

void XmlUnserializer::_ConsumeCharacter(const char * str, size_t strLen, size_t begin, size_t * end, const char & c)
{
    if (str == nullptr)
    {
        *end = begin;
        return;
    }

    for (size_t i = begin; i < strLen; ++i)
    {
        if (str[i] == ' ' || str[i] == '\t')
        {
            continue;
        }
        else if (str[i] == c)
        {
            *end = i + 1;
            return;
        }
        else
        {
            // failed to consume this character
            *end = begin;
            return;
        }
    }
}


} // end of namespace ToyUtility