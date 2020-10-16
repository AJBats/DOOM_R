JO_COMPILE_WITH_VIDEO_MODULE = 0
JO_COMPILE_WITH_BACKUP_MODULE = 0
JO_COMPILE_WITH_TGA_MODULE = 0
JO_COMPILE_WITH_AUDIO_MODULE = 1
JO_COMPILE_WITH_3D_MODULE = 1
JO_COMPILE_WITH_PSEUDO_MODE7_MODULE = 0
JO_COMPILE_WITH_EFFECTS_MODULE = 0
JO_PSEUDO_SATURN_KAI_SUPPORT = 0
JO_COMPILE_WITH_DUAL_CPU_MODULE = 1
JO_DEBUG = 0
JO_NTSC = 1
JO_COMPILE_USING_SGL=1
SRCS= \
sh2doom-1.10/tables.c \
sh2doom-1.10/s_sound.c \
sh2doom-1.10/sounds.c \
sh2doom-1.10/st_lib.c \
sh2doom-1.10/r_sky.c \
sh2doom-1.10/r_things.c \
sh2doom-1.10/r_main.c \
sh2doom-1.10/r_plane.c \
sh2doom-1.10/r_segs.c \
sh2doom-1.10/r_data.c \
sh2doom-1.10/r_draw.c \
sh2doom-1.10/p_switch.c \
sh2doom-1.10/p_telept.c \
sh2doom-1.10/p_tick.c \
sh2doom-1.10/p_user.c \
sh2doom-1.10/r_bsp.c \
sh2doom-1.10/p_setup.c \
sh2doom-1.10/p_sight.c \
sh2doom-1.10/p_spec.c \
sh2doom-1.10/p_plats.c \
sh2doom-1.10/p_pspr.c \
sh2doom-1.10/p_saveg.c \
sh2doom-1.10/p_lights.c \
sh2doom-1.10/p_map.c \
sh2doom-1.10/p_maputl.c \
sh2doom-1.10/p_mobj.c \
sh2doom-1.10/p_ceilng.c \
sh2doom-1.10/p_doors.c \
sh2doom-1.10/p_enemy.c \
sh2doom-1.10/p_floor.c \
sh2doom-1.10/p_inter.c \
sh2doom-1.10/m_misc.c \
sh2doom-1.10/m_random.c \
sh2doom-1.10/m_swap.c \
sh2doom-1.10/m_cheat.c \
sh2doom-1.10/m_fixed.c \
sh2doom-1.10/m_menu.c \
sh2doom-1.10/m_bbox.c \
sh2doom-1.10/i_video.c \
sh2doom-1.10/info.c \
sh2doom-1.10/i_sound.c \
sh2doom-1.10/i_system.c \
sh2doom-1.10/hu_lib.c \
sh2doom-1.10/hu_stuff.c \
sh2doom-1.10/i_main.c \
sh2doom-1.10/i_net.c \
sh2doom-1.10/f_wipe.c \
sh2doom-1.10/g_game.c \
sh2doom-1.10/doomstat.c \
sh2doom-1.10/dstrings.c \
sh2doom-1.10/f_finale.c \
sh2doom-1.10/doomdef.c \
sh2doom-1.10/d_items.c \
sh2doom-1.10/d_main.c \
sh2doom-1.10/d_net.c \
sh2doom-1.10/am_map.c \
sh2doom-1.10/wi_stuff.c \
sh2doom-1.10/z_zone.c \
sh2doom-1.10/v_video.c \
sh2doom-1.10/w_wad.c \
sh2doom-1.10/st_stuff.c \
sh2doom-1.10/dummyfile.c
JO_ENGINE_SRC_DIR=../../jo_engine
COMPILER_DIR=../../Compiler
include $(COMPILER_DIR)/COMMON/jo_engine_makefile
