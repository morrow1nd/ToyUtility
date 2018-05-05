#pragma once

#include <map>
#include "ToyUtility/Container/Common.h"


namespace ToyUtility
{


template<typename T,
    typename P = std::less<T>,
    typename A = StdAlloc<T>>
using Set = std::set<T, P, A>;


} // end of namespace ToyUtility