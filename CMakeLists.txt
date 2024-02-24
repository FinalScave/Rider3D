cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
# project name
project(unknown3d)

# macro
add_definitions(-DBX_CONFIG_DEBUG=ON)
add_definitions(-DENABLE_LOG)
add_definitions(-DFORCE_GLFW)
option(ENABLE_LOG "Enable logging" ON)
option(BUILD_PC_DEMO "Build demo for Windows/Mac/Linux to test" ON)

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
include_directories(${SRC_DIR}/core)
include_directories(${SRC_DIR}/component)
if (ENABLE_LOG)
    include_directories(${3DPARTY_DIR}/logger)
endif ()

# core source files config
file(GLOB_RECURSE CORE_SOURCE_FILES
        ${3DPARTY_DIR}/bgfx/include/bgfx/*.*
        ${3DPARTY_DIR}/bgfx/include/bimg/*.*
        ${3DPARTY_DIR}/bgfx/include/bx/*.*
        ${3DPARTY_DIR}/bgfx/include/tinystl/*.*
        ${3DPARTY_DIR}/json-cpp/*.*
        ${SRC_DIR}/UnknownEngine.h
        ${SRC_DIR}/UnknownEngine.cpp
        ${SRC_DIR}/component/*.*
        ${SRC_DIR}/core/*.*
        ${SRC_DIR}/entityx/*.*
        ${SRC_DIR}/util/*.*
)
if (ENABLE_LOG)
    file(GLOB_RECURSE LOGGER_FILES ${3DPARTY_DIR}/logger/*.*)
    set(CORE_SOURCE_FILES ${CORE_SOURCE_FILES} ${LOGGER_FILES})
endif ()

# Determine whether to build a demo and which platform to build demo on
if (BUILD_PC_DEMO AND NOT ANDROID AND NOT IOS)
    set(DEMO_NAME Unknown3DDemo)

    if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
        add_definitions(-DMACOS)
        set(MACOS ON)
        set(BUILD_DEMO_MACOS ON)
    elseif (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
        add_definitions(-DWINDOWS -D_POSIX -D_POSIX_THREAD_SAFE_FUNCTIONS)
        set(WINDOWS ON)
        set(BUILD_DEMO_WINDOWS ON)
    elseif (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
        add_definitions(-DLINUX)
        set(LINUX ON)
        set(BUILD_DEMO_LINUX ON)
    endif ()
endif ()

# Platform special
if (ANDROID)
    file(GLOB_RECURSE PLATFORM_FILES ${SRC_DIR}/platform/android/*.*)
elseif (IOS)
    file(GLOB_RECURSE PLATFORM_FILES ${SRC_DIR}/platform/iOS/*.*)
elseif (WINDOWS)
    file(GLOB_RECURSE PLATFORM_FILES ${SRC_DIR}/platform/windows/*.*)
elseif (MACOS)
    file(GLOB_RECURSE PLATFORM_FILES ${SRC_DIR}/platform/macOS/*.*)
elseif (LINUX)
    file(GLOB_RECURSE PLATFORM_FILES ${SRC_DIR}/platform/linux/*.*)
endif ()

# project shared lib
add_library(${CMAKE_PROJECT_NAME} SHARED ${CORE_SOURCE_FILES} ${PLATFORM_FILES})

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
function(mac_add_3dparty_static_lib dir name)
    add_library(${name} STATIC IMPORTED)
    set_target_properties(${name}
            PROPERTIES IMPORTED_LOCATION
            ${3DPARTY_DIR}/${dir}/macOS/arm64/lib${name}.a)
endfunction()
function(linux_add_3dparty_static_lib dir name)
    add_library(${name} STATIC IMPORTED)
    set_target_properties(${name}
            PROPERTIES IMPORTED_LOCATION
            ${3DPARTY_DIR}/${dir}/linux/x86_64/lib${name}.a)
endfunction()


# add library
if (ANDROID)
    android_add_3dparty_static_lib(bgfx bgfx)
    android_add_3dparty_static_lib(bgfx bimg)
    android_add_3dparty_static_lib(bgfx bimg_encode)
    android_add_3dparty_static_lib(bgfx bimg_decode)
    android_add_3dparty_static_lib(bgfx bx)
    find_library(ANDROID_LIB android)
    find_library(LOG_LIB log)
    find_library(JNI_GRAPHICS jnigraphics)
    find_library(GLES libGLESv2.so)
    find_library(EGL libEGL.so)
    set(LINK_LIB ${LINK_LIB} ${ANDROID_LIB} ${LOG_LIB} ${JNI_GRAPHICS} ${GLES} ${EGL}
            bgfx bimg bimg_decode bimg_encode bx
    )
elseif (IOS)
    ios_add_3dparty_static_lib(bgfx bgfx)
    ios_add_3dparty_static_lib(bgfx bimg)
    ios_add_3dparty_static_lib(bgfx bimg_encode)
    ios_add_3dparty_static_lib(bgfx bimg_decode)
    ios_add_3dparty_static_lib(bgfx bx)
    find_library(FOUNDATION_FRAMEWORK Foundation)
    find_library(CORE_FOUNDATION_FRAMEWORK CoreFoundation)
    find_library(IOKIT_FRAMEWORK IOKit)
    find_library(METAL_FRAMEWORK Metal)
    find_library(QUARTZ_CORE_FRAMEWORK QuartzCore)
    find_library(UIKIT_FRAMEWORK UIKit)
    set(LINK_LIB ${LINK_LIB}
            ${FOUNDATION_FRAMEWORK} ${CORE_FOUNDATION_FRAMEWORK} ${IOKIT_FRAMEWORK}
            ${METAL_FRAMEWORK} ${QUARTZ_CORE_FRAMEWORK} ${UIKIT_FRAMEWORK}
            bgfx bimg bimg_decode bimg_encode bx
    )
elseif (WINDOWS)
    windows_add_3dparty_static_lib(bgfx bgfx)
    windows_add_3dparty_static_lib(bgfx bimg)
    windows_add_3dparty_static_lib(bgfx bimg_encode)
    windows_add_3dparty_static_lib(bgfx bimg_decode)
    windows_add_3dparty_static_lib(bgfx bx)
    set(LINK_LIB ${LINK_LIB} bgfx bimg bimg_decode bimg_encode bx)
elseif (MACOS)
    mac_add_3dparty_static_lib(bgfx bgfx)
    mac_add_3dparty_static_lib(bgfx bimg)
    mac_add_3dparty_static_lib(bgfx bimg_encode)
    mac_add_3dparty_static_lib(bgfx bimg_decode)
    mac_add_3dparty_static_lib(bgfx bx)
    find_library(FOUNDATION_FRAMEWORK Foundation)
    find_library(CORE_FOUNDATION_FRAMEWORK CoreFoundation)
    find_library(IOKIT_FRAMEWORK IOKit)
    find_library(METAL_FRAMEWORK Metal)
    find_library(QUARTZ_CORE_FRAMEWORK QuartzCore)
    find_library(APPKIT_FRAMEWORK AppKit)
    find_library(SECURITY_FRAMEWORK Security)
    set(LINK_LIB ${LINK_LIB}
            ${FOUNDATION_FRAMEWORK} ${CORE_FOUNDATION_FRAMEWORK} ${IOKIT_FRAMEWORK}
            ${METAL_FRAMEWORK} ${QUARTZ_CORE_FRAMEWORK} ${APPKIT_FRAMEWORK} ${SECURITY_FRAMEWORK}
            bgfx bimg bimg_decode bimg_encode bx
    )
elseif (LINUX)
    linux_add_3dparty_static_lib(bgfx bgfx)
    linux_add_3dparty_static_lib(bgfx bimg)
    linux_add_3dparty_static_lib(bgfx bimg_encode)
    linux_add_3dparty_static_lib(bgfx bimg_decode)
    linux_add_3dparty_static_lib(bgfx bx)
    set(LINK_LIB ${LINK_LIB} bgfx bimg bimg_decode bimg_encode bx)
endif ()

target_link_libraries(${CMAKE_PROJECT_NAME} ${LINK_LIB})

# Build demo executable for pc
if (BUILD_DEMO_WINDOWS)
    message(STATUS "Build Windows demo enabled")
    include_directories(${CMAKE_SOURCE_DIR}/platform/Windows/lib/glfw/include)
    add_executable(${DEMO_NAME} WIN32
            ${CMAKE_SOURCE_DIR}/platform/Windows/demo/main.cpp
            ${CORE_SOURCE_FILES} ${PLATFORM_FILES}
    )
    target_link_libraries(${DEMO_NAME}
            ${LINK_LIB}
            ${CMAKE_SOURCE_DIR}/platform/Windows/lib/glfw/x64/libglfw3.a
    )
elseif (BUILD_DEMO_MACOS)
    message(STATUS "Build MacOS demo enabled")
    include_directories(${CMAKE_SOURCE_DIR}/platform/MacOS/lib/glfw/include)
    add_executable(${DEMO_NAME} MACOSX_BUNDLE
            ${CMAKE_SOURCE_DIR}/platform/MacOS/demo/main.cpp
            ${CORE_SOURCE_FILES} ${PLATFORM_FILES}
    )
    find_library(FOUNDATION_FRAMEWORK Foundation)
    find_library(CORE_GRAPHICS_FRAMEWORK CoreGraphics)
    find_library(CORE_VIDEO_FRAMEWORK CoreVideo)
    find_library(APPKIT_FRAMEWORK AppKit)
    find_library(IOKIT_FRAMEWORK IOKit)
    target_link_libraries(${DEMO_NAME}
            ${LINK_LIB}
            ${CMAKE_SOURCE_DIR}/platform/MacOS/lib/glfw/arm64/libglfw3.a
            ${FOUNDATION_FRAMEWORK}
            ${CORE_GRAPHICS_FRAMEWORK}
            ${CORE_VIDEO_FRAMEWORK}
            ${APPKIT_FRAMEWORK}
            ${IOKIT_FRAMEWORK}
    )
elseif (BUILD_DEMO_LINUX)
    message(STATUS "Build Linux demo enabled")
    add_executable(${DEMO_NAME}
            ${CMAKE_SOURCE_DIR}/platform/Linux/demo/main.cpp
            ${CORE_SOURCE_FILES} ${PLATFORM_FILES}
    )
    find_package(glfw3 REQUIRED)
    include_directories(${GLFW_INCLUDE_DIRS})
    target_link_libraries(${DEMO_NAME}
            ${LINK_LIB} glfw
    )
endif ()
