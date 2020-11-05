// Emacs style mode select   -*- C++ -*- 
//-----------------------------------------------------------------------------
//
// $Id:$
//
// Copyright (C) 1993-1996 by id Software, Inc.
//
// This source is available for distribution and/or modification
// only under the terms of the DOOM Source Code License as
// published by id Software. All rights reserved.
//
// The source is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// FITNESS FOR A PARTICULAR PURPOSE. See the DOOM Source Code License
// for more details.
//
// $Log:$
//
// DESCRIPTION:
//	Main program, simply calls D_DoomMain high level loop.
//
//-----------------------------------------------------------------------------

#include <yaul.h>
#include "doomdef.h"

#include "d_main.h"
#include "dummyfile.h"

static void _hardware_init(void);
static void _vblank_out_handler(void *);

int main() 
{  
    _hardware_init();

    dbgio_dev_default_init(DBGIO_DEV_VDP2_ASYNC);
    dbgio_dev_font_load();
    dbgio_dev_font_load_wait();


    D_DoomMain (); 

    return 0;
} 

static void _hardware_init(void)
{
    vdp2_tvmd_display_res_set(VDP2_TVMD_INTERLACE_NONE, VDP2_TVMD_HORZ_NORMAL_A,
        VDP2_TVMD_VERT_224);

    vdp2_scrn_back_screen_color_set(VDP2_VRAM_ADDR(3, 0x01FFFE),
        COLOR_RGB1555(1, 0, 3, 15));

    vdp_sync_vblank_out_set(_vblank_out_handler);

    cpu_intc_mask_set(0);

    vdp2_tvmd_display_set();
}

static void _vblank_out_handler(void *work __unused)
{
    smpc_peripheral_intback_issue();
}