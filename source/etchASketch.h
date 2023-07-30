#ifndef ETCH_A_SKETCH_H
#define ETCH_A_SKETCH_H

#include "basic_types.h"
#include "sprites.h"
#include "mode3.h"

#define ETCH_A_SKETCH_NUM_PAINT_COLORS 6
#define ETCH_A_SKETCH_ERASER_SIZE 4

typedef struct EtchASketchState {
    int x;
    int y;

    rgb15 backgroundColor;

    rgb15 paintColors[ETCH_A_SKETCH_NUM_PAINT_COLORS];
    int paintColorIndex;
    
    int cursorPaletteIndex;

    spriteAttr* cursorSprite;

    bool initialized;
} EtchASketchState;

inline EtchASketchState getDefaultEtchASketchState() {
    EtchASketchState state;

	state.x = M3_WIDTH / 2;
	state.y = M3_HEIGHT / 2;
    state.paintColorIndex = 0;

	state.backgroundColor = RGB(15, 15, 15); // Grey

	state.paintColors[0] = RGB(31, 0, 31); 	// Purple
	state.paintColors[1] = RGB(31, 0, 0); 	// Red
	state.paintColors[2] = RGB(31, 31, 0); 	// Yellow
	state.paintColors[3] = RGB(0, 31, 0); 	// Green
	state.paintColors[4] = RGB(0, 31, 31); 	// Cyan
	state.paintColors[5] = RGB(0, 0, 31); 	// Blue

    state.cursorPaletteIndex = 0;
    state.cursorSprite = &SPRITE_ATTRS[0];

    state.initialized = false;
    
    return state;
}

void etchASketchFrame(EtchASketchState* state);

#endif