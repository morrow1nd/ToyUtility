#pragma once

#include <map>
#include <memory>
#include "ToyUtility/Container/Common.h"


namespace ToyUtility
{


template<typename K,
    typename V,
    typename P = std::less<K>,
    typename A = std::allocator<std::pair<const K, V>>>
using Map = std::map<K, V, P, A>;


} // end of namespace ToyUtility