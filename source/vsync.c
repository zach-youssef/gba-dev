#include "vsync.h"
#include "display_control.h"

void vsync() {
    while(VCOUNT >= 160); // Wait til VDraw
    while(VCOUNT < 160); // Wait till VBlank
}