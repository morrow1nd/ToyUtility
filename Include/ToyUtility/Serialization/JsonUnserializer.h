#pragma once

#include <sstream>

#include "rapidjson/reader.h"

#include "ToyUtility/Prerequisites/PreDefine.h"
#include "ToyUtility/Serialization/Unserializer.h"


// rapidjson SAX api usage:
// http://rapidjson.org/zh-cn/md_doc_sax_8zh-cn.html

namespace ToyUtility
{


class JsonUnserializer : public Unserializer
{
public:
    JsonUnserializer(DataStream& stream);

    virtual ~JsonUnserializer() override;


public:
    // Pop Operation
    virtual void Pop(const String& fieldName, uint8& v) override;
    virtual void Pop(const String& fieldName, int8& v) override;
    virtual void Pop(const String& fieldName, uint16& v) override;
    virtual void Pop(const String& fieldName, int16& v) override;
    virtual void Pop(const String& fieldName, uint32& v) override;
    virtual void Pop(const String& fieldName, int32& v) override;
    virtual void Pop(const String& fieldName, bool& v) override;
    virtual void Pop(const String& fieldName, float& v) override;
    virtual void Pop(const String& fieldName, double& v) override;
    virtual void Pop(const String& fieldName, String& v) override;
    virtual void Pop(const String& fieldName, Vector2& v) override;
    virtual void Pop(const String& fieldName, Vector3& v) override;

    virtual void BeginDictionary(const String& name = "") override;
    virtual void EndDictionary() override;

    virtual void BeginArray(const String& name = "") override;
    virtual void EndArray() override;


private:
    ToyUtility::String m_JsonString;

    struct JsonEvent;
    ToyUtility::List<JsonEvent> m_JsonEvents;
    int m_Index;

    rapidjson::Reader m_Reader;
    rapidjson::StringStream m_StringStream;
    ToyUtility::List<String> m_StringCaches;


private:
    enum class JsonEventType
    {
        Null,
        Bool,
        Int,
        UInt,
        Int64,
        UInt64,
        Double,
        String,
        StartObject,
        EndObject,
        Key,
        StartArray,
        EndArray,
    };
    struct JsonEvent
    {
        JsonEventType Type;

        union
        {
            uint32 _uint;
            int32 _int;
            int64 _int_64;
            uint64 _uint_64;
            double _double;
            bool _bool;
        } Data;

        explicit JsonEvent(uint32 value) : Type(JsonEventType::UInt)
        {
            Data._uint = value;
        }
        explicit JsonEvent(int32 value) : Type(JsonEventType::Int)
        {
            Data._int = value;
        }
        explicit JsonEvent(int64 value) : Type(JsonEventType::Int64)
        {
            Data._int_64 = value;
        }
        explicit JsonEvent(uint64 value) : Type(JsonEventType::UInt64)
        {
            Data._uint_64 = value;
        }
        explicit JsonEvent(double value) : Type(JsonEventType::Double)
        {
            Data._double = value;
        }
        explicit JsonEvent(bool value) : Type(JsonEventType::Bool)
        {
            Data._bool = value;
        }
        explicit JsonEvent(JsonEventType type) : Type(type)
        {
        }
        explicit JsonEvent(JsonEventType type, uint32 size) : Type(type)
        {
            Data._uint = size;
        }
    };

    struct JsonEventHandler : public rapidjson::BaseReaderHandler<rapidjson::UTF8<>, JsonEventHandler>
    {
        bool Null()
        {
            JsonEvents.push_back(JsonEvent(JsonEventType::Null));
            return true;
        }
        bool Bool(bool b)
        {
            JsonEvents.push_back(JsonEvent(b));
            return true;
        }
        bool Int(int i)
        {
            JsonEvents.push_back(JsonEvent(i));
            return true;
        }
        bool Uint(unsigned u)
        {
            JsonEvents.push_back(JsonEvent(u));
            return true;
        }
        bool Int64(int64_t i)
        {
            JsonEvents.push_back(JsonEvent(i));
            return true;
        }
        bool Uint64(uint64_t u)
        {
            JsonEvents.push_back(JsonEvent(u));
            return true;
        }
        bool Double(double d)
        {
            JsonEvents.push_back(JsonEvent(d));
            return true;
        }
        bool String(const char* str, rapidjson::SizeType length, bool copy)
        {
            StringCaches.push_back(ToyUtility::String(str, length));
            JsonEvents.push_back(JsonEvent(JsonEventType::String, StringCaches.size() - 1));
            return true;
        }
        bool StartObject()
        {
            JsonEvents.push_back(JsonEvent(JsonEventType::StartObject));
            return true;
        }
        bool Key(const char* str, rapidjson::SizeType length, bool copy)
        {
            StringCaches.push_back(ToyUtility::String(str, length));
            JsonEvents.push_back(JsonEvent(JsonEventType::Key, StringCaches.size() - 1));
            return true;
        }
        bool EndObject(rapidjson::SizeType memberCount)
        {
            JsonEvents.push_back(JsonEvent(JsonEventType::EndObject, memberCount));
            return true;
        }
        bool StartArray()
        {
            JsonEvents.push_back(JsonEvent(JsonEventType::StartArray));
            return true;
        }
        bool EndArray(rapidjson::SizeType elementCount)
        {
            JsonEvents.push_back(JsonEvent(JsonEventType::EndArray));
            return true;
        }

        ToyUtility::List<JsonEvent> JsonEvents;
        ToyUtility::List<ToyUtility::String> StringCaches;
    };
};


} // end of namespace ToyUtility