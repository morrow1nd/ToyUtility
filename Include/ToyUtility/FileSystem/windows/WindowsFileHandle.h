#pragma once

#include "ToyUtility/Prerequisites/PreDefine.h"
#include "ToyUtility/FileSystem/FileHandle.h"
#include "ToyUtility/FileSystem/FilePath.h"


namespace ToyUtility
{


class WindowsFileHandle : public FileHandle
{
public:
    WindowsFileHandle(const String& path);
    ~WindowsFileHandle();

    // Inherited via FileHandle
    virtual String Path() const override;
    virtual String FileName() const override;
    virtual String ParentDirectory() const override;
    virtual bool Exist() const override;
    virtual FileHandleType HandleType() const override;
    virtual bool IsSymbolicLink() const override;
    virtual List<String> ListFiles() const override;
    virtual uint32 Size() const override;
    virtual uint32 AccessTime() const override;
    virtual uint32 ModificationTime() const override;
    virtual uint32 UserId() const override;
    virtual void SetUserId(uint32 uid) override;
    virtual uint32 GroupId() const override;
    virtual void SetGroupId(uint32 gid) override;
    virtual uint64 Permissions() const override;
    virtual void SetPermissions(uint64 permissions) override;
    virtual bool CreateDirectory() override;
    virtual bool Remove() override;
    virtual void Copy(FileHandle & dest) override;
    virtual bool Move(FileHandle & dest) override;
    virtual bool CreateHardLink(FileHandle & dest) override;
    virtual bool CreateSymbolicLink(FileHandle & dest) override;
    virtual bool Rename(const String & newName) override;
    virtual UPtr<std::istream> CreateInputStream(std::ios_base::openmode mode = std::ios_base::in) const override;
    virtual UPtr<std::ostream> CreateOutputStream(std::ios_base::openmode mode = std::ios_base::out) override;
    virtual std::string ReadFile() const override;
    virtual bool WriteFile(const std::string & str) override;


protected:
    void _ReadFileInfo() const;

    // Remove empty directory
    bool _RemoveEmptyDirectory();

    // Remove file
    bool _RemoveFile();

    // Copy file
    bool _CopyFile(FileHandle& dest);


private:
    // Inherited via FileHandle
    virtual void _UpdateFileInfo() override;


private:
    String m_Path;
    
    mutable FilePath m_FilePath;
    mutable void* m_FileInfo;
};


} // end of namespace ToyUtility