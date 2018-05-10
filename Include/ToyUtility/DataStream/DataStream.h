#pragma once

#include "ToyUtility/Prerequisites/PreDefine.h"
#include "ToyUtility/String/String.h"


namespace ToyUtility
{


class DataStream
{
public:
    enum AccessMode
    {
        READ = 1 << 0,
        WRITE = 1 << 1,
    };


public:
    DataStream(uint16 accessMode = AccessMode::READ)
        :
        m_Access(accessMode)
    {}

    virtual ~DataStream() = default;

    uint16 GetAccessMode() const { return m_Access; }

    virtual bool IsReadable() const { return (m_Access & READ) != 0; }
    virtual bool IsWriteable() const { return (m_Access & WRITE) != 0; }

    // Read the requisite number of bytes from the stream, stopping at the end of the file.
    // Return the number of bytes actually read.
    virtual uint32 Read(void* buffer, uint32 count) = 0;

    // Return the number of bytes actually written
    virtual uint32 Write(const void* buffer, uint32 count) { return 0; }

    // Skip a defined number of bytes. This can also be a negative value, in which case the pointer rewinds
    // a defined number of bytes.
    virtual void Skip(int32 count) = 0;
    // Repositions the read point to a specified byte
    virtual void Seek(uint32 pos) = 0;
    // Returns the current byte offset from beginning
    virtual uint32 Tell() const = 0;
    // Returns true if the stream has reached the end
    virtual bool Eof() const = 0;
    // Returns the total size of the data to be read from the stream, or 0 if this is indeterminate for this stream
    uint32 Size() const { return m_Size; }

    //virtual SPtr<DataStream> clone(bool copyData = true) const = 0;
    
    // Close the stream. This makes further operations invalid.
    virtual void Close() = 0;


    // Reads data from the buffer and copies it to the specified value
    template<typename T> DataStream& operator>>(T& val);

    virtual String GetAsString();

    //virtual WString GetAsWString();

    /**
    * Writes the provided narrow string to the steam. String is convered to the required encoding before being written.
    *
    * @param[in]	string		String containing narrow characters to write, encoded as UTF8.
    * @param[in]	encoding	Encoding to convert the string to before writing.
    */
    //virtual void WriteString(const String& string, StringEncoding encoding = StringEncoding::UTF8);
    virtual void WriteString(const String& string);

    /**
    * Writes the provided wide string to the steam. String is convered to the required encoding before being written.
    *
    * @param[in]	string		String containing wide characters to write, encoded as specified by platform for
    * 							wide characters.
    * @param[in]	encoding	Encoding to convert the string to before writing.
    */
    //virtual void WriteString(const WString& string, StringEncoding encoding = StringEncoding::UTF8);

    // 
    String ReadOneLine();


protected:
    size_t m_Size = 0;
    uint16 m_Access;


private:
    static const int TEM_BUFFER_LEN = 32;
    char m_TemBuffer[TEM_BUFFER_LEN];
};


} // end of namespace ToyUtility