cmake_minimum_required(VERSION 3.7.2)
project(HitSpoT)

# Version number
set(HST_VERSION_MAJOR 0)
set(HST_VERSION_MINOR 1)
set(HST_TITLE "HitSpoT")

set(HST_NAME hitspot)
set(MST_NAME mathspot)

# Includes
set(HST_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(MST_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/${MST_NAME}/include)
include_directories(${HST_INCLUDE_DIR}
                    ${MST_INCLUDE_DIR})

# Sources
set(HST_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)
set(SOURCES
	${HST_SOURCE_DIR}/BoundingBox.cpp
	${HST_SOURCE_DIR}/CollisionSystem.cpp)
source_group("Sources" FILES ${SOURCES})

set(CMAKE_C_STANDARD   11)
set(CMAKE_CXX_STANDARD 11)

add_subdirectory(mathspot)

# Library
add_library(${HST_NAME} ${SOURCES})
set_target_properties(${HST_NAME} PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(${HST_NAME} ${MST_NAME})

# Test
set(MST_TEST_DIR ${PROJECT_SOURCE_DIR}/test)

function(make_test TEST_NAME)
	# Sources
	set(TEST_SOURCES ${MST_TEST_DIR}/${TEST_NAME}.cpp)
	source_group(${TEST_NAME} FILES ${TEST_SOURCES})

	# Executable
	add_executable(${TEST_NAME} ${TEST_SOURCES})
	set_target_properties(${TEST_NAME} PROPERTIES LINKER_LANGUAGE CXX)
	target_link_libraries(${TEST_NAME} ${HST_NAME})
	add_test(${TEST_NAME} ${EXECUTABLE_OUTPUT_PATH}/${TEST_NAME})
endfunction(make_test)

make_test(simple-test)

include(CTest)
