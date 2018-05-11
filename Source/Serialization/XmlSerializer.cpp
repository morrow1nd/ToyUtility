#include "ToyUtility/Serialization/XmlSerializer.h"

#include "rapidxml/rapidxml_print.hpp"
#include "ToyUtility/Log/Logger.h"
#include "ToyUtility/Math/Vector3.h"
#include "ToyUtility/Math/Vector2.h"


namespace ToyUtility
{


using namespace rapidxml;


XmlSerializer::XmlSerializer(DataStream & stream)
    :
    Serializer(stream)
{}

XmlSerializer::~XmlSerializer()
{
    m_Doc.clear();
}

void XmlSerializer::Push(const uint8 v, const String & fieldName)
{
    _AttachNode(fieldName, std::to_string(v));
}

void XmlSerializer::Push(const int8 v, const String & fieldName)
{
    _AttachNode(fieldName, std::to_string(v));
}

void XmlSerializer::Push(const uint16 v, const String & fieldName)
{
    _AttachNode(fieldName, std::to_string(v));
}

void XmlSerializer::Push(const int16 v, const String & fieldName)
{
    _AttachNode(fieldName, std::to_string(v));
}

void XmlSerializer::Push(const uint32 v, const String & fieldName)
{
    _AttachNode(fieldName, std::to_string(v));
}

void XmlSerializer::Push(const int32 v, const String & fieldName)
{
    _AttachNode(fieldName, std::to_string(v));
}

void XmlSerializer::Push(const bool v, const String & fieldName)
{
    _AttachNode(fieldName, (v ? "true" : "false"));
}

void XmlSerializer::Push(const float v, const String & fieldName)
{
    _AttachNode(fieldName, std::to_string(v));
}

void XmlSerializer::Push(const double v, const String & fieldName)
{
    _AttachNode(fieldName, std::to_string(v));
}

void XmlSerializer::Push(const String & v, const String & fieldName)
{
    _AttachNode(fieldName, v);
}

void XmlSerializer::Push(const Vector2 & v, const String & fieldName)
{
    m_TemStrStream.clear();
    m_TemStrStream << "(" << v.x << ", " << v.y << ")";

    _AttachNode(fieldName, m_TemStrStream.str());
}

void XmlSerializer::Push(const Vector3 & v, const String & fieldName)
{
    m_TemStrStream.clear();
    m_TemStrStream << "(" << v.x << ", " << v.y << ", " << v.z << ")";

    _AttachNode(fieldName, m_TemStrStream.str());
}

void XmlSerializer::BeginDictionary(const String& name)
{
    auto node = _CreateNode(name);
    m_NodesStack.push_back(node);

    //return SerializerDictionaryBlock(this);
}

void XmlSerializer::EndDictionary()
{
    auto node = m_NodesStack.back();
    m_NodesStack.resize(m_NodesStack.size() - 1);

    if (m_NodesStack.empty())
    {
        m_Doc.append_node(node);
    }
    else
    {
        m_NodesStack.back()->append_node(node);
    }
}

void XmlSerializer::BeginArray(const String & name)
{
    BeginDictionary(name);
}

void XmlSerializer::EndArray()
{
    EndDictionary();
}

void XmlSerializer::Flush()
{
    std::string s;
    rapidxml::print(std::back_inserter(s), m_Doc, 0);
    m_Stream.WriteString(s);
}

rapidxml::xml_node<>* XmlSerializer::_CreateNode(const String& nodeName, const String& value)
{
    xml_node<>* node = m_Doc.allocate_node(node_type::node_element,
        nodeName == "" ? "unnamed_xml_node" : m_Doc.allocate_string(nodeName.c_str()),
        m_Doc.allocate_string(value.c_str()));
    return node;
}

void XmlSerializer::_AttachNode(const String& nodeName, const String& value)
{
    if (m_NodesStack.empty())
    {
        m_Doc.append_node(_CreateNode(nodeName, value));
    }
    else
    {
        m_NodesStack.back()->append_node(_CreateNode(nodeName, value));
    }
}


} // end of namespace ToyUtility