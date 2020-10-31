

#include <yaul.h>
#include <stdio.h>
#include <stdarg.h>
#include "dummyfile.h"

#pragma GCC diagnostic ignored "-Wunused-parameter"
int printf(const char * __restrict fmt, ...)
{
    char buffer[2048];
    int retcode = 0;
    va_list args;

    va_start(args, fmt);
    (void)vsprintf(buffer, fmt, args);

    //do something with the error
    dbgio_puts(buffer);

    retcode = strlen(buffer);

    va_end (args);

    getinput();

    return retcode; 
}

#if DEBUG_PRINT == 1
void clearscreen()
{
    dbgio_puts("[H[2J");
}

void getinput()
{
    static smpc_peripheral_digital_t _digital;
    bool held = false;

    smpc_peripheral_process();
    smpc_peripheral_digital_port(1, &_digital);

    held = ((_digital.pressed.raw & PERIPHERAL_DIGITAL_A) != 0x0000);

    while (true)
    {
        dbgio_flush();
        vdp_sync();

        if (((_digital.pressed.raw & PERIPHERAL_DIGITAL_A) != 0x0000) && !held)
        {
            break;
        }

        smpc_peripheral_process();
        smpc_peripheral_digital_port(1, &_digital);

        if (held)
        {
            held = ((_digital.pressed.raw & PERIPHERAL_DIGITAL_A) != 0x0000);
        }
    }
}
#endif

#pragma GCC diagnostic pop // "-Wunused-parameter"