#pragma once

#include "ToyUtility/Prerequisites/PreDefine.h"
#include "ToyUtility/Container/List.h"
#include "ToyUtility/String/String.h"


namespace ToyUtility
{


class Base64
{
public:
    static void Encode(const uint8* binary, int binarySize, List<uint8>& result);

    static void Decode(const List<uint8>& base64String, List<uint8>& result);
    static void Decode(const String& base64String, List<uint8>& result);
};


} // end of namespace ToyUtility