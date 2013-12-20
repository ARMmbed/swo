# Copyright (C) 2013 ARM Limited. All rights reserved.  
cmake_minimum_required(VERSION 2.8)

# use toolchain file from the toolchain package!
set(CMAKE_TOOLCHAIN_FILE yotta_modules/toolchain/CMake/toolchain.cmake)

project(swo)

# include root dirs of all packages
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/yotta_modules/toolchain)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/yotta_modules/swo-efm32)

# CMake can't handle repeated dependencies, even if they're symlinked...
# we just need headers / toolchain stuff from dependencies anyway
#add_subdirectory(yotta_modules/toolchain)
add_subdirectory(yotta_modules/swo-efm32)


# FIXME: this is necessary because we expect to be able to include, e.g. libc
# files without a prefix, but they are provided within a module
include_directories(SYSTEM ${EXTRA_SYSTEM_INCLUDE_DIRS})

# FIXME: this is necessary because em_x.h files expect to be able to include
# em_device.h, and em_device.h is provided by a separate module. See comments
# in bootstrap-efm32gg/CMakeLists.txt (these definitions are currently provided by
# bootstrap-efm32gg)
include_directories(${EXTRA_INCLUDE_DIRS})
add_definitions(${EXTRA_DEFINITIONS})

add_library(swo
    source/swo.m
)
# no proper CMake support for objective-c flags :(
set_target_properties(swo PROPERTIES
    COMPILE_FLAGS "${CMAKE_OBJC_FLAGS}"
)

target_link_libraries(swo
    swo-platform
)

