#include "ToyUtility/Serialization/TextSerializer.h"

#include "ToyUtility/Log/Logger.h"


namespace ToyUtility
{

//
//void TextSerializer::Push(SerializeDataType type, const String& fieldName, const void* ptr)
//{
//    if (ptr == nullptr)
//    {
//        TOY_RAW_LOG_ERR << "TextSerializer::Push Argument ptr is nullptr.\n";
//        return;
//    }
//
//    if (m_Stream.IsWriteable() == false)
//    {
//        TOY_RAW_LOG_ERR << "TextSerializer::Push m_Stream.IsWriteable() == false.\n";
//        return;
//    }
//
//    m_StrStream.clear();
//
//    switch (type)
//    {
//    case SerializeDataType::UINT8:
//        const uint8& v = *static_cast<const uint8*>(ptr);
//        m_StrStream << fieldName << ":" << v << "\n";
//        break;
//    case SerializeDataType::INT8:
//        const int8& v = *static_cast<const int8*>(ptr);
//        m_StrStream << fieldName << ":" << v << "\n";
//        break;
//    case SerializeDataType::UINT16:
//        const uint16& v = *static_cast<const uint16*>(ptr);
//        m_StrStream << fieldName << ":" << v << "\n";
//        break;
//    case SerializeDataType::INT16:
//        const int16& v = *static_cast<const int16*>(ptr);
//        m_StrStream << fieldName << ":" << v << "\n";
//        break;
//    case SerializeDataType::UINT32:
//        const uint32& v = *static_cast<const uint32*>(ptr);
//        m_StrStream << fieldName << ":" << v << "\n";
//        break;
//    case SerializeDataType::INT32:
//        const int32& v = *static_cast<const int32*>(ptr);
//        m_StrStream << fieldName << ":" << v << "\n";
//        break;
//    case SerializeDataType::FLOAT:
//        const float& v = *static_cast<const float*>(ptr);
//        m_StrStream << fieldName << ":" << v << "\n";
//        break;
//    case SerializeDataType::DOUBLE:
//        const double& v = *static_cast<const double*>(ptr);
//        m_StrStream << fieldName << ":" << v << "\n";
//        break;
//    case SerializeDataType::BOOL:
//        auto& b = *static_cast<const bool*>(ptr);
//        m_StrStream << fieldName << ":" << (b ? "true" : "false") << "\n";
//        break;
//    case SerializeDataType::STRING:
//        const String& v = *static_cast<const String*>(ptr);
//        m_StrStream << fieldName << ":" << v << "\n"; // TODOH: don't support a string contains a \n.
//        break;
//    default:
//        TOY_RAW_LOG_ERR << "TextSerializer::Push Came to default.\n";
//        break;
//    }
//    m_Stream.WriteString(m_StrStream.str());
//}
//
//void TextSerializer::Pop(SerializeDataType type, const String& fieldName, void* ptr)
//{
//    if (ptr == nullptr)
//    {
//        TOY_RAW_LOG_ERR << "TextSerializer::Pop Argument ptr is nullptr.\n";
//        return;
//    }
//
//    if (m_Stream.IsReadable() == false)
//    {
//        TOY_RAW_LOG_ERR << "TextSerializer::Pop m_Stream.IsReadable() == false.\n";
//        return;
//    }
//
//    // TODO: not finished
//}
//

} // end of namespace ToyUtility