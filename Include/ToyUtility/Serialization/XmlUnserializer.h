#pragma once

#include <sstream>

#include "rapidxml/rapidxml.hpp"

#include "ToyUtility/Prerequisites/PreDefine.h"
#include "ToyUtility/Container/List.h"
#include "ToyUtility/Serialization/Unserializer.h"


namespace ToyUtility
{


class XmlUnserializer : public Unserializer
{
public:
    XmlUnserializer(DataStream& stream);

    virtual ~XmlUnserializer() override;


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
    void _GotoNextNode();
    void _ConsumeFloat(const char* str, size_t strLen, size_t begin, size_t* end, float* value);
    void _ConsumeCharacter(const char* str, size_t strLen, size_t begin, size_t* end, const char& c);


private:
    char* m_Buffer;
    size_t m_BufferLength;
    rapidxml::xml_document<> m_Doc;

    rapidxml::xml_node<>* m_CurrNode;
};


} // end of namespace ToyUtility