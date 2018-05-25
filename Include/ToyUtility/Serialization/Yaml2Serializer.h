#pragma once

#include "ToyUtility/Prerequisites/PreDefine.h"
#include "ToyUtility/Serialization/Serializer.h"

#include "yaml.h"


namespace ToyUtility
{

// Yaml 1.1(2rd Edition) Serializer
class Yaml2Serializer : public Serializer
{
public:
    Yaml2Serializer(DataStream& stream);

    virtual ~Yaml2Serializer() override;


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
    yaml_emitter_t m_YamlEmitter;
    yaml_event_t m_YamlEvent;
};


} // end of namespace ToyUtility