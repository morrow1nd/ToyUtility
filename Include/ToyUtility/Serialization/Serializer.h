#pragma once

#include "ToyUtility/Prerequisites/PreDefine.h"
#include "ToyUtility/String/String.h"
#include "ToyUtility/Container/List.h"
#include "ToyUtility/DataStream/DataStream.h"


namespace ToyUtility
{


class Vector2;
class Vector3;
class Serializer;


//class SerializerDictionaryBlock
//{
//public:
//    SerializerDictionaryBlock(Serializer* serializer)
//        : m_Serializer(serializer)
//    {}
//
//    ~SerializerDictionaryBlock();
//
//
//private:
//    Serializer* m_Serializer;
//};
//
//class SerializerArrayBlock
//{
//public:
//    SerializerArrayBlock(Serializer* serializer)
//        : m_Serializer(serializer)
//    {
//    }
//
//    ~SerializerArrayBlock();
//
//
//private:
//    Serializer * m_Serializer;
//};


class Serializer
{
public:
    Serializer(DataStream& stream)
        :
        m_Stream(stream)
    {}

    virtual ~Serializer() = default;


public:
    // Push Operation
    virtual void Push(const uint8 v, const String& fieldName = "") = 0;
    virtual void Push(const int8 v, const String& fieldName = "") = 0;
    virtual void Push(const uint16 v, const String& fieldName = "") = 0;
    virtual void Push(const int16 v, const String& fieldName = "") = 0;
    virtual void Push(const uint32 v, const String& fieldName = "") = 0;
    virtual void Push(const int32 v, const String& fieldName = "") = 0;
    virtual void Push(const bool v, const String& fieldName = "") = 0;
    virtual void Push(const float v, const String& fieldName = "") = 0;
    virtual void Push(const double v, const String& fieldName = "") = 0;
    //virtual void Push(const List<uint8>& v, const String& fieldName = "") = 0;
    //virtual void Push(const List<int8>& v, const String& fieldName = "") = 0;
    //virtual void Push(const List<uint16>& v, const String& fieldName = "") = 0;
    //virtual void Push(const List<int16>& v, const String& fieldName = "") = 0;
    //virtual void Push(const List<uint32>& v, const String& fieldName = "") = 0;
    //virtual void Push(const List<int32>& v, const String& fieldName = "") = 0;
    //virtual void Push(const List<bool>& v, const String& fieldName = "") = 0;
    //virtual void Push(const List<float>& v, const String& fieldName = "") = 0;
    //virtual void Push(const List<double>& v, const String& fieldName = "") = 0;
    virtual void Push(const String& v, const String& fieldName = "") = 0;
    virtual void Push(const Vector2& v, const String& fieldName = "") = 0;
    virtual void Push(const Vector3& v, const String& fieldName = "") = 0;

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
    
    // Focus write all data to data stream.
    virtual void Flush() = 0;


protected:
    DataStream& m_Stream;
};


} // end of namespace ToyUtility