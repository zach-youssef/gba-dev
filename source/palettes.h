#ifndef PALETTES_H
#define PALETTES_H

#include "basic_types.h"
#include "memory.h"

typedef struct { rgb15 colors[16]; } Palette;

#define PALETTES_BG ((Palette*) MEMORY_PALETTE)
#define PALETTES_OBJ ((Palette*) (MEMORY_PALETTE + 0x200))

#endif