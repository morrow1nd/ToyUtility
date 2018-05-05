#pragma once

#include "ToyUtility/Prerequisites/PreDefine.h"


namespace ToyUtility
{


using EventId = int16;


class Event
{
public:
    Event()
        :
        m_Id(EventId())
    {}

    template<typename T>
    void SetId(T t) { m_Id = static_cast<EventId>(t); }
    template<typename T>
    void SetArg1(T v){ m_Arg1 = static_cast<int32>(v); }
    template<typename T>
    void SetArg2(T v){ m_Arg2 = static_cast<uint32>(v); }
    template<typename T>
    void SetArg3(T v){ m_Arg3 = static_cast<float>(v); }
    template<typename T>
    void SetArg4(T v){ m_Arg4 = static_cast<void*>(v); }

    template<typename T1, typename T2>
    void SetArgs(T1 v1, T2 v2)
    {
        m_Arg1 = static_cast<int32>(v1);
        m_Arg2 = static_cast<uint32>(v2);
    }

    template<typename T1, typename T2, typename T3>
    void SetArgs(T1 v1, T2 v2, T3 v3)
    {
        m_Arg1 = static_cast<int32>(v1);
        m_Arg2 = static_cast<uint32>(v2);
        m_Arg3 = static_cast<float>(v3);
    }

    template<typename T1, typename T2, typename T3, typename T4>
    void SetArgs(T1 v1, T2 v2, T3 v3, T4 v4)
    {
        m_Arg1 = static_cast<int32>(v1);
        m_Arg2 = static_cast<uint32>(v2);
        m_Arg3 = static_cast<float>(v3);
        m_Arg4 = static_cast<void*>(v4);
    }

    template<typename T, typename T1, typename T2>
    void SetIdArgs(T id, T1 v1, T2 v2)
    {
        m_Id = static_cast<EventId>(id);
        m_Arg1 = static_cast<int32>(v1);
        m_Arg2 = static_cast<uint32>(v2);
    }

    template<typename T, typename T1, typename T2, typename T3>
    void SetIdArgs(T id, T1 v1, T2 v2, T3 v3)
    {
        m_Id = static_cast<EventId>(id);
        m_Arg1 = static_cast<int32>(v1);
        m_Arg2 = static_cast<uint32>(v2);
        m_Arg3 = static_cast<float>(v3);
    }

    template<typename T, typename T1, typename T2, typename T3, typename T4>
    void SetIdArgs(T id, T1 v1, T2 v2, T3 v3, T4 v4)
    {
        m_Id = static_cast<EventId>(id);
        m_Arg1 = static_cast<int32>(v1);
        m_Arg2 = static_cast<uint32>(v2);
        m_Arg3 = static_cast<float>(v3);
        m_Arg4 = static_cast<void*>(v4);
    }


public:
    EventId GetId() const { return m_Id; }


private:
    EventId m_Id;
    //int16 m_Arg5;
    int32 m_Arg1;
    uint32 m_Arg2;
    float m_Arg3;
    void* m_Arg4;
};


} // end of namespace ToyUtility