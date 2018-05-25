#include "ToyUtility/Serialization/JsonUnserializer.h"

#include "ToyUtility/Math/Vector2.h"
#include "ToyUtility/Math/Vector3.h"

using namespace rapidjson;


namespace ToyUtility
{


JsonUnserializer::JsonUnserializer(DataStream & stream)
    :
    Unserializer(stream),
    m_Index(0),
    m_StringStream("")
{
    m_JsonString = stream.GetAsString();

    JsonEventHandler handler;
    m_StringStream = StringStream(m_JsonString.c_str());
    m_Reader.Parse(m_StringStream, handler);

    m_JsonEvents.swap(handler.JsonEvents);
    m_StringCaches.swap(handler.StringCaches);

    m_Index = 1; // Skip the root node, see more at JsonSerializer::JsonSerializer
}

JsonUnserializer::~JsonUnserializer()
{
}

void JsonUnserializer::Pop(const String & fieldName, uint8 & v)
{
    auto& key = m_JsonEvents[m_Index++];
    // TODOM: key._string == fieldName

    auto& value = m_JsonEvents[m_Index++];
    // TODOM: check value.Type, and check number range
    v = value.Data._uint;
}

void JsonUnserializer::Pop(const String & fieldName, int8 & v)
{
    auto& key = m_JsonEvents[m_Index++];

    auto& value = m_JsonEvents[m_Index++];
    v = value.Data._int;
}

void JsonUnserializer::Pop(const String & fieldName, uint16 & v)
{
    auto& key = m_JsonEvents[m_Index++];

    auto& value = m_JsonEvents[m_Index++];
    v = value.Data._uint;
}

void JsonUnserializer::Pop(const String & fieldName, int16 & v)
{
    auto& key = m_JsonEvents[m_Index++];

    auto& value = m_JsonEvents[m_Index++];
    v = value.Data._int;
}

void JsonUnserializer::Pop(const String & fieldName, uint32 & v)
{
    auto& key = m_JsonEvents[m_Index++];

    auto& value = m_JsonEvents[m_Index++];
    v = value.Data._uint;
}

void JsonUnserializer::Pop(const String & fieldName, int32 & v)
{
    auto& key = m_JsonEvents[m_Index++];

    auto& value = m_JsonEvents[m_Index++];
    v = value.Data._int;
}

void JsonUnserializer::Pop(const String & fieldName, bool & v)
{
    auto& key = m_JsonEvents[m_Index++];

    auto& value = m_JsonEvents[m_Index++];
    v = value.Data._bool;
}

void JsonUnserializer::Pop(const String & fieldName, float & v)
{
    auto& key = m_JsonEvents[m_Index++];

    auto& value = m_JsonEvents[m_Index++];
    v = value.Data._double;
}

void JsonUnserializer::Pop(const String & fieldName, double & v)
{
    auto& key = m_JsonEvents[m_Index++];

    auto& value = m_JsonEvents[m_Index++];
    v = value.Data._double;
}

void JsonUnserializer::Pop(const String & fieldName, String & v)
{
    auto& key = m_JsonEvents[m_Index++];

    auto& value = m_JsonEvents[m_Index++];
    v = m_StringCaches[value.Data._uint];
}

void JsonUnserializer::Pop(const String & fieldName, Vector2 & v)
{
    auto& _fieldName = m_JsonEvents[m_Index++]; // fieldName
    auto& startArray = m_JsonEvents[m_Index++];
    auto& x = m_JsonEvents[m_Index++];
    auto& y = m_JsonEvents[m_Index++];
    auto& endArray = m_JsonEvents[m_Index++];

    v.x = x.Data._double;
    v.y = y.Data._double;
}

void JsonUnserializer::Pop(const String & fieldName, Vector3 & v)
{
    auto& _fieldName = m_JsonEvents[m_Index++]; // fieldName
    auto& startArray = m_JsonEvents[m_Index++];
    auto& x = m_JsonEvents[m_Index++];
    auto& y = m_JsonEvents[m_Index++];
    auto& z = m_JsonEvents[m_Index++];
    auto& endArray = m_JsonEvents[m_Index++];

    v.x = x.Data._double;
    v.y = y.Data._double;
    v.z = z.Data._double;
}


void JsonUnserializer::BeginDictionary(const String & name)
{
    auto& key = m_JsonEvents[m_Index++];
    auto& startObject = m_JsonEvents[m_Index++];
}

void JsonUnserializer::EndDictionary()
{
    auto& endObject = m_JsonEvents[m_Index++];
}

void JsonUnserializer::BeginArray(const String & name)
{
    auto& key = m_JsonEvents[m_Index++];
    auto& startArray = m_JsonEvents[m_Index++];
}

void JsonUnserializer::EndArray()
{
    auto& endArray = m_JsonEvents[m_Index++];
}


} // end of namespace ToyUtility