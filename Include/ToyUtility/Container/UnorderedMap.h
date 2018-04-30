#pragma once

#include <unordered_map>
#include "ToyUtility/Container/Common.h"


namespace ToyUtility
{


template<typename K,
    typename V,
    typename H = HashType<K>,
    typename C = std::equal_to<K>,
    typename A = std::allocator<std::pair<const K, V>>>
using UnorderedMap = std::unordered_map<K, V, H, C, A>;


} // end of namespace ToyUtility