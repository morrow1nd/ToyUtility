#include "ToyUtility/FileSystem/windows/WindowsFileHandle.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <iterator>
#include <array>
#include <Windows.h>


namespace ToyUtility
{


WindowsFileHandle::WindowsFileHandle(const String & path)
    :
    FileHandle(path),
    m_Path(path),
    m_FilePath(path),
    m_FileInfo(nullptr)
{
}

WindowsFileHandle::~WindowsFileHandle()
{
    if (m_FileInfo)
    {
        delete (WIN32_FILE_ATTRIBUTE_DATA *)m_FileInfo;
        m_FileInfo = nullptr;
    }
}

String WindowsFileHandle::Path() const
{
    return m_Path;
}

String WindowsFileHandle::FileName() const
{
    return m_FilePath.FileName();
}

String WindowsFileHandle::ParentDirectory() const
{
    return m_FilePath.Resolve("..").Resolved();
}

bool WindowsFileHandle::Exist() const
{
    _ReadFileInfo();

    return m_FileInfo != nullptr;
}

FileHandleType WindowsFileHandle::HandleType() const
{
    _ReadFileInfo();

    if (m_FileInfo)
    {
        if ((((WIN32_FILE_ATTRIBUTE_DATA *)m_FileInfo)->dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0)
        {
            return FileHandleType::Directory;
        }
        else
        {
            return FileHandleType::File;
        }
    }

    return FileHandleType::Unknown;
}

bool WindowsFileHandle::IsSymbolicLink() const
{
    _ReadFileInfo();

    if (m_FileInfo)
    {
        return (((WIN32_FILE_ATTRIBUTE_DATA *)m_FileInfo)->dwFileAttributes & FILE_ATTRIBUTE_REPARSE_POINT) != 0;
    }

    return false;
}

List<String> WindowsFileHandle::ListFiles() const
{
    std::vector<std::string> entries;

    // Open directory
    WIN32_FIND_DATA findData;
    std::string query = m_FilePath.FullPath() + "/*";
    HANDLE findHandle = FindFirstFileA(query.c_str(), &findData);

    if (findHandle == INVALID_HANDLE_VALUE)
    {
        return entries;
    }

    // Read directory entries
    do
    {
        // Get name
        std::string name = findData.cFileName;

        // Ignore . and ..
        if (name != ".." && name != ".")
        {
            entries.push_back(name);
        }
    } while (FindNextFile(findHandle, &findData));

    // Close directory
    FindClose(findHandle);

    // Return directory entries
    return entries;
}

uint32 WindowsFileHandle::Size() const
{
    _ReadFileInfo();

    if (m_FileInfo)
    {
        // [TODOM] Use 64bit numbers
        auto fileSizeH = ((WIN32_FILE_ATTRIBUTE_DATA *)m_FileInfo)->nFileSizeHigh;
        auto fileSizeL = ((WIN32_FILE_ATTRIBUTE_DATA *)m_FileInfo)->nFileSizeLow;
        return static_cast<unsigned int>(static_cast<__int64>(fileSizeH) << 32 | fileSizeL);
    }

    return 0;
}

uint32 WindowsFileHandle::AccessTime() const
{
    _ReadFileInfo();

    if (m_FileInfo)
    {
        // [TODO] Use 64bit numbers
        auto time = ((WIN32_FILE_ATTRIBUTE_DATA *)m_FileInfo)->ftLastAccessTime;
        return static_cast<unsigned int>(static_cast<__int64>(time.dwHighDateTime) << 32 | time.dwLowDateTime);
    }

    return 0;
}

uint32 WindowsFileHandle::ModificationTime() const
{
    _ReadFileInfo();

    if (m_FileInfo)
    {
        // [TODO] Use 64bit numbers
        auto time = ((WIN32_FILE_ATTRIBUTE_DATA *)m_FileInfo)->ftLastWriteTime;
        return static_cast<unsigned int>(static_cast<__int64>(time.dwHighDateTime) << 32 | time.dwLowDateTime);
    }

    return 0;
}

uint32 WindowsFileHandle::UserId() const
{
    return 0;
}

void WindowsFileHandle::SetUserId(uint32 uid)
{
}

uint32 WindowsFileHandle::GroupId() const
{
    return 0;
}

void WindowsFileHandle::SetGroupId(uint32 gid)
{
}

uint64 WindowsFileHandle::Permissions() const
{
    return 0;
}

void WindowsFileHandle::SetPermissions(uint64 permissions)
{
}

#ifdef CreateDirectory
# undef CreateDirectory
#endif

bool WindowsFileHandle::CreateDirectory()
{
    // Check directory
    if (Exist()) return false;

    // Create directory
    if (!CreateDirectoryA(m_Path.c_str(), nullptr))
    {
        return false;
    }

    // Done
    _UpdateFileInfo();
    return true;
}

bool WindowsFileHandle::Remove()
{
    auto handleType = HandleType();

    if (handleType == FileHandleType::File)
    {
        return _RemoveFile();
    }
    else if (handleType == FileHandleType::Directory)
    {
        auto contents = ListFiles();
        for each(auto item in contents)
        {
            WindowsFileHandle fh(m_FilePath.Resolve(item).FullPath());
            fh.Remove();
        }

        return _RemoveEmptyDirectory();
    }
    else
    {
        return false;
    }
}

void WindowsFileHandle::Copy(FileHandle& dest)
{
    auto handleType = HandleType();

    if (handleType == FileHandleType::File)
    {
        _CopyFile(dest);
        dest._UpdateFileInfo();
    }
    else if (handleType == FileHandleType::Directory)
    {
        // Check destination directory and try to create it if necessary
        if (dest.HandleType() != FileHandleType::Directory)
        {
            dest.CreateDirectory();

            if (dest.HandleType() != FileHandleType::Directory)
            {
                // Error
                return;
            }
        }

        // Copy all entries
        auto contents = ListFiles();
        for each(auto item in contents)
        {
            WindowsFileHandle src(m_FilePath.Resolve(item).FullPath());
            WindowsFileHandle des(dest.Path() + "/" + item);

            src.Copy(des);
        }

        dest._UpdateFileInfo();
    }
}

bool WindowsFileHandle::Move(FileHandle& dest)
{
    Copy(dest);
    Remove();
}

#ifdef CreateHardLink
# undef CreateHardLink
#endif

#ifdef CreateSymbolicLink
# undef CreateSymbolicLink
#endif

bool WindowsFileHandle::CreateHardLink(FileHandle & dest)
{
    // Check source file
    if (HandleType() != FileHandleType::File)
        return false;

    // Get source and target filenames
    std::string src = m_Path;
    std::string dst = dest.Path();

    if (dest.HandleType() == FileHandleType::Directory)
    {
        std::string filename = m_FilePath.FileName();
        dst = FilePath(dest.Path()).Resolve(filename).FullPath();
    }

    // Copy file
    if (!CreateHardLinkA(src.c_str(), dst.c_str(), 0))
    {
        // Error!
        return false;
    }

    // Done
    dest._UpdateFileInfo();
    return true;
}

bool WindowsFileHandle::CreateSymbolicLink(FileHandle & dest)
{
    // Check source file
    if (HandleType() != FileHandleType::File)
        return false;

    // Get source and target filenames
    std::string src = m_Path;
    std::string dst = dest.Path();

    if (dest.HandleType() == FileHandleType::Directory)
    {
        std::string filename = m_FilePath.FileName();
        dst = FilePath(dest.Path()).Resolve(filename).FullPath();
    }

    // Copy file
    if (!CreateSymbolicLinkA(src.c_str(), dst.c_str(), 0))
    {
        // Error!
        return false;
    }

    // Done
    dest._UpdateFileInfo();
    return true;
}

bool WindowsFileHandle::Rename(const String & newName)
{
    // Check file
    if (!Exist()) return false;

    // Compose new file path
    std::string path = m_FilePath.DirectoryPath() + "/" + newName;

    // Rename
    if (!MoveFileA(m_Path.c_str(), path.c_str()))
    {
        // Error!
        return false;
    }

    // Update path
    m_Path = path;
    m_FilePath.SetPath(std::move(path));
    _UpdateFileInfo();

    // Done
    return true;
}

UPtr<std::istream> WindowsFileHandle::CreateInputStream(std::ios_base::openmode mode = std::ios_base::in) const
{
    return std::unique_ptr<std::istream>(new std::ifstream(m_Path, mode));
}

UPtr<std::ostream> WindowsFileHandle::CreateOutputStream(std::ios_base::openmode mode = std::ios_base::out)
{
    return std::unique_ptr<std::ostream>(new std::ofstream(m_Path, mode));
}

std::string WindowsFileHandle::ReadFile() const
{
    if (HandleType() == FileHandleType::File)
    {
        auto inputStream = CreateInputStream();
        if(!inputStream)
            return "";

        std::stringstream buffer;
        buffer << inputStream->rdbuf();

        return buffer.str();
    }
    else
    {
        return "";
    }
}

bool WindowsFileHandle::WriteFile(const std::string & str)
{
    // Open output stream
    auto outputStream = CreateOutputStream();
    if (!outputStream)
        return false;

    // Write content to file
    (*outputStream) << str;

    // Done
    return true;
}

void WindowsFileHandle::_ReadFileInfo() const
{
    // Check if file info has already been read
    if (m_FileInfo) return;

    // Create file information structure
    m_FileInfo = (void *)new WIN32_FILE_ATTRIBUTE_DATA;

    // Get file info
    if (!GetFileAttributesExA(m_Path.c_str(), GetFileExInfoStandard, (WIN32_FILE_ATTRIBUTE_DATA*)m_FileInfo))
    {
        // Error!
        delete (WIN32_FILE_ATTRIBUTE_DATA *)m_FileInfo;
        m_FileInfo = nullptr;
    }
}

bool WindowsFileHandle::_RemoveEmptyDirectory()
{
    // Remove directory
    if (!RemoveDirectoryA(m_Path.c_str()))
    {
        return false;
    }

    // Done
    _UpdateFileInfo();
    return true;
}

bool WindowsFileHandle::_RemoveFile()
{
    // Delete file
    if (!DeleteFileA(m_Path.c_str()))
    {
        return false;
    }

    // Done
    _UpdateFileInfo();
    return true;
}

bool WindowsFileHandle::_CopyFile(FileHandle & dest)
{
    // Get source and target filenames
    String src = m_Path;
    String dst = dest.Path();

    if (dest.HandleType() == FileHandleType::Directory)
    {
        String fileName = m_FilePath.FileName();
        dst += "/" + fileName;
    }

    // Copy file
    if (!CopyFileA(src.c_str(), dst.c_str(), FALSE))
    {
        // Error!
        return false;
    }

    // Done
    dest._UpdateFileInfo();
    _UpdateFileInfo();
    return true;
}

void WindowsFileHandle::_UpdateFileInfo()
{
    // Reset file information
    if (m_FileInfo)
    {
        delete (WIN32_FILE_ATTRIBUTE_DATA *)m_FileInfo;
        m_FileInfo = nullptr;
    }

    _ReadFileInfo();
}


} // end of namespace ToyUtility