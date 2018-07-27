cmake_minimum_required(VERSION 3.6)

set(CMAKE_C_STANDARD   11)
set(CMAKE_CXX_STANDARD 11)

# HitSpot
set(HST_TITLE HitSpot)
project(${HST_TITLE})

# Version number
set(HST_VERSION_MAJOR 0)
set(HST_VERSION_MINOR 3)
set(HST_NAME hitspot)

# CMake modules
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake)
include(AddMathSpot)

# Includes
set(HST_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(HST_INCLUDE_DIRS ${HST_INCLUDE_DIR} ${MATHSPOT_INCLUDE_DIRS})

# Sources
set(HST_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)
set(SOURCES
	${HST_SOURCE_DIR}/BoundingBox.cpp
	${HST_SOURCE_DIR}/CollisionSystem.cpp)
source_group(Sources FILES ${SOURCES})

# Library
add_library(${HST_NAME} ${SOURCES})
target_include_directories(${HST_NAME} PUBLIC ${HST_INCLUDE_DIRS})
target_link_libraries(${HST_NAME} ${MATHSPOT_LIBRARIES})

# Test
set(HST_TEST_DIR ${PROJECT_SOURCE_DIR}/test)

function(make_test TEST_NAME)
	# Sources
	set(TEST_SOURCES ${HST_TEST_DIR}/${TEST_NAME}.cpp)
	source_group(${TEST_NAME} FILES ${TEST_SOURCES})

	# Executable
	add_executable(${TEST_NAME} ${TEST_SOURCES})
	target_include_directories(${TEST_NAME} PRIVATE ${HST_INCLUDE_DIRS})
	target_link_libraries(${TEST_NAME} ${HST_NAME})
	add_test(${TEST_NAME} ${EXECUTABLE_OUTPUT_PATH}/${TEST_NAME})
endfunction(make_test)

make_test(simple-test)
make_test(payload-test)

include(CTest)
