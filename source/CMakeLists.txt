# Copyright (C) 2013 ARM Limited. All rights reserved.  

add_library(swo
    swo.c
)

target_link_libraries(swo
    swo-platform
)

