#include "ToyUtility/Serialization/JsonSerializer.h"

#include "ToyUtility/Math/Vector2.h"
#include "ToyUtility/Math/Vector3.h"
#include "ToyUtility/Log/Logger.h"


namespace ToyUtility
{


JsonSerializer::JsonSerializer(DataStream & stream)
    :
    Serializer(stream),
    m_Writer(m_StringBuffer)
{
    m_Writer.SetIndent('\t', 1);

    m_Writer.StartObject(); // Create the root node
}

JsonSerializer::~JsonSerializer()
{
}

void JsonSerializer::Push(const uint8 v, const String & fieldName)
{
    m_Writer.Key(fieldName.c_str());
    m_Writer.Uint(v);
}

void JsonSerializer::Push(const int8 v, const String & fieldName)
{
    m_Writer.Key(fieldName.c_str());
    m_Writer.Int(v);
}

void JsonSerializer::Push(const uint16 v, const String & fieldName)
{
    m_Writer.Key(fieldName.c_str());
    m_Writer.Uint(v);
}

void JsonSerializer::Push(const int16 v, const String & fieldName)
{
    m_Writer.Key(fieldName.c_str());
    m_Writer.Int(v);
}

void JsonSerializer::Push(const uint32 v, const String & fieldName)
{
    m_Writer.Key(fieldName.c_str());
    m_Writer.Uint(v);
}

void JsonSerializer::Push(const int32 v, const String & fieldName)
{
    m_Writer.Key(fieldName.c_str());
    m_Writer.Int(v);
}

void JsonSerializer::Push(const bool v, const String & fieldName)
{
    m_Writer.Key(fieldName.c_str());
    m_Writer.Bool(v);
}

void JsonSerializer::Push(const float v, const String & fieldName)
{
    m_Writer.Key(fieldName.c_str());
    m_Writer.Double(v);
}

void JsonSerializer::Push(const double v, const String & fieldName)
{
    m_Writer.Key(fieldName.c_str());
    m_Writer.Double(v);
}

void JsonSerializer::Push(const String & v, const String & fieldName)
{
    m_Writer.Key(fieldName.c_str());
    m_Writer.String(v.c_str());
}

void JsonSerializer::Push(const Vector2 & v, const String & fieldName)
{
    m_Writer.Key(fieldName.c_str());
    {
        m_Writer.StartArray();
        m_Writer.Double(v.x);
        m_Writer.Double(v.y);
        m_Writer.EndArray();
    }
}

void JsonSerializer::Push(const Vector3 & v, const String & fieldName)
{
    m_Writer.Key(fieldName.c_str());
    {
        m_Writer.StartArray();
        m_Writer.Double(v.x);
        m_Writer.Double(v.y);
        m_Writer.Double(v.z);
        m_Writer.EndArray();
    }
}

void JsonSerializer::BeginDictionary(const String & name)
{
    m_Writer.Key(name.c_str());
    m_Writer.StartObject();
}

void JsonSerializer::EndDictionary()
{
    m_Writer.EndObject();
}

void JsonSerializer::BeginArray(const String & name)
{
    m_Writer.Key(name.c_str());
    m_Writer.StartArray();
}

void JsonSerializer::EndArray()
{
    m_Writer.EndArray();
}

void JsonSerializer::Flush()
{
    m_Writer.EndObject(); // End the root node

    if (m_Writer.IsComplete())
    {
        m_Stream.Write(m_StringBuffer.GetString(), m_StringBuffer.GetSize());
    }
    else
    {
        // TODOH error handle
        TOY_RAW_LOG_ERR << "JsonSerializer::Flush: json writer isn't complete" << std::endl;
    }
}


} // end of namespace ToyUtility