cmake_minimum_required(VERSION 3.10)
# set(CMAKE_CXX_STANDARD 17)
# project name
project(unknown3d)

# macro
add_definitions(-DENABLE_LOG)

# initial config
set(LINK_LIB)
set(CMAKE_PROJECT_DIR ${CMAKE_SOURCE_DIR})
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
# Platform special
if (ANDROID)
    file(GLOB_RECURSE PLATFORM_FILES ${SRC_DIR}/platform/android/*.*)
elseif (IOS)
    file(GLOB_RECURSE PLATFORM_FILES ${SRC_DIR}/platform/iOS/*.*)
elseif (WINDOWS)
    file(GLOB_RECURSE PLATFORM_FILES ${SRC_DIR}/platform/windows/*.*)
elseif (MACOS)
    file(GLOB_RECURSE PLATFORM_FILES ${SRC_DIR}/platform/macOS/*.*)
endif ()

# project shared lib
add_library(${CMAKE_PROJECT_NAME} SHARED ${CORE_SOURCE_FILES} ${PLATFORM_FILES})

# android add library
function (android_add_3dparty_static_lib dir name)
    add_library(${name} STATIC IMPORTED)
    set_target_properties(${name}
            PROPERTIES IMPORTED_LOCATION
            ${3DPARTY_DIR}/${dir}/android/${CMAKE_ANDROID_ARCH_ABI}/lib${name}.a)
endfunction()
function (ios_add_3dparty_static_lib dir name)
    add_library(${name} STATIC IMPORTED)
    set_target_properties(${name}
            PROPERTIES IMPORTED_LOCATION
            ${3DPARTY_DIR}/${dir}/iOS/${CMAKE_ANDROID_ARCH_ABI}/lib${name}.a)
endfunction()
# add library
if (ANDROID)
    android_add_3dparty_static_lib(bgfx bgfx)
    android_add_3dparty_static_lib(bgfx bimg)
    android_add_3dparty_static_lib(bgfx bimg_encode)
    android_add_3dparty_static_lib(bgfx bimg_decode)
    android_add_3dparty_static_lib(bgfx bx)
    find_library(android-lib android)
    find_library(log-lib log)
    set(LINK_LIB ${LINK_LIB} bgfx bimg bimg_decode bimg_encode bx android log jnigraphics libGLESv2.so libEGL.so)
elseif(IOS)

elseif(WINDOWS)
    set(LINK_LIB ${LINK_LIB} bgfx bimg bimg_decode bimg_encode bx)
elseif(MACOS)

endif ()

target_link_libraries(${CMAKE_PROJECT_NAME} ${LINK_LIB})

# Build demo executable for windows
if(WINDOWS)

endif()
