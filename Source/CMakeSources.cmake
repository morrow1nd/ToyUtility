SET(TOY_UTILITY_INC_PREREQUISITES
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Prerequisites/Types.h"
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Prerequisites/PreDefine.h"
)

SET(TOY_UTILITY_SRC_PREREQUISITES
)

SET(TOY_UTILITY_INC_CONTAINER

)

SET(TOY_UTILITY_SRC_CONTAINER
    "test.cpp"
)

SET(TOY_UTILITY_INC_STRING
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/String/String.h"
)

SET(TOY_UTILITY_SRC_STRING)


# if(MSVC)
#   list(APPEND BS_BANSHEECORE_INC_PLATFORM VSVisualizations.natvis)
# endif()


source_group("Header Files\\String"                     FILES ${TOY_UTILITY_INC_STRING})
source_group("Source Files\\String"                     FILES ${TOY_UTILITY_SRC_STRING})
source_group("Header Files\\Container"                  FILES ${TOY_UTILITY_INC_CONTAINER})
source_group("Source Files\\Container"                  FILES ${TOY_UTILITY_SRC_CONTAINER})
source_group("Header Files\\Prerequisites"              FILES ${TOY_UTILITY_INC_PREREQUISITES})
source_group("Source Files\\Prerequisites"              FILES ${TOY_UTILITY_SRC_PREREQUISITES})
source_group("CMake"                                    FILES "CMakeSources.cmake" "CMakeLists.txt")


set(TOY_UTILITY_SRC
    "CMakeSources.cmake" "CMakeLists.txt"
    ${TOY_UTILITY_INC_STRING}
    ${TOY_UTILITY_SRC_STRING}
    ${TOY_UTILITY_INC_CONTAINER}
    ${TOY_UTILITY_SRC_CONTAINER}
    ${TOY_UTILITY_INC_PREREQUISITES}
    ${TOY_UTILITY_SRC_PREREQUISITES}
)
