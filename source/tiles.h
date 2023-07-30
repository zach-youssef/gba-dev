#ifndef TILES_H
#define TILES_H

#include "basic_types.h"
#include "memory.h"

typedef struct { u32 data[8]; } Tile;
typedef Tile Charblock[512];

#define CHARBLOCK_BG_0  0
#define CHARBLOCK_BG_1  1
#define CHARBLOCK_BG_2  2
#define CHARBLOCK_BG_3  3
#define CHARBLOCK_OBJ_0 4
#define CHARBLOCK_OBJ_1 5

#define tile_mem ((Charblock*) MEMORY_VRAM)

#endif