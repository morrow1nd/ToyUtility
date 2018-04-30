#pragma once

#include <unordered_set>
#include "ToyUtility/Container/Common.h"


namespace ToyUtility
{


template<typename T,
    typename H = HashType<T>,
    typename C = std::equal_to<T>,
    typename A = std::allocator<T>>
using UnorderedSet = std::unordered_set<T, H, C, A>;


} // end of namespace ToyUtility