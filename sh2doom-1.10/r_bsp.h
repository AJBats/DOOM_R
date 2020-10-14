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
// DESCRIPTION:
//	Refresh module, BSP traversal and handling.
//
//-----------------------------------------------------------------------------


#ifndef __R_BSP__
#define __R_BSP__

#ifdef __GNUG__
#pragma interface
#endif


extern seg_t*		gCurline;
extern side_t*		gSidedef;
extern line_t*		gLinedef;
extern sector_t*	gFrontsector;
extern sector_t*	gBacksector;

extern int		gRw_x;
extern int		gRw_stopx;

extern boolean		gSegtextured;

// false if the back side is the same plane
extern boolean		gMarkfloor;		
extern boolean		gMarkceiling;

extern boolean		gSkymap;

extern drawseg_t	gDrawsegs[MAXDRAWSEGS];
extern drawseg_t*	gDs_p;

extern lighttable_t**	gHscalelight;
extern lighttable_t**	gVscalelight;
extern lighttable_t**	gDscalelight;


typedef void (*drawfunc_t) (int start, int stop);


// BSP?
void R_ClearClipSegs (void);
void R_ClearDrawSegs (void);


void R_RenderBSPNode (int bspnum);


#endif
//-----------------------------------------------------------------------------
//
// $Log:$
//
//-----------------------------------------------------------------------------
