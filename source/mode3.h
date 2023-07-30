#ifndef MODE_3_H
#define MODE_3_H

#include "display_control.h"
#include "basic_types.h"

#define vram ((u16*)MEMORY_VRAM)
#define M3_WIDTH 	240
#define M3_HEIGHT 	160

inline void mode3_plot(int x, int y, rgb15 color) {
	vram[y*M3_WIDTH + x] = color;
}

void mode3_line(int x0, int y0, int x1, int y1, rgb15 color);

void mode3_fill(rgb15 color);

#endif