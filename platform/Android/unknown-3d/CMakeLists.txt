cmake_minimum_required(VERSION 3.10)
# set(CMAKE_CXX_STANDARD 17)
# project name
project(unknown3d)

# initial config
set(LINK_LIB)
set(CMAKE_PROJECT_DIR ${CMAKE_SOURCE_DIR}/../../..)
set(SRC_DIR ${CMAKE_PROJECT_DIR}/src)
set(3DPARTY_DIR ${CMAKE_PROJECT_DIR}/3dparty)

# header search path
include_directories(${3DPARTY_DIR})
include_directories(${SRC_DIR})
include_directories(${SRC_DIR}/util)
include_directories(${SRC_DIR}/unknown)

# core source files config
file(GLOB_RECURSE CORE_SOURCE_FILES
        ${SRC_DIR}/util/*.*
        ${SRC_DIR}/unknown/*.*
        )
# Android special
if (ANDROID)
    find_library(android-lib android)
    find_library(log-lib log)
    set(LINK_LIB ${LINK_LIB} android log jnigraphics)

    file(GLOB_RECURSE PLATFORM_FILES ${SRC_DIR}/platform/android/*.*)
elseif (IOS)
    file(GLOB_RECURSE PLATFORM_FILES ${SRC_DIR}/platform/iOS/*.*)
endif ()

# add library
add_library(${CMAKE_PROJECT_NAME} SHARED ${CORE_SOURCE_FILES} ${PLATFORM_FILES})

set(LINK_LIB ${LINK_LIB})

target_link_libraries(${CMAKE_PROJECT_NAME}
        ${LINK_LIB}
        )