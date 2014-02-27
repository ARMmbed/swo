# Copyright (C) 2013 ARM Limited. All rights reserved.  

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

