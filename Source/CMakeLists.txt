# 
# ToyUtility/Source
# 

## Source files and their filters
## INCLUDE(CMakeSources.cmake)


# SET(TW_UTILITY_INCLUDE
#     "${TW_SOURCE_DIR}/Utility"
#     CACHE INTERNAL "ToyWorld Utility Include Paths"
# )

INCLUDE_DIRECTORIES(${TOY_UTILITY_SOURCE_DIR}/../Include)

# Target
#ADD_LIBRARY(ToyUtility ${TW_UTILITY_SRC})
# ADD_LIBRARY(ToyUtility SHARED ${TW_UTILITY_SRC})

ADD_LIBRARY(ToyUtility "test.cpp")


# IDE specific
SET_PROPERTY(TARGET ToyUtility PROPERTY FOLDER Layers)