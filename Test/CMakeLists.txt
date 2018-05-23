# Test


file(GLOB_RECURSE CppFiles ${PROJECT_SOURCE_DIR}/Test/*.cpp)


INCLUDE_DIRECTORIES(${TOY_UTILITY_INCLUDE_PATHS})
add_executable(ToyUtility_TestSuit
	${CppFiles}
)


target_link_libraries(ToyUtility_TestSuit ToyUtility)


# IDE specific
set_property(TARGET ToyUtility_TestSuit PROPERTY FOLDER Test)