#pragma once

#include "ToyUtility/Prerequisites/PreDefine.h"
#include "ToyUtility/Serialization/Unserializer.h"


namespace ToyUtility
{


class Yaml2Unserializer : public Unserializer
{
public:
    Yaml2Unserializer(DataStream& stream);

    virtual ~Yaml2Unserializer() override;


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
};


} // end of namespace ToyUtility