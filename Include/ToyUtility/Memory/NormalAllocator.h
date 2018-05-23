#pragma once

#include <cstdlib>
#include "ToyUtility/Prerequisites/PreDefine.h"


namespace ToyUtility
{


class NormalAllocator
{
public:
    void* Alloc(uint32 amount)
    {
        return ::malloc(amount);
    }

    void Free(void* ptr)
    {
        ::free(ptr);
    }
};


} // end of namespace ToyUtility