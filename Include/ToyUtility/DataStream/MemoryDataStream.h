#pragma once

#include "ToyUtility/Prerequisites/PreDefine.h"
#include "ToyUtility/DataStream/DataStream.h"


namespace ToyUtility
{


class MemoryDataStream : public DataStream
{
public:
    /**
    * Allocates a new chunk of memory and wraps it in a stream.
    *
    * @param[in]	size		Size of the memory chunk in bytes.
    */
    MemoryDataStream(size_t size, uint16 readWriteFlag = READ | WRITE);

    /**
    * Wrap an existing memory chunk in a stream.
    *
    * @param[in] 	memory		Memory to wrap the data stream around.
    * @param[in]	size		Size of the memory chunk in bytes.
    * @param[in]	freeOnClose	Should the memory buffer be freed when the data stream goes out of scope.
    */
    MemoryDataStream(void* memory, size_t size, bool freeOnClose = true, uint16 readWriteFlag = READ | WRITE);

    ~MemoryDataStream();


public:
    /** Get a pointer to the start of the memory block this stream holds. */
    uint8* GetPtr() const { return mData; }
		
    /** Get a pointer to the current position in the memory block this stream holds. */
    uint8* GetCurrentPtr() const { return mPos; }
		
    /** @copydoc DataStream::read */
    uint32 Read(void* buf, uint32 count) override;

    /** @copydoc DataStream::write */
    uint32 Write(const void* buf, uint32 count) override;

    /** @copydoc DataStream::skip */
    void Skip(int32 count) override;
	
    /** @copydoc DataStream::seek */
    void Seek(uint32 pos) override;
		
    /** @copydoc DataStream::tell */
    uint32 Tell() const override;

    /** @copydoc DataStream::eof */
    bool Eof() const override;

    /** @copydoc DataStream::clone */
    //SPtr<DataStream> clone(bool copyData = true) const override;

    /** @copydoc DataStream::close */
    void Close() override;


protected:
    uint8* mData;
    uint8* mPos;
    uint8* mEnd;

    bool mFreeOnClose;
};


} // end of namespace ToyUtility