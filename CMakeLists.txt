set(COMMON_INCLUDES ${PROJECT_SOURCE_DIR}/include)
	set(COMMON_INCLUDES ${PROJECT_SOURCE_DIR}/src)
	include_directories(${COMMON_INCLUDES})
	file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/test/*.cpp)
	
	
	set(SRC_FILES ${PROJECT_SOURCE_DIR}/src/deanery.cpp)
	     
	set(SRC_FILES ${PROJECT_SOURCE_DIR}/src/main.cpp)
	
	set(CMAKE_CXX_STANDARD 11)
