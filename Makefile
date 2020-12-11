ifeq ($(strip $(YAUL_INSTALL_ROOT)),)
  $(error Undefined YAUL_INSTALL_ROOT (install root directory))
endif

include $(YAUL_INSTALL_ROOT)/share/pre.common.mk

SH_PROGRAM:= doom_r
SH_OBJECTS:= \
sh2doom-1.10/tables.o \
sh2doom-1.10/s_sound.o \
sh2doom-1.10/sounds.o \
sh2doom-1.10/st_lib.o \
sh2doom-1.10/r_sky.o \
sh2doom-1.10/r_things.o \
sh2doom-1.10/r_main.o \
sh2doom-1.10/r_plane.o \
sh2doom-1.10/r_segs.o \
sh2doom-1.10/r_data.o \
sh2doom-1.10/r_draw.o \
sh2doom-1.10/p_switch.o \
sh2doom-1.10/p_telept.o \
sh2doom-1.10/p_tick.o \
sh2doom-1.10/p_user.o \
sh2doom-1.10/r_bsp.o \
sh2doom-1.10/p_setup.o \
sh2doom-1.10/p_sight.o \
sh2doom-1.10/p_spec.o \
sh2doom-1.10/p_plats.o \
sh2doom-1.10/p_pspr.o \
sh2doom-1.10/p_saveg.o \
sh2doom-1.10/p_lights.o \
sh2doom-1.10/p_map.o \
sh2doom-1.10/p_maputl.o \
sh2doom-1.10/p_mobj.o \
sh2doom-1.10/p_ceilng.o \
sh2doom-1.10/p_doors.o \
sh2doom-1.10/p_enemy.o \
sh2doom-1.10/p_floor.o \
sh2doom-1.10/p_inter.o \
sh2doom-1.10/m_misc.o \
sh2doom-1.10/m_random.o \
sh2doom-1.10/m_swap.o \
sh2doom-1.10/m_cheat.o \
sh2doom-1.10/m_fixed.o \
sh2doom-1.10/m_menu.o \
sh2doom-1.10/m_bbox.o \
sh2doom-1.10/i_video.o \
sh2doom-1.10/info.o \
sh2doom-1.10/i_sound.o \
sh2doom-1.10/i_system.o \
sh2doom-1.10/hu_lib.o \
sh2doom-1.10/hu_stuff.o \
sh2doom-1.10/i_main.o \
sh2doom-1.10/i_net.o \
sh2doom-1.10/f_wipe.o \
sh2doom-1.10/g_game.o \
sh2doom-1.10/doomstat.o \
sh2doom-1.10/dstrings.o \
sh2doom-1.10/f_finale.o \
sh2doom-1.10/doomdef.o \
sh2doom-1.10/d_items.o \
sh2doom-1.10/d_main.o \
sh2doom-1.10/d_net.o \
sh2doom-1.10/am_map.o \
sh2doom-1.10/wi_stuff.o \
sh2doom-1.10/z_zone.o \
sh2doom-1.10/v_video.o \
sh2doom-1.10/w_wad.o \
sh2doom-1.10/st_stuff.o \
sh2doom-1.10/fileio.o
#sh2doom-1.10/block.o 

SH_LIBRARIES:=
SH_CFLAGS+= -O2 -I. -save-temps

IP_VERSION:= V1.000
IP_RELEASE_DATE:= 20160101
IP_AREAS:= JTUBKAEL
IP_PERIPHERALS:= JAMKST
IP_TITLE:= DOOM
IP_MASTER_STACK_ADDR:= 0x06004000
IP_SLAVE_STACK_ADDR:= 0x06001000
IP_1ST_READ_ADDR:= 0x06004000

M68K_PROGRAM:=
M68K_OBJECTS:=

include $(YAUL_INSTALL_ROOT)/share/post.common.mk
