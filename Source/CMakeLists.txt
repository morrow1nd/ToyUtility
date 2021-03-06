# 
# ToyUtility/Source
# 


## Operating System Check
# set(TOY_OS_UNKNOWN			"(0)")		# Unknown
# set(TOY_OS_WINDOWS			"(1 << 0)") # Microsoft Windows
# set(TOY_OS_LINUX			"(1 << 1)") # Linux
# set(TOY_OS_UNIX				"(1 << 2)") # Linux And Apple MacOS
# set(TOY_OS_MACOS			"(1 << 3)") # Apple MacOS
# 
# SET(TOY_OS ${TOY_OS_UNKNOWN} CACHE INTERNAL "-")

SET(TOY_WINDOWS 0 CACHE INTERNAL "-")
SET(TOY_MACOS 0 CACHE INTERNAL "-")
SET(TOY_LINUX 0 CACHE INTERNAL "-")
SET(TOY_UNIX 0 CACHE INTERNAL "-")

if(WIN32)
SET(TOY_WINDOWS 1 CACHE INTERNAL "-")
endif()
if(APPLE)
SET(TOY_MACOS 1 CACHE INTERNAL "-")
endif()
if(LINUX)
SET(TOY_LINUX 1 CACHE INTERNAL "-")
endif()
if(UNIX AND NOT APPLE)
SET(TOY_UNIX 1 CACHE INTERNAL "-")
endif()

## Compiler Check(TODO)



## Configure file
CONFIGURE_FILE(
    "${TOY_UTILITY_SOURCE_DIR}/ToyUtilityConfig.h.in"
    "${PROJECT_BINARY_DIR}/ToyUtilityConfig.h"
)

ADD_SUBDIRECTORY(ThirdParty)

# Source files and their filters
INCLUDE(CMakeSources.cmake)

INCLUDE_DIRECTORIES(
    ${TOY_UTILITY_INCLUDE_DIR}
    ${PROJECT_BINARY_DIR}
	${TOY_UTILITY_THIRD_PARTY_LIBS_INCLUDE}
)

# Target
ADD_LIBRARY(ToyUtility
    ${TOY_UTILITY_SRC}
    ToyUtilityConfig.h.in
)
# ADD_LIBRARY(ToyUtility SHARED ${TOY_UTILITY_SRC})

TARGET_LINK_LIBRARIES(ToyUtility
	${TOY_UTILITY_THIRD_PARTY_LIBS_DEPS}
)

# IDE specific
#Only when it's set to TRUE, can we use: SET_PROPERTY(TARGET ToyUtility PROPERTY FOLDER Layers)
set_property(GLOBAL PROPERTY USE_FOLDERS TRUE)
SET_PROPERTY(TARGET ToyUtility PROPERTY FOLDER Layers)

## For lib user
SET(TOY_UTILITY_INCLUDE_PATHS
    "${TOY_UTILITY_INCLUDE_DIR}"
	"${PROJECT_BINARY_DIR}"
	"${TOY_UTILITY_THIRD_PARTY_LIBS_INCLUDE}"
    CACHE INTERNAL "ToyUtility INCLUDE PATHS"
)

SET(TOY_UTILITY_LIBRARIES
    ToyUtility
	${TOY_UTILITY_THIRD_PARTY_LIBS_DEPS}
    CACHE INTERNAL "ToyUtility Librarys"
)