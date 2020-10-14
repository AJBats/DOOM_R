

#include <stdio.h>

#pragma GCC diagnostic ignored "-Wunused-parameter"
int printf(const char * __restrict fmt, ...)
{
    return 0;
}
#pragma GCC diagnostic pop // "-Wunused-parameter"