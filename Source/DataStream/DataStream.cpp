#include "ToyUtility/DataStream/DataStream.h"

#include <istream>
#include <sstream>
#include "ToyUtility/Log/Logger.h"


namespace ToyUtility
{


/** Checks does the provided buffer has an UTF32 byte order mark in little endian order. */
bool isUTF32LE(const UINT8* buffer)
{
    return buffer[0] == 0xFF && buffer[1] == 0xFE && buffer[2] == 0x00 && buffer[3] == 0x00;
}

/** Checks does the provided buffer has an UTF32 byte order mark in big endian order. */
bool isUTF32BE(const UINT8* buffer)
{
    return buffer[0] == 0x00 && buffer[1] == 0x00 && buffer[2] == 0xFE && buffer[3] == 0xFF;
}

/** Checks does the provided buffer has an UTF16 byte order mark in little endian order. */
bool isUTF16LE(const UINT8* buffer)
{
    return buffer[0] == 0xFF && buffer[1] == 0xFE;
}

/**	Checks does the provided buffer has an UTF16 byte order mark in big endian order. */
bool isUTF16BE(const UINT8* buffer)
{
    return buffer[0] == 0xFE && buffer[1] == 0xFF;
}

/**	Checks does the provided buffer has an UTF8 byte order mark. */
bool isUTF8(const UINT8* buffer)
{
    return (buffer[0] == 0xEF && buffer[1] == 0xBB && buffer[2] == 0xBF);
}


template<typename T>
DataStream& ToyUtility::DataStream::operator>>(T & val)
{
    read(static_cast<void*>(&val), sizeof(T));

    return *this;
}


String DataStream::GetAsString()
{
    // Read the entire buffer - ideally in one read, but if the size of
    // the buffer is unknown, do multiple fixed size reads.
    size_t bufSize = (m_Size > 0 ? m_Size : 4096);
    std::stringstream::char_type* tempBuffer =
        (std::stringstream::char_type*)new std::stringstream::char_type[bufSize];

    // Ensure read from begin of stream
    Seek(0);

    // Try reading header
    uint8 headerBytes[4];
    size_t numHeaderBytes = Read(headerBytes, 4);

    size_t dataOffset = 0;
    if (numHeaderBytes >= 4)
    {
        if (isUTF32LE(headerBytes))
            dataOffset = 4;
        else if (isUTF32BE(headerBytes))
        {
            TOY_RAW_LOG_ERR << "UTF-32 big endian decoding not supported\n";
            return u8"";
        }
    }

    if (dataOffset == 0 && numHeaderBytes >= 3)
    {
        if (isUTF8(headerBytes))
            dataOffset = 3;
    }

    if (dataOffset == 0 && numHeaderBytes >= 2)
    {
        if (isUTF16LE(headerBytes))
            dataOffset = 2;
        else if (isUTF16BE(headerBytes))
        {
            TOY_RAW_LOG_ERR << "UTF-16 big endian decoding not supported\n";
            return u8"";
        }
    }

    Seek(dataOffset);

    std::stringstream result;
    while (!Eof())
    {
        size_t numReadBytes = Read(tempBuffer, bufSize);
        result.write(tempBuffer, numReadBytes);
    }

    delete[] tempBuffer;
    std::string string = result.str();

    switch (dataOffset)
    {
    default:
    case 0: // No BOM = assumed UTF-8
    case 3: // UTF-8
        return String(string.data(), string.length());
    case 2: // UTF-16
    {
        UINT32 numElems = (UINT32)string.length() / 2;

        // TODO:
        TOY_RAW_LOG_ERR << "UTF-16 decoding not supported\n";
        //return UTF8::fromUTF16(U16String((char16_t*)string.data(), numElems));
    }
    case 4: // UTF-32
    {
        UINT32 numElems = (UINT32)string.length() / 4;

        // TODO:
        TOY_RAW_LOG_ERR << "UTF-32 decoding not supported\n";
        //return UTF8::fromUTF32(U32String((char32_t*)string.data(), numElems));
    }
    }

    // Note: Never assuming ANSI as there is no ideal way to check for it. If required I need to
    // try reading the data and if all UTF encodings fail, assume it's ANSI. For now it should be
    // fine as most files are UTF-8 encoded.
}

void DataStream::WriteString(const String & string)
{
    // Write BOM
    uint8 bom[3] = {0xEF, 0xBB, 0xBF};
    Write(bom, sizeof(bom));

    Write(string.data(), string.length());
}

String DataStream::ReadOneLine()
{
    std::stringstream result;

    while (!Eof())
    {
        int realReadBytes = Read(m_TemBuffer, TEM_BUFFER_LEN);
        char* res = std::find(m_TemBuffer, m_TemBuffer + realReadBytes, '\n');
        if (res != m_TemBuffer + realReadBytes)
        {
            result.write(m_TemBuffer, res - m_TemBuffer);
            Skip(realReadBytes - (res - m_TemBuffer));
            Skip(1); // Skip this \n
            break;
        }
        else
        {
            if (Eof())
            {
                result.write(m_TemBuffer, realReadBytes);
                break;
            }
            else
            {
                result.write(m_TemBuffer, realReadBytes);
            }
        }
    }

    return result.str();
}


} // end of namespace ToyUtility