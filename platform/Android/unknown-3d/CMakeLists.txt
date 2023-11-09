cmake_minimum_required(VERSION 3.10)
# set(CMAKE_CXX_STANDARD 17)
# project name
project(unknown3d)

# bx definition
add_definitions(-DBX_CONFIG_DEBUG=0)

# initial config
set(LINK_LIB)
set(CMAKE_PROJECT_DIR ${CMAKE_SOURCE_DIR}/../../..)
set(SRC_DIR ${CMAKE_PROJECT_DIR}/src)
set(3DPARTY_DIR ${CMAKE_PROJECT_DIR}/3dparty)

# header search path
include_directories(${3DPARTY_DIR}/bgfx/include)
include_directories(${3DPARTY_DIR}/json-cpp)
include_directories(${3DPARTY_DIR}/logger)
include_directories(${SRC_DIR})
include_directories(${SRC_DIR}/util)
include_directories(${SRC_DIR}/unknown)

# core source files config
file(GLOB_RECURSE CORE_SOURCE_FILES
        ${3DPARTY_DIR}/bgfx/include/bgfx/*.*
        ${3DPARTY_DIR}/bgfx/include/bimg/*.*
        ${3DPARTY_DIR}/bgfx/include/bx/*.*
        ${3DPARTY_DIR}/bgfx/include/tinystl/*.*
        ${3DPARTY_DIR}/json-cpp/*.*
        ${3DPARTY_DIR}/logger/*.*
        ${SRC_DIR}/util/*.*
        ${SRC_DIR}/unknown/*.*
        ${SRC_DIR}/unknown/render/*.*
        ${SRC_DIR}/unknown/render/config/*.*
        ${SRC_DIR}/unknown/render/context/*.*
        ${SRC_DIR}/unknown/data/*.*
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
add_library(bgfx SHARED IMPORTED)
add_library(bimg SHARED IMPORTED)
add_library(bimg_decode SHARED IMPORTED)
add_library(bimg_encode SHARED IMPORTED)
add_library(bx SHARED IMPORTED)

set_target_properties(bgfx
        PROPERTIES IMPORTED_LOCATION
        ${3DPARTY_DIR}/bgfx/android/${CMAKE_ANDROID_ARCH_ABI}/libbgfx.a)
set_target_properties(bimg
        PROPERTIES IMPORTED_LOCATION
        ${3DPARTY_DIR}/bgfx/android/${CMAKE_ANDROID_ARCH_ABI}/libbimg.a)
set_target_properties(bimg_decode
        PROPERTIES IMPORTED_LOCATION
        ${3DPARTY_DIR}/bgfx/android/${CMAKE_ANDROID_ARCH_ABI}/libbimg_decode.a)
set_target_properties(bimg_encode
        PROPERTIES IMPORTED_LOCATION
        ${3DPARTY_DIR}/bgfx/android/${CMAKE_ANDROID_ARCH_ABI}/libbimg_encode.a)
set_target_properties(bx
        PROPERTIES IMPORTED_LOCATION
        ${3DPARTY_DIR}/bgfx/android/${CMAKE_ANDROID_ARCH_ABI}/libbx.a)

set(LINK_LIB ${LINK_LIB} bgfx bimg bimg_decode bimg_encode bx)

target_link_libraries(${CMAKE_PROJECT_NAME}
        ${LINK_LIB}
        )