

#include <yaul.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "fileio.h"

static iso9660_filelist_entry_t sFilelistEntries[2];
#define DOOMWAD  0
#define DOOM2WAD 1

// extra the doom.wad and doom2.wad file entries
void initFileSystem()
{
    iso9660_filelist_t tmpFilelist;
    iso9660_filelist_entry_t tmpEntries[6];

    tmpFilelist.entries = tmpEntries;    
    
    // change this to stack memory
    assert(false);

    iso9660_filelist_read(&tmpFilelist, 6);

    memcpy(&sFilelistEntries[0], &tmpFilelist.entries[4], sizeof(iso9660_filelist_entry_t));
    memcpy(&sFilelistEntries[1], &tmpFilelist.entries[5], sizeof(iso9660_filelist_entry_t));
}

CDFileHandle GetDoomWad()
{
    return &sFilelistEntries[DOOMWAD];
}

CDFileHandle GetDoom2Wad()
{
    return &sFilelistEntries[DOOM2WAD];
}

int internal_printf(const char * __restrict fmt, va_list args)
{
    char buffer[2048];
    int retcode = vsprintf(buffer, fmt, args);

    //do something with the error
    dbgio_puts(buffer);    

    return retcode; 
}

int debug_phase1(const char * __restrict fmt __unused, ...)
{
#if DEBUG_PHASE_1 == 1
    va_list args;
    va_start(args, fmt);
    int retVal = internal_printf(fmt, args);
    va_end (args);
    getinput();
    return retVal;
#else
    return 0;
#endif
}

int debug_phase2(const char * __restrict fmt __unused, ...)
{
#if DEBUG_PHASE_2 == 1
    va_list args;
    va_start(args, fmt);
    int retVal = internal_printf(fmt, args);
    va_end (args);
    getinput();
    return retVal;
#else
    return 0;
#endif
}

int debug_phase3(const char * __restrict fmt __unused, ...)
{
#if DEBUG_PHASE_3 == 1
    va_list args;
    va_start(args, fmt);
    int retVal = internal_printf(fmt, args);
    va_end (args);
    getinput();
    return retVal;
#else
    return 0;
#endif
}

int printf(const char * __restrict fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    int retVal = internal_printf(fmt, args);
    va_end (args);
    dbgio_flush();
    vdp_sync();
    return retVal;
}


#if DEBUG_PRINT == 1
void clearscreen()
{
    dbgio_puts("[H[2J");
}

void getinput()
{
    //static int counter = 0;
    static smpc_peripheral_digital_t _digital;
    bool held = false;

    smpc_peripheral_process();
    smpc_peripheral_digital_port(1, &_digital);

    held = ((_digital.pressed.raw & PERIPHERAL_DIGITAL_A) != 0x0000);

    while (true)
    {
        //dbgio_printf("[%d;1H %d _dig.pre.raw %X  held %d", counter % 28 + 1, counter % 28, _digital.pressed.raw, held);
        //counter++;

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
