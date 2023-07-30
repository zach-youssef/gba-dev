#ifndef DISPLAY_CONTROL_H
#define DISPLAY_CONTROL_H

#include "memory.h"
#include "basic_types.h"

// Display Control

#define DISPLAY_CONTROL *((volatile u32*)(MEMORY_IO + 0x0000))

#define DISPLAY_MODE0 0x0000
#define DISPLAY_MODE1 0x0001
#define DISPLAY_MODE2 0x0002
#define DISPLAY_MODE3 0x0003
#define DISPLAY_MODE4 0x0004
#define DISPLAY_MODE5 0x0005

#define DISPLAY_PAGE_SELECT         0x0010
#define DISPLAY_OAM_HBLANK          0x0020
#define DISPLAY_OBJECT_1D_MAPPING   0x0040
#define DISPLAY_FORCE_BLANK         0x0080

#define DISPLAY_LAYER_BG0 0x0100
#define DISPLAY_LAYER_BG1 0x0200
#define DISPLAY_LAYER_BG2 0x0400
#define DISPLAY_LAYER_BG3 0x0800
#define DISPLAY_LAYER_OBJ 0x1000

#define DISPLAY_WINDOW0     0x2000
#define DISPLAY_WINDOW1     0x4000
#define DISPLAY_WINDOW_OBJ  0x8000

// Display Status
// The VCOUNT_TRIGGER is the front 8 bytes of display stat

#define DISPLAY_STAT *((volatile u32*)(MEMORY_IO + 0x0004))

#define STAT_REFRESH_VERTICAL   0x0001
#define STAT_REFRESH_HORIZONTAL 0x0002
#define STAT_VCOUNT_TRIGGERED   0x0004
#define STAT_ENABLE_IRQ_VBLANK  0x0008
#define STAT_ENABLE_IRQ_HBLANK  0x0010
#define STAT_ENABLE_IRQ_VCOUNT  0x0020

// VCount (current y location of the LCD hardware)
// 160 lines of vdraw followed by 68 lines of vblank
#define VCOUNT *((volatile u16*)(MEMORY_IO + 0x0006))

#endif //DISPLAY_CONTROL_H