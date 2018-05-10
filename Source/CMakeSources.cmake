SET(TOY_UTILITY_INC_CONTAINER
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Container/Common.h"
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Container/List.h"
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Container/Map.h"
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Container/Set.h"
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Container/UnorderedMap.h"
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Container/UnorderedSet.h"
)

SET(TOY_UTILITY_SRC_CONTAINER
)

SET(TOY_UTILITY_INC_DATA_STREAM
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/DataStream/DataStream.h"
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/DataStream/FileDataStream.h"
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/DataStream/MemoryDataStream.h"
)

SET(TOY_UTILITY_SRC_DATA_STREAM
	"${TOY_UTILITY_SOURCE_DIR}/DataStream/DataStream.cpp"
	"${TOY_UTILITY_SOURCE_DIR}/DataStream/FileDataStream.cpp"
	"${TOY_UTILITY_SOURCE_DIR}/DataStream/MemoryDataStream.cpp"
)

SET(TOY_UTILITY_INC_DESIGN_PATTERN
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/DesignPattern/IModule.h"
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/DesignPattern/ISingleton.h"
)

SET(TOY_UTILITY_INC_EVENT
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Event/Event.h"
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Event/EventHub.h"
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Event/EventListener.h"
)

SET(TOY_UTILITY_SRC_EVENT
	"${TOY_UTILITY_SOURCE_DIR}/Event/EventListener.cpp"
)

SET(TOY_UTILITY_INC_LOG
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Log/Logger.h"
)

SET(TOY_UTILITY_SRC_LOG
)

SET(TOY_UTILITY_INC_MATH
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Math/AABox.h"
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Math/Bounds.h"
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Math/Capsule.h"
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Math/ConvexVolume.h"
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Math/Degree.h"
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Math/Line2.h"
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Math/LineSegment3.h"
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Math/Math.h"
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Math/MathFwdDecl.h"
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Math/Matrix3.h"
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Math/Matrix4.h"
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Math/MatrixNxM.h"
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Math/Plane.h"
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Math/Quaternion.h"
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Math/Radian.h"
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Math/Ray.h"
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Math/Rect2.h"
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Math/Rect2I.h"
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Math/Rect3.h"
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Math/Sphere.h"
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Math/Torus.h"
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Math/TransformPRS.h"
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Math/Vector2.h"
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Math/Vector2I.h"
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Math/Vector3.h"
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Math/Vector3I.h"
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Math/Vector4.h"
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Math/Vector4I.h"
)

SET(TOY_UTILITY_SRC_MATH
	"${TOY_UTILITY_SOURCE_DIR}/Math/AABox.cpp"
	"${TOY_UTILITY_SOURCE_DIR}/Math/Bounds.cpp"
	"${TOY_UTILITY_SOURCE_DIR}/Math/Capsule.cpp"
	"${TOY_UTILITY_SOURCE_DIR}/Math/ConvexVolume.cpp"
	"${TOY_UTILITY_SOURCE_DIR}/Math/Degree.cpp"
	"${TOY_UTILITY_SOURCE_DIR}/Math/Line2.cpp"
	"${TOY_UTILITY_SOURCE_DIR}/Math/LineSegment3.cpp"
	"${TOY_UTILITY_SOURCE_DIR}/Math/Math.cpp"
	"${TOY_UTILITY_SOURCE_DIR}/Math/Matrix3.cpp"
	"${TOY_UTILITY_SOURCE_DIR}/Math/Matrix4.cpp"
	"${TOY_UTILITY_SOURCE_DIR}/Math/Plane.cpp"
	"${TOY_UTILITY_SOURCE_DIR}/Math/Quaternion.cpp"
	"${TOY_UTILITY_SOURCE_DIR}/Math/Radian.cpp"
	"${TOY_UTILITY_SOURCE_DIR}/Math/Ray.cpp"
	"${TOY_UTILITY_SOURCE_DIR}/Math/Rect2.cpp"
	"${TOY_UTILITY_SOURCE_DIR}/Math/Rect2I.cpp"
	"${TOY_UTILITY_SOURCE_DIR}/Math/Rect3.cpp"
	"${TOY_UTILITY_SOURCE_DIR}/Math/Sphere.cpp"
	"${TOY_UTILITY_SOURCE_DIR}/Math/Torus.cpp"
	"${TOY_UTILITY_SOURCE_DIR}/Math/TransformPRS.cpp"
	"${TOY_UTILITY_SOURCE_DIR}/Math/Vector2.cpp"
	"${TOY_UTILITY_SOURCE_DIR}/Math/Vector2I.cpp"
	"${TOY_UTILITY_SOURCE_DIR}/Math/Vector3.cpp"
	"${TOY_UTILITY_SOURCE_DIR}/Math/Vector4.cpp"
)

SET(TOY_UTILITY_INC_MEMORY
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Memory/SmartPtr.h"
)

SET(TOY_UTILITY_SRC_MEMORY
)

SET(TOY_UTILITY_INC_PREREQUISITES
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Prerequisites/Types.h"
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Prerequisites/PreDefine.h"
)

SET(TOY_UTILITY_SRC_PREREQUISITES
)

SET(TOY_UTILITY_INC_SERIALIZATION
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Serialization/BinarySerializer.h"
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Serialization/JsonSerializer.h"
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Serialization/Serializable.h"
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Serialization/Serializer.h"
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Serialization/TextSerializer.h"
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Serialization/XmlSerializer.h"
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/Serialization/Yaml2Serializer.h"
)

SET(TOY_UTILITY_SRC_SERIALIZATION
	"${TOY_UTILITY_SOURCE_DIR}/Serialization/Serializer.cpp"
	"${TOY_UTILITY_SOURCE_DIR}/Serialization/TextSerializer.cpp"
	"${TOY_UTILITY_SOURCE_DIR}/Serialization/XmlSerializer.cpp"
)

SET(TOY_UTILITY_INC_STRING
    "${TOY_UTILITY_INCLUDE_DIR}/ToyUtility/String/String.h"
)

SET(TOY_UTILITY_SRC_STRING
)


# if(MSVC)
#   list(APPEND BS_BANSHEECORE_INC_PLATFORM VSVisualizations.natvis)
# endif()


source_group("CMake"                                    FILES "CMakeSources.cmake" "CMakeLists.txt")
source_group("CMake\\ThirdParty"                        FILES "ThirdParty/CMakeLists.txt")
source_group("Header Files\\String"                     FILES ${TOY_UTILITY_INC_STRING})
source_group("Source Files\\String"                     FILES ${TOY_UTILITY_SRC_STRING})
source_group("Header Files\\Container"                  FILES ${TOY_UTILITY_INC_CONTAINER})
source_group("Source Files\\Container"                  FILES ${TOY_UTILITY_SRC_CONTAINER})
source_group("Header Files\\Prerequisites"              FILES ${TOY_UTILITY_INC_PREREQUISITES})
source_group("Source Files\\Prerequisites"              FILES ${TOY_UTILITY_SRC_PREREQUISITES})
source_group("Header Files\\Memory"						FILES ${TOY_UTILITY_INC_MEMORY})
source_group("Source Files\\Memory"						FILES ${TOY_UTILITY_SRC_MEMORY})
source_group("Header Files\\Design Pattern"				FILES ${TOY_UTILITY_INC_DESIGN_PATTERN})
source_group("Header Files\\Event"						FILES ${TOY_UTILITY_INC_EVENT})
source_group("Source Files\\Event"						FILES ${TOY_UTILITY_SRC_EVENT})
source_group("Header Files\\Math"						FILES ${TOY_UTILITY_INC_MATH})
source_group("Source Files\\Math"						FILES ${TOY_UTILITY_SRC_MATH})
source_group("Header Files\\Log"						FILES ${TOY_UTILITY_INC_LOG})
source_group("Source Files\\Log"						FILES ${TOY_UTILITY_SRC_LOG})
source_group("Header Files\\Serialization"              FILES ${TOY_UTILITY_INC_SERIALIZATION})
source_group("Source Files\\Serialization"              FILES ${TOY_UTILITY_SRC_SERIALIZATION})
source_group("Header Files\\Data Stream"                FILES ${TOY_UTILITY_INC_DATA_STREAM})
source_group("Source Files\\Data Stream"                FILES ${TOY_UTILITY_SRC_DATA_STREAM})


set(TOY_UTILITY_SRC
    "CMakeSources.cmake" "CMakeLists.txt"
	"ThirdParty/CMakeLists.txt"
    ${TOY_UTILITY_INC_STRING}
    ${TOY_UTILITY_SRC_STRING}
    ${TOY_UTILITY_INC_CONTAINER}
    ${TOY_UTILITY_SRC_CONTAINER}
    ${TOY_UTILITY_INC_PREREQUISITES}
    ${TOY_UTILITY_SRC_PREREQUISITES}
	${TOY_UTILITY_INC_MEMORY}
	${TOY_UTILITY_SRC_MEMORY}
	${TOY_UTILITY_INC_DESIGN_PATTERN}
	${TOY_UTILITY_INC_EVENT}
	${TOY_UTILITY_SRC_EVENT}
	${TOY_UTILITY_INC_MATH}
	${TOY_UTILITY_SRC_MATH}
	${TOY_UTILITY_INC_LOG}
	${TOY_UTILITY_SRC_LOG}
	${TOY_UTILITY_INC_SERIALIZATION}
	${TOY_UTILITY_SRC_SERIALIZATION}
	${TOY_UTILITY_INC_DATA_STREAM}
	${TOY_UTILITY_SRC_DATA_STREAM}
)
