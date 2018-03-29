# 
# ToyUtility/Source
# 

## Configure file
CONFIGURE_FILE(
    "${TOY_UTILITY_SOURCE_DIR}/ToyUtilityConfig.h.in"
    "${PROJECT_BINARY_DIR}/ToyUtilityConfig.h"
    )


# Source files and their filters
INCLUDE(CMakeSources.cmake)

SET(TOY_UTILITY_INCLUDE_PATHS
    "${TOY_UTILITY_INCLUDE_DIR}"
    CACHE INTERNAL "ToyUtility INCLUDE PATHS"
)

INCLUDE_DIRECTORIES(
    ${TOY_UTILITY_INCLUDE_DIR}
    ${PROJECT_BINARY_DIR}
)

# Target
ADD_LIBRARY(ToyUtility
    ${TOY_UTILITY_SRC}
    ToyUtilityConfig.h.in
)
# ADD_LIBRARY(ToyUtility SHARED ${TOY_UTILITY_SRC})


#Only when it's set to TRUE, can we use: SET_PROPERTY(TARGET ToyUtility PROPERTY FOLDER Layers)
set_property(GLOBAL PROPERTY USE_FOLDERS TRUE)

# IDE specific
SET_PROPERTY(TARGET ToyUtility PROPERTY FOLDER Layers)