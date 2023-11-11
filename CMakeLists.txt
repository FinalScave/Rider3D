cmake_minimum_required(VERSION 3.10)
# set(CMAKE_CXX_STANDARD 17)
# project name
project(unknown3d)

# macro
# add_definitions(-DENABLE_LOG)
option(ENABLE_LOG "Enable logging" OFF)
option(BUILD_PC_DEMO "Build demo for windows or mac to test" ON)

# initial config
set(LINK_LIB)
set(CMAKE_PROJECT_DIR ${CMAKE_SOURCE_DIR})
set(SRC_DIR ${CMAKE_PROJECT_DIR}/src)
set(3DPARTY_DIR ${CMAKE_PROJECT_DIR}/3dparty)

# header search path
include_directories(${3DPARTY_DIR}/bgfx/include)
include_directories(${3DPARTY_DIR}/json-cpp)
include_directories(${SRC_DIR})
include_directories(${SRC_DIR}/util)
include_directories(${SRC_DIR}/unknown)
if(ENABLE_LOG)
    include_directories(${3DPARTY_DIR}/logger)
endif()

# core source files config
file(GLOB_RECURSE CORE_SOURCE_FILES
        ${3DPARTY_DIR}/bgfx/include/bgfx/*.*
        ${3DPARTY_DIR}/bgfx/include/bimg/*.*
        ${3DPARTY_DIR}/bgfx/include/bx/*.*
        ${3DPARTY_DIR}/bgfx/include/tinystl/*.*
        ${3DPARTY_DIR}/json-cpp/*.*
        ${SRC_DIR}/util/*.*
        ${SRC_DIR}/unknown/*.*
        ${SRC_DIR}/unknown/render/*.*
        ${SRC_DIR}/unknown/render/config/*.*
        ${SRC_DIR}/unknown/render/context/*.*
        ${SRC_DIR}/unknown/data/*.*
        )
if(ENABLE_LOG)
    file(GLOB_RECURSE LOGGER_FILES ${3DPARTY_DIR}/logger/*.*)
    set(CORE_SOURCE_FILES ${CORE_SOURCE_FILES} ${LOGGER_FILES})
endif()

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

# Determine whether to build a demo and which platform to build demo on
if (BUILD_PC_DEMO AND NOT ANDROID AND NOT IOS)
    set(DEMO_NAME Unknown3DDemo)

    if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
        set(MACOS ON)
        set(BUILD_DEMO_MACOS ON)
    elseif (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
        set(WINDOWS ON)
        set(BUILD_DEMO_WINDOWS ON)
    endif ()
endif ()

# add library functions
function(android_add_3dparty_static_lib dir name)
    add_library(${name} STATIC IMPORTED)
    set_target_properties(${name}
            PROPERTIES IMPORTED_LOCATION
            ${3DPARTY_DIR}/${dir}/android/${CMAKE_ANDROID_ARCH_ABI}/lib${name}.a)
endfunction()
function(ios_add_3dparty_static_lib dir name)
    add_library(${name} STATIC IMPORTED)
    set_target_properties(${name}
            PROPERTIES IMPORTED_LOCATION
            ${3DPARTY_DIR}/${dir}/iOS/arm64/lib${name}.a)
endfunction()
function(windows_add_3dparty_static_lib dir name)
    add_library(${name} STATIC IMPORTED)
    set_target_properties(${name}
            PROPERTIES IMPORTED_LOCATION
            ${3DPARTY_DIR}/${dir}/windows/x64/lib${name}.a)
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
elseif (IOS)
    ios_add_3dparty_static_lib(bgfx bgfx)
    ios_add_3dparty_static_lib(bgfx bimg)
    ios_add_3dparty_static_lib(bgfx bimg_encode)
    ios_add_3dparty_static_lib(bgfx bimg_decode)
    ios_add_3dparty_static_lib(bgfx bx)
    set(LINK_LIB ${LINK_LIB} bgfx bimg bimg_decode bimg_encode bx)
elseif (WINDOWS)
    windows_add_3dparty_static_lib(bgfx bgfx)
    windows_add_3dparty_static_lib(bgfx bimg)
    windows_add_3dparty_static_lib(bgfx bimg_encode)
    windows_add_3dparty_static_lib(bgfx bimg_decode)
    windows_add_3dparty_static_lib(bgfx bx)
    set(LINK_LIB ${LINK_LIB} bgfx bimg bimg_decode bimg_encode bx)
elseif (MACOS)

endif ()

target_link_libraries(${CMAKE_PROJECT_NAME} ${LINK_LIB})

# Build demo executable for pc
if (BUILD_DEMO_WINDOWS)
    message(STATUS "Build Windows demo enabled")
    include_directories(${CMAKE_SOURCE_DIR}/platform/Windows/lib/glfw/include)
    # file(GLOB_RECURSE DEMO_FILES ${SRC_DIR}/platform/Windows/demo/*.*)
    add_executable(${DEMO_NAME} WIN32 ${CMAKE_SOURCE_DIR}/platform/Windows/demo/main.cpp)
    target_link_libraries(${DEMO_NAME} 
        ${CMAKE_SOURCE_DIR}/build/lib${CMAKE_PROJECT_NAME}.dll
        ${CMAKE_SOURCE_DIR}/platform/Windows/lib/glfw/x64/libglfw3.a
        )
elseif(BUILD_DEMO_MACOS)
    message(STATUS "Build MacOS demo enabled")
endif ()
