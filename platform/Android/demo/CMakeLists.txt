cmake_minimum_required(VERSION 3.10)
project(demo)

set(DEMO_SRC_DIR ${CMAKE_SOURCE_DIR}/src/main/cpp)
file(GLOB_RECURSE DEMO_CORE_FILES
        ${DEMO_SRC_DIR}/*.*)

add_library(${CMAKE_PROJECT_NAME} SHARED ${DEMO_CORE_FILES})
target_link_libraries(${CMAKE_PROJECT_NAME})