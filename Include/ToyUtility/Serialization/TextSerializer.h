#pragma once

#include <sstream>
#include "ToyUtility/Prerequisites/PreDefine.h"
#include "ToyUtility/Serialization/Serializer.h"


namespace ToyUtility
{


class TextSerializer : public Serializer
{
public:
    //virtual void Push(SerializeDataType type, const String& fieldName, const void* ptr) override;
    //virtual void Pop(SerializeDataType type, const String& fieldName, void* ptr) override;


private:
    std::stringstream m_StrStream; // Use it to connect strings
};


} // end of namespace ToyUtility