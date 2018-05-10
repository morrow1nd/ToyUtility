#pragma once

#include "ToyUtility/Prerequisites/PreDefine.h"
#include "ToyUtility/DataStream/DataStream.h"
#include "ToyUtility/Memory/SmartPtr.h"
#include "ToyUtility/Log/Logger.h"


namespace ToyUtility
{


/** Data stream for handling data from standard streams. */
class FileDataStream : public DataStream
{
public:
    /**
    * Construct a file stream.
    *
    * @param[in]	filePath	Path of the file to open.
    * @param[in]	accessMode	Determines should the file be opened in read, write or read/write mode.
    * @param[in]	freeOnClose	Determines should the internal stream be freed once the data stream is closed or goes
    *							out of scope.
    */
    FileDataStream(const String& filePath, AccessMode accessMode = READ, bool freeOnClose = true);

    ~FileDataStream();

    /** @copydoc DataStream::read */
    size_t Read(void* buf, size_t count) override;

    /** @copydoc DataStream::write */
    size_t Write(const void* buf, size_t count) override;

    /** @copydoc DataStream::skip */
    void Skip(int count) override;

    /** @copydoc DataStream::seek */
    void Seek(size_t pos) override;

    /** @copydoc DataStream::tell */
    size_t Tell() const override;

    /** @copydoc DataStream::eof */
    bool Eof() const override;

    /** @copydoc DataStream::clone */
    // SPtr<DataStream> clone(bool copyData = true) const override;

    /** @copydoc DataStream::close */
    void Close() override;

    /** Returns the path of the file opened by the stream. */
    const String& GetFilePath() const
    {
        return mPath;
    }

protected:
    String mPath;
    SPtr<std::istream> mInStream;
    SPtr<std::ifstream> mFStreamRO;
    SPtr<std::fstream> mFStream;
    bool mFreeOnClose;
};


} // end of namespace ToyUtility