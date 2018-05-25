#pragma once

#include <sstream>

#include <rapidjson/prettywriter.h>
#include <rapidjson/stringbuffer.h>

#include "ToyUtility/Prerequisites/PreDefine.h"
#include "ToyUtility/Serialization/Serializer.h"


namespace ToyUtility
{


class JsonSerializer : public Serializer
{
public:
    JsonSerializer(DataStream& stream);

    virtual ~JsonSerializer() override;


public:
    // Push Operation
    virtual void Push(const uint8 v, const String& fieldName = "") override;
    virtual void Push(const int8 v, const String& fieldName = "") override;
    virtual void Push(const uint16 v, const String& fieldName = "") override;
    virtual void Push(const int16 v, const String& fieldName = "") override;
    virtual void Push(const uint32 v, const String& fieldName = "") override;
    virtual void Push(const int32 v, const String& fieldName = "") override;
    virtual void Push(const bool v, const String& fieldName = "") override;
    virtual void Push(const float v, const String& fieldName = "") override;
    virtual void Push(const double v, const String& fieldName = "") override;
    virtual void Push(const String& v, const String& fieldName = "") override;
    virtual void Push(const Vector2& v, const String& fieldName = "") override;
    virtual void Push(const Vector3& v, const String& fieldName = "") override;

    virtual void BeginDictionary(const String& name = "") override;
    virtual void EndDictionary() override;

    virtual void BeginArray(const String& name = "") override;
    virtual void EndArray() override;

    virtual void Flush();


private:
    rapidjson::StringBuffer m_StringBuffer;
    rapidjson::PrettyWriter<rapidjson::StringBuffer> m_Writer;
};


} // end of namespace ToyUtility