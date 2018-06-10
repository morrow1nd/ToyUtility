#pragma once

#include "ToyUtility/Prerequisites/PreDefine.h"


namespace ToyUtility
{


class RefCounted
{
public:
    RefCounted()
        :
        m_Count(0)
    {}


public:
    void Retain()
    {
        m_Count++;
    }

    void Release()
    {
        m_Count--;
    }

    int RefCountedNumber() const { return m_Count; }


private:
    int m_Count;
};


} // end of namespace ToyUtility