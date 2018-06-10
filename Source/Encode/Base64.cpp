#include "ToyUtility/Encode/Base64.h"

#include "cppcodec/base64_default_url.hpp"


namespace ToyUtility
{


void Base64::Encode(const uint8* binary, int binarySize, List<uint8>& result)
{
    result.swap(cppcodec::base64_url::encode<List<uint8>>(binary, binarySize));
}

void Base64::Decode(const List<uint8>& base64String, List<uint8>& result)
{
    result.swap(cppcodec::base64_url::decode<List<uint8>, const List<uint8>>(base64String));
}

void Base64::Decode(const String & base64String, List<uint8>& result)
{
    result.swap(cppcodec::base64_url::decode<List<uint8>, const String>(base64String));
}


} // end of namespace ToyUtility