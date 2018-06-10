#pragma once

#include <functional>
#include "ToyUtility/Prerequisites/PreDefine.h"
#include "ToyUtility/String/String.h"


namespace ToyUtility
{


struct UUID
{
    static UUID CreateVersion1();
    static UUID CreateVersion4();
    static UUID Rebuild(uint64 X, uint64 Y);
    static UUID Rebuild(const String& uustr);

    static UUID None;


    UUID()
    {
        Data.Numbers64.X = 0;
        Data.Numbers64.Y = 0;
    }

    UUID(uint64 X, uint64 Y)
    {
        Data.Numbers64.X = X;
        Data.Numbers64.Y = Y;
    }
    String Str() const;
    String Pretty() const;


    union
    {
        uint8 Bytes[16];
        
        struct
        {
            uint32 A;
            uint32 B;
            uint32 C;
            uint32 D;
        } Numbers;

        struct
        {
            uint64 X;
            uint64 Y;
        } Numbers64;
    } Data;
};

class UUIDHasher : public std::unary_function< ToyUtility::UUID, size_t >
{
public:
    // hash functor: hash uuid to size_t value by pseudorandomizing transform
    size_t operator()(const ToyUtility::UUID& uuid) const
    {
        if (sizeof(size_t) > 4)
        {
            return size_t(uuid.Data.Numbers64.X ^ uuid.Data.Numbers64.Y);
        }
        else
        {
            uint64_t hash64 = uuid.Data.Numbers64.X ^ uuid.Data.Numbers64.Y;
            return size_t(uint32_t(hash64 >> 32) ^ uint32_t(hash64));
        }
    }
};

class UUIDEqualTo
{
public:
    bool operator()(const ToyUtility::UUID& lhs, const ToyUtility::UUID& rhs) const
    {
        return lhs.Data.Numbers64.X == rhs.Data.Numbers64.Y
            && lhs.Data.Numbers64.Y == rhs.Data.Numbers64.Y;
    }
};


} // end of namespace ToyUtility