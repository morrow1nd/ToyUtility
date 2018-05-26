#include "ToyUtility/FileSystem/FileSystem.h"

#include "ToyUtilityConfig.h"

#if (TOY_FILE_SYSTEM_WINDOWS)
# include "ToyUtility/FileSystem/windows/WindowsFileHandle.h"
#endif


namespace ToyUtility
{


UPtr<FileHandle> FileSystem::Open(const String & path)
{
#if (TOY_FILE_SYSTEM_WINDOWS)
    return UPtr<FileHandle>(new WindowsFileHandle(path));
#else
    return UPtr<FileHandle>();
#endif
}


} // end of namespace ToyUtility