/// Copyright (C) 2013 ARM Limited, All rights reserved.

#include "swo/swo.h"

#ifdef EFM32GG

// trying out a specific-module-provides-standard-interface type approach with
// this:
#include "swo-platform/swo-platform.h"

void swoInit(){
    // nothing to do: as SWO has to be accessible everywhere, including ISRs,
    // we can't easily communicate the dependency on clocks etc. to other
    // components - so every time a character is sent over SWO we check that
    // things are configured & switched on as they need to be, and if not
    // set them up again
}

void swoSendChar(char c){
    swoPlatformEnsureInit();
    swoPlatformSendChar(c);
}

#else // def EFM32GG

#error "no supported platform detected" // FIXME this should be a configure-time error

#endif // else def EFM32GG


