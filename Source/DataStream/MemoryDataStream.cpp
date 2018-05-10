#include "ToyUtility/DataStream/MemoryDataStream.h"

#include <istream>
#include <sstream>
#include "ToyUtility/Log/Logger.h"


namespace ToyUtility
{


MemoryDataStream::MemoryDataStream(size_t size)
    : DataStream(READ | WRITE), mData(nullptr), mFreeOnClose(true)
{
    mData = mPos = (uint8*)new uint8[(UINT32)size];
    m_Size = size;
    mEnd = mData + m_Size;

    assert(mEnd >= mPos);
}

MemoryDataStream::MemoryDataStream(void* memory, size_t inSize, bool freeOnClose)
    : DataStream(READ | WRITE), mData(nullptr), mFreeOnClose(freeOnClose)
{
    mData = mPos = static_cast<UINT8*>(memory);
    m_Size = inSize;
    mEnd = mData + m_Size;

    assert(mEnd >= mPos);
}

MemoryDataStream::~MemoryDataStream()
{
    Close();
}

size_t MemoryDataStream::Read(void* buf, size_t count)
{
    size_t cnt = count;

    if (mPos + cnt > mEnd)
        cnt = mEnd - mPos;
    if (cnt == 0)
        return 0;

    assert(cnt <= count);

    memcpy(buf, mPos, cnt);
    mPos += cnt;

    return cnt;
}

size_t MemoryDataStream::Write(const void* buf, size_t count)
{
    size_t written = 0;
    if (IsWriteable())
    {
        written = count;

        if (mPos + written > mEnd)
            written = mEnd - mPos;
        if (written == 0)
            return 0;

        memcpy(mPos, buf, written);
        mPos += written;
    }

    return written;
}

void MemoryDataStream::Skip(int32 count)
{
    size_t newpos = (size_t)((mPos - mData) + count);
    assert(mData + newpos <= mEnd);

    mPos = mData + newpos;
}

void MemoryDataStream::Seek(size_t pos)
{
    assert(mData + pos <= mEnd);
    mPos = mData + pos;
}

size_t MemoryDataStream::Tell() const
{
    return mPos - mData;
}

bool MemoryDataStream::Eof() const
{
    return mPos >= mEnd;
}

//SPtr<DataStream> MemoryDataStream::clone(bool copyData) const
//{
//    if (!copyData)
//        return bs_shared_ptr_new<MemoryDataStream>(mData, mSize, false);
//
//    return bs_shared_ptr_new<MemoryDataStream>(*this);
//}

void MemoryDataStream::Close()
{
    if (mData != nullptr)
    {
        if (mFreeOnClose)
            delete[] mData;

        mData = nullptr;
    }
}


} // end of namespace ToyUtility