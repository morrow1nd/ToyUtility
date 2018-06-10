#pragma once

#include <cstdlib>
#include "ToyUtility/Prerequisites/PreDefine.h"
#include "ToyUtility/Container/List.h"
#include "ToyUtility/Memory/NormalAllocator.h"


namespace ToyUtility
{


struct FrameAllocatorBlock
{
    FrameAllocatorBlock() : Usage(0), Length(0), Data(nullptr)
    {
    }

    template<typename AllocatorType>
    void Init(AllocatorType& allocator, uint32 amount)
    {
        Data = static_cast<uint8*>(allocator.Alloc(amount));
        Length = amount;
        Usage = 0;
    }

    template<typename AllocatorType>
    void Release(AllocatorType& allocator)
    {
        allocator.Free(Data);
        Data = nullptr;
        Length = 0;
        Usage = 0;
    }

    bool Enough(uint32 needed) const
    {
        return Usage + needed <= Length;
    }


    uint32 Usage;
    uint32 Length;
    uint8* Data;
};


template<typename AllocatorType>
class FrameAllocator
{
private:

public:
    using allocator_t = AllocatorType;

    FrameAllocator(allocator_t& allocator)
        :
        m_Allocator(allocator)
    {}

    void* Alloc(uint32 amount)
    {
        if (m_Pools.empty() || m_Pools.back().Enough(amount) == false)
        {
            _NewBlock(amount);
        }

        auto& block = m_Pools.back();
        block.Usage += amount;
        return block.Data + (block.Usage - amount);
    }

    // Nothing done really, just keeped for debug and leak track.
    void Free(void* ptr)
    {
    }

    void Clear()
    {
        int size = m_Pools.size();
        for (int i = 0; i < size; ++i)
        {
            m_Pools[i].Release(m_Allocator);
        }
        m_Pools.clear();
    }


private:
    const uint32 BlockDefaultSize = 1024*4;
    void _NewBlock(uint32 amount)
    {
        if (amount < BlockDefaultSize)
        {
            amount = BlockDefaultSize;
        }

        m_Pools.push_back(FrameAllocatorBlock());
        m_Pools.back().Init<allocator_t>(m_Allocator, amount);
    }

private:
    ToyUtility::List<FrameAllocatorBlock> m_Pools;
    allocator_t& m_Allocator;
};


} // end of namespace ToyUtility