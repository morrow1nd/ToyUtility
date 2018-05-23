#include "../catch.hpp"

#include "ToyUtility/Memory/NormalAllocator.h"
#include "ToyUtility/Memory/FrameAllocator.h"


using namespace ToyUtility;


TEST_CASE("-", "[FrameAllocator]")
{
    ToyUtility::NormalAllocator normalAllocator;

    ToyUtility::FrameAllocator<ToyUtility::NormalAllocator> frameAllocator(normalAllocator);


    SECTION("-")
    {
        void* p = frameAllocator.Alloc(1024 * 10);
        void* p2 = frameAllocator.Alloc(65);

        frameAllocator.Free(p);

        frameAllocator.Free(p2);

        frameAllocator.Alloc(1024 * 70);

        //REQUIRE(v.size() == 10);
        //REQUIRE(v.capacity() >= 10);
    }
}