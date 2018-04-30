#pragma once

// STL algorithms & functions
#include <algorithm>
#include <functional>
#include <limits>

#include "ToyUtility/Prerequisites/PreDefine.h"


namespace ToyUtility
{


/**
* Hash for enum types, to be used instead of std::hash<T> when T is an enum.
*
* Until C++14, std::hash<T> is not defined if T is a enum (see
* http://www.open-std.org/jtc1/sc22/wg21/docs/lwg-defects.html#2148).  But
* even with C++14, as of october 2016, std::hash for enums is not widely
* implemented by compilers, so here when T is a enum, we use EnumClassHash
* instead of std::hash. (For instance, in bs::hash_combine(), or
* bs::UnorderedMap.)
*/
struct EnumClassHash
{
    template <typename T>
    std::size_t operator()(T t) const
    {
        return static_cast<std::size_t>(t);
    }
};


/** Hasher that handles custom enums automatically. */
template<typename Key>
using HashType = typename std::conditional<std::is_enum<Key>::value, EnumClassHash, std::hash<Key>>::type;


} // end of namespace ToyUtility