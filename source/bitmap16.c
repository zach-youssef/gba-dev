#include "bitmap16.h"
#include <stdlib.h>

void bitmap_line(int x0, int y0, 
                 int x1, int y1, 
                 u32 color, 
                 u16* displayBuffer, 
                 u32 displayPitch) {

    int dx = x1 - x0;
    int dy = y1 - y0;

    int i, dd;

    u16* dst = displayBuffer + y0*displayPitch + x0*2;
    displayPitch /= 2;

    int yDir = (y1 - y0) / abs(y1 - y0);
    int xDir = (x1 - x0) / abs(x1 - x0);

    if  (!dy) {
        for(i = 0; i <= dx; ++i) {
            dst[i * xDir] = color;
        }
    } else if (!dx) {
        for(i = 0; i <= dy; ++i) {
            dst[i * displayPitch * yDir] = color;
        }
    } else if (dx >=dy) {
        dd = 2 * dy - dx;
        for (i = 0; i <=dx; ++i) {
            *dst = color;
            if (dd >= 0) {
                dd -= 2*dx; 
                dst += displayPitch * yDir;
            }
            dd += 2 * dy;
            dst += xDir;
        }
    } else {
        dd = 2 * dx - dy;
        for (i = 0; i <=dy; ++i) {
            *dst = color;
            if (dd >= 0) {
                dd -= 2*dy; 
                dst += xDir;
            }
            dd += 2 * dx;
            dst+= displayPitch * yDir;
        }
    }

}

void bitmap_rectangle(int left, int top, int right, int bottom, 
                      u32 color, void* displayBuffer, u32 displayPitch) {}

void bitmap_frame(int left, int top, int right, int bottom, 
                  u32 color, void* displayBuffer, u32 displayPitch) {}