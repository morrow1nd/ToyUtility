#pragma once

#include "ToyUtility/Prerequisites/Types.h"

#ifdef _WIN32
#  undef min
#  undef max
#	if !defined(NOMINMAX) && defined(_MSC_VER)
#		define NOMINMAX // required to stop windows.h messing up std::min
#	endif
#  if defined( __MINGW32__ )
#    include <unistd.h>
#  endif
#endif


namespace ToyUtility
{

} // end of namespace ToyUtility