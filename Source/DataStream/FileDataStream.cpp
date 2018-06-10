#include "ToyUtility/DataStream/FileDataStream.h"

#include <istream>
#include <sstream>
#include <fstream>
#include "ToyUtility/Log/Logger.h"


namespace ToyUtility
{


FileDataStream::FileDataStream(const String& path, AccessMode accessMode, bool freeOnClose)
    : DataStream(accessMode), mPath(path), mFreeOnClose(freeOnClose)
{
    // Always open in binary mode
    // Also, always include reading
    std::ios::openmode mode = std::ios::binary;

    if ((accessMode & READ) != 0)
        mode |= std::ios::in;

    if (((accessMode & WRITE) != 0))
    {
        mode |= std::ios::out;
        mFStream = SPtr<std::fstream>(new std::fstream());
        mFStream->open(path, mode);
        mInStream = mFStream;
    }
    else
    {
        mFStreamRO = SPtr<std::ifstream>(new std::ifstream());
        mFStreamRO->open(path, mode);
        mInStream = mFStreamRO;
    }

    // Should check ensure open succeeded, in case fail for some reason.
    if (mInStream->fail())
    {
        TOY_RAW_LOG_ERR << "Cannot open file: " + path + "\n";
        return;
    }

    mInStream->seekg(0, std::ios_base::end);
    m_Size = (size_t)mInStream->tellg();
    mInStream->seekg(0, std::ios_base::beg);
}

FileDataStream::FileDataStream(UPtr<std::istream> stream, AccessMode accessMode, bool freeOnClose)
    :
    DataStream(accessMode),
    mFreeOnClose(freeOnClose)
{
    // TODOM
    if (IsWriteable())
    {
        TOY_RAW_LOG << "Error: can't write" << std::endl;
    }

    mInStream.reset(stream.release());
}

FileDataStream::~FileDataStream()
{
    Close();
}

uint32 FileDataStream::Read(void* buf, uint32 count)
{
    mInStream->read(static_cast<char*>(buf), static_cast<std::streamsize>(count));

    return (uint32)mInStream->gcount();
}

uint32 FileDataStream::Write(const void* buf, uint32 count)
{
    size_t written = 0;
    if (IsWriteable() && mFStream)
    {
        mFStream->write(static_cast<const char*>(buf), static_cast<std::streamsize>(count));
        written = count;
    }

    return written;
}
void FileDataStream::Skip(int32 count)
{
    mInStream->clear(); // Clear fail status in case eof was set
    mInStream->seekg(static_cast<std::ifstream::pos_type>(count), std::ios::cur);
}

void FileDataStream::Seek(uint32 pos)
{
    mInStream->clear(); // Clear fail status in case eof was set
    mInStream->seekg(static_cast<std::streamoff>(pos), std::ios::beg);
}

uint32 FileDataStream::Tell() const
{
    mInStream->clear(); // Clear fail status in case eof was set

    return (uint32)mInStream->tellg();
}

bool FileDataStream::Eof() const
{
    return mInStream->eof();
}

//SPtr<DataStream> FileDataStream::clone(bool copyData) const
//{
//    return bs_shared_ptr_new<FileDataStream>(mPath, (AccessMode)getAccessMode(), true);
//}

void FileDataStream::Close()
{
    if (mInStream)
    {
        if (mFStreamRO)
            mFStreamRO->close();

        if (mFStream)
        {
            mFStream->flush();
            mFStream->close();
        }

        if (mFreeOnClose)
        {
            mInStream = nullptr;
            mFStreamRO = nullptr;
            mFStream = nullptr;
        }
    }
}


} // end of namespace ToyUtility