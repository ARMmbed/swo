# Copyright (C) 2013 ARM Limited. All rights reserved.  

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
    swo.m
)
# no proper CMake support for objective-c flags :(
set_target_properties(swo PROPERTIES
    COMPILE_FLAGS "${CMAKE_OBJC_FLAGS}"
)

target_link_libraries(swo
    swo-platform
)

