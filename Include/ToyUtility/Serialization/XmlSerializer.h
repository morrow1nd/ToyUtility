#pragma once

#include <sstream>

#include "rapidxml/rapidxml.hpp"

#include "ToyUtility/Prerequisites/PreDefine.h"
#include "ToyUtility/Container/List.h"
#include "ToyUtility/Serialization/Serializer.h"


namespace ToyUtility
{


class XmlSerializer : public Serializer
{
public:
    XmlSerializer(DataStream& stream);

    virtual ~XmlSerializer() override;


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
    rapidxml::xml_node<>* _CreateNode(const String& nodeName, const String& value = "");
    void _AttachNode(const String& nodeName, const String& value = "");


private:
    std::stringstream m_TemStrStream;


private:
    rapidxml::xml_document<> m_Doc;
    List<rapidxml::xml_node<>*> m_NodesStack;
};


} // end of namespace ToyUtility