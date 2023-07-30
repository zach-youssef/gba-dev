#include "mode3.h"
#include "bitmap16.h"

void mode3_line(int x0, int y0, int x1, int y1, rgb15 color) {
    bitmap_line(x0, y0, x1, y1, color, vram, M3_WIDTH * 2);
}

void mode3_fill(rgb15 color) {
    for (int x = 0; x < M3_WIDTH; ++x) {
        for (int y = 0; y < M3_HEIGHT; ++y) {
            mode3_plot(x, y, color);
        }
    }
}