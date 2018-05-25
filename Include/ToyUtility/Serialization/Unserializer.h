#pragma once

#include "ToyUtility/Prerequisites/PreDefine.h"
#include "ToyUtility/String/String.h"
#include "ToyUtility/Container/List.h"
#include "ToyUtility/DataStream/DataStream.h"


namespace ToyUtility
{


class Vector2;
class Vector3;


class Unserializer
{
public:
    Unserializer(DataStream& stream)
        :
        m_Stream(stream)
    {
    }

    virtual ~Unserializer() = default;


public:
    // Pop Operation
    virtual void Pop(const String& fieldName, uint8& v) = 0;
    virtual void Pop(const String& fieldName, int8& v) = 0;
    virtual void Pop(const String& fieldName, uint16& v) = 0;
    virtual void Pop(const String& fieldName, int16& v) = 0;
    virtual void Pop(const String& fieldName, uint32& v) = 0;
    virtual void Pop(const String& fieldName, int32& v) = 0;
    virtual void Pop(const String& fieldName, bool& v) = 0;
    virtual void Pop(const String& fieldName, float& v) = 0;
    virtual void Pop(const String& fieldName, double& v) = 0;
    virtual void Pop(const String& fieldName, String& v) = 0;
    virtual void Pop(const String& fieldName, Vector2& v) = 0;
    virtual void Pop(const String& fieldName, Vector3& v) = 0;

    virtual void BeginDictionary(const String& name = "") {}
    virtual void EndDictionary() {}

    virtual void BeginArray(const String& name = "") {}
    virtual void EndArray() {}


protected:
    DataStream & m_Stream;
};


} // end of namespace ToyUtility