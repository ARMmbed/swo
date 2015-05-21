/* mbed
 * Copyright (c) 2006-2015 ARM Limited
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "swo/swo.h"
#include "swo-platform/swo-platform.h"

#include <stdio.h>
#include <stdarg.h>


void swoInit()
{
    swoPlatformEnsureInit();
}

void swoSendChar(char c)
{
    swoPlatformEnsureInit();
    swoPlatformSendChar(c);
}

static void swoSend(const char* buffer, int length)
{
    swoPlatformEnsureInit();

    for (int idx = 0; idx < length; idx++)
    {
        swoPlatformSendChar(buffer[idx]);
    }
}

int swoprintf(const char* format, ...)
{
    char buffer[100] = {0};

    va_list arg;
    va_start(arg, format);

    int r = vsnprintf(buffer, 100, format, arg);
    va_end(arg);

    swoSend(buffer, r);

    return r;
}

