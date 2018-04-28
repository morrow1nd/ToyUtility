#pragma once

#include <memory>
#include "ToyUtility/Prerequisites/PreDefine.h"


namespace ToyUtility
{


template<typename T>
using SPtr = std::shared_ptr<T>;

template<typename T>
using WeakPtr = std::weak_ptr<T>;

template<typename T>
using UPtr = std::unique_ptr<T>;


} // end of namespace ToyUtility