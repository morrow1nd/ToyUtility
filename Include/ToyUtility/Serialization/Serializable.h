#pragma once

#include "ToyUtility/Prerequisites/PreDefine.h"


namespace ToyUtility
{


class Serializer;
class Unserializer;


class Serializable
{
public:
    virtual ~Serializable() {}


public:
    virtual void Serialize(Serializer& serializer) const = 0;
    virtual void Unserialize(Unserializer& serializer) = 0;

    //virtual uint32 Length() const = 0;
    //virtual void Serialize(uint8* buffer, uint32 bufferLength, uint32* bytesWritten) const = 0;
    //virtual void Unserialize(const uint8* data, uint32 dataLength) = 0;

};


} // end of namespace ToyUtility