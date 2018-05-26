#pragma once

#include "ToyUtility/Prerequisites/PreDefine.h"
#include "ToyUtility/String/String.h"
#include "ToyUtility/Container/List.h"
#include "ToyUtility/Memory/SmartPtr.h"
#include "ToyUtility/DesignPattern/IUncopyable.h"


namespace ToyUtility
{


enum class FileHandleType
{
    Unknown,

    File,
    Directory,
};


class FileHandle : private IUncopyable
{
public:
    FileHandle(const String& path) {}

    //// Copy constructor
    //FileHandle(const FileHandle& fileHandle);

    //// Move constructor
    //FileHandle(FileHandle&& fileHandle);

    virtual ~FileHandle() = default;

    //// Copy operator
    //FileHandle& operator=(const FileHandle& rhs);

    //// Move operator
    //FileHandle& operator=(FileHandle&& rhs);

    // Get path to file or directory
    virtual String Path() const = 0;

    // Get file name or directory name
    virtual String FileName() const = 0;

    // Get parent directory path
    virtual String ParentDirectory() const = 0;

    // Check if file or directory exists
    virtual bool Exist() const = 0;

    // Check is a file or directory
    virtual FileHandleType HandleType() const = 0;

    // Check if item is a symbolic link
    virtual bool IsSymbolicLink() const = 0;

    // List all items in directory
    virtual List<String> ListFiles() const = 0;

    // ... move way to traverse

    // File size
    virtual uint32 Size() const = 0;

    // Time of last access, return a time stamp
    virtual uint32 AccessTime() const = 0;

    // Time of last modification
    virtual uint32 ModificationTime() const = 0;

    // ID of owning user
    virtual uint32 UserId() const = 0;

    // Set owning user
    virtual void SetUserId(uint32 uid) = 0;

    // ID of owning group
    virtual uint32 GroupId() const = 0;

    // Set owning group
    virtual void SetGroupId(uint32 gid) = 0;

    // Get permissions
    virtual uint64 Permissions() const = 0;

    // Set permissions
    virtual void SetPermissions(uint64 permissions) = 0;

    // Create directory, return ture if successful
    virtual bool CreateDirectory() = 0;

    // Remove directory recursively or file
    virtual bool Remove() = 0;

    // Copy directory recursively if this handle is a directory.
    // @dstDir points to the actual directory that is to be created, not it's parent.
    // 
    // Copy file if this handle is a file.
    // @dstDir Destination file or directory
    virtual void Copy(FileHandle& dest) = 0;

    // @ref @Copy
    virtual bool Move(FileHandle& dest) = 0;

    // Create hard link
    // @dest: Destination file or directory
    // @return: ture if successful
    virtual bool CreateHardLink(FileHandle& dest) = 0;

    // Create symbolic link
    virtual bool CreateSymbolicLink(FileHandle& dest) = 0;

    // Rename file or directory
    virtual bool Rename(const String& newName) = 0;

    // Create input stream to read from the file
    // The created stream object has to be destroyed by the caller.
    // @return nullptr if error happens
    virtual UPtr<std::istream> CreateInputStream(std::ios_base::openmode mode = std::ios_base::in) const = 0;

    // Create output stream to write to the file
    // The created stream object has to be destroyed by the caller.
    // @return nullptr if error happens
    virtual UPtr<std::ostream> CreateOutputStream(std::ios_base::openmode mode = std::ios_base::out) = 0;

    // Read file to string
    virtual std::string ReadFile() const = 0;

    // Write string to file
    // @return: true if successful
    virtual bool WriteFile(const std::string& str) = 0;


public:
    // Reread file info
    virtual void _UpdateFileInfo() = 0;
};


} // end of namespace ToyUtility