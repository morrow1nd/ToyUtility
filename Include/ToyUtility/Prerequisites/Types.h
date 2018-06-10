#pragma once

#include <cstdint>


// Common type define
namespace ToyUtility
{


typedef std::int8_t int8;
typedef std::uint8_t uint8;
typedef std::int16_t int16;
typedef std::uint16_t uint16;
typedef std::int32_t int32;
typedef std::uint32_t uint32;
typedef std::int64_t int64;
typedef std::uint64_t uint64;


enum CommonType
{
    _Begin = 0,

    bool_,
    uint8_,
    int8_,
    uint16_,
    int16_,
    uint32_,
    int32_,
    uint64_,
    int64_,
    float_,
    double_,

    _End,
};


} // end of namespace ToyUtility