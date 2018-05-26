#pragma once

#include "ToyUtility/Prerequisites/PreDefine.h"
#include "ToyUtility/FileSystem/FileHandle.h"
#include "ToyUtility/Memory/SmartPtr.h"
#include "ToyUtility/String/String.h"


namespace ToyUtility
{


class FileSystem
{
public:
    static UPtr<FileHandle> Open(const String& path);
};


} // end of namespace ToyUtility