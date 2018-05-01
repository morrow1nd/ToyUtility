SET(TOY_UTILITY_INC_PREREQUISITES
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Prerequisites/Types.h"
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Prerequisites/PreDefine.h"
)

SET(TOY_UTILITY_SRC_PREREQUISITES
)

SET(TOY_UTILITY_INC_CONTAINER
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Container/Common.h"
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Container/List.h"
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Container/UnorderedMap.h"
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Container/UnorderedSet.h"
)

SET(TOY_UTILITY_SRC_CONTAINER
)

SET(TOY_UTILITY_INC_STRING
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/String/String.h"
)

SET(TOY_UTILITY_SRC_STRING
)

SET(TOY_UTILITY_INC_MEMORY
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Memory/SmartPtr.h"
)

SET(TOY_UTILITY_SRC_MEMORY
)

SET(TOY_UTILITY_INC_DESIGN_PATTERN
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/DesignPattern/IModule.h"
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/DesignPattern/ISingleton.h"
)

SET(TOY_UTILITY_INC_MATH
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Math/Degree.h"
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Math/Math.h"
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Math/MathFwdDecl.h"
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Math/Matrix3.h"
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Math/Matrix4.h"
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Math/MatrixNxM.h"
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Math/Quaternion.h"
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Math/Radian.h"
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Math/TransformPRS.h"
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Math/Vector2.h"
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Math/Vector2I.h"
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Math/Vector3.h"
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Math/Vector3I.h"
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Math/Vector4.h"
)

SET(TOY_UTILITY_SRC_MATH
	"${TOY_UTILITY_SOURCE_DIR}/Math/Degree.cpp"
	"${TOY_UTILITY_SOURCE_DIR}/Math/Math.cpp"
	"${TOY_UTILITY_SOURCE_DIR}/Math/Matrix3.cpp"
	"${TOY_UTILITY_SOURCE_DIR}/Math/Matrix4.cpp"
	"${TOY_UTILITY_SOURCE_DIR}/Math/Quaternion.cpp"
	"${TOY_UTILITY_SOURCE_DIR}/Math/Radian.cpp"
	"${TOY_UTILITY_SOURCE_DIR}/Math/TransformPRS.cpp"
	"${TOY_UTILITY_SOURCE_DIR}/Math/Vector2.cpp"
	"${TOY_UTILITY_SOURCE_DIR}/Math/Vector2I.cpp"
	"${TOY_UTILITY_SOURCE_DIR}/Math/Vector3.cpp"
	"${TOY_UTILITY_SOURCE_DIR}/Math/Vector3I.cpp"
	"${TOY_UTILITY_SOURCE_DIR}/Math/Vector4.cpp"
)


# if(MSVC)
#   list(APPEND BS_BANSHEECORE_INC_PLATFORM VSVisualizations.natvis)
# endif()


source_group("CMake"                                    FILES "CMakeSources.cmake" "CMakeLists.txt")
source_group("Header Files\\String"                     FILES ${TOY_UTILITY_INC_STRING})
source_group("Source Files\\String"                     FILES ${TOY_UTILITY_SRC_STRING})
source_group("Header Files\\Container"                  FILES ${TOY_UTILITY_INC_CONTAINER})
source_group("Source Files\\Container"                  FILES ${TOY_UTILITY_SRC_CONTAINER})
source_group("Header Files\\Prerequisites"              FILES ${TOY_UTILITY_INC_PREREQUISITES})
source_group("Source Files\\Prerequisites"              FILES ${TOY_UTILITY_SRC_PREREQUISITES})
source_group("Header Files\\Memory"						FILES ${TOY_UTILITY_INC_MEMORY})
source_group("Source Files\\Memory"						FILES ${TOY_UTILITY_SRC_MEMORY})
source_group("Header Files\\Design Pattern"				FILES ${TOY_UTILITY_INC_DESIGN_PATTERN})
source_group("Header Files\\Math"						FILES ${TOY_UTILITY_INC_MATH})
source_group("Source Files\\Math"						FILES ${TOY_UTILITY_SRC_MATH})


set(TOY_UTILITY_SRC
    "CMakeSources.cmake" "CMakeLists.txt"
    ${TOY_UTILITY_INC_STRING}
    ${TOY_UTILITY_SRC_STRING}
    ${TOY_UTILITY_INC_CONTAINER}
    ${TOY_UTILITY_SRC_CONTAINER}
    ${TOY_UTILITY_INC_PREREQUISITES}
    ${TOY_UTILITY_SRC_PREREQUISITES}
	${TOY_UTILITY_INC_MEMORY}
	${TOY_UTILITY_SRC_MEMORY}
	${TOY_UTILITY_INC_DESIGN_PATTERN}
	${TOY_UTILITY_INC_MATH}
	${TOY_UTILITY_SRC_MATH}
)
