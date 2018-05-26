#pragma once

#include <string>
#include "ToyUtility/Prerequisites/PreDefine.h"


namespace ToyUtility
{

//// Supported encoding types for strings
//enum class StringEncoding
//{
//    UTF8 = 1,
//    UTF16 = 2
//};


template <typename T>
using BasicString = std::basic_string < T, std::char_traits<T>, std::allocator<T> >;

// Wide string used primarily for handling Unicode text (UTF-32 on Linux, UTF-16 on Windows, generally)
typedef BasicString<wchar_t> WString;

// Narrow string used for handling narrow encoded text (either locale specific ANSI or UTF-8)
typedef BasicString<char> String;


} // end of namespace ToyUtility