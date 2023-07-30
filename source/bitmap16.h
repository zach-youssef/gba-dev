#ifndef BITMAP_16_H
#define BITMAP_16_H

#include "basic_types.h"

void bitmap_line(int x0, int y0, 
                 int x1, int y1, 
                 u32 color, 
                 u16* displayBuffer, 
                 u32 displayPitch);

void bitmap_rectangle(int left, int top, int right, int bottom, 
                      u32 color, void* displayBuffer, u32 displayPitch);

void bitmap_frame(int left, int top, int right, int bottom, 
                  u32 color, void* displayBuffer, u32 displayPitch);

#endif