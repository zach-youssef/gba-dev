#include "etchASketch.h"
#include "mode3.h"
#include "keys.h"
#include "tiles.h"
#include "palettes.h"

const u32 cursorSpriteData[8] = {
    0x00011000,
    0x00011000,
    0x00011000,
    0x11122111,
    0x11122111,
    0x00011000,
    0x00011000,
    0x00011000
};

Palette* getCursorPalette(EtchASketchState* state) {
    return &PALETTES_OBJ[state->cursorPaletteIndex];
}

void etchASketch_init(EtchASketchState* state) {
	// Clear the background
	mode3_fill(state->backgroundColor);

    // Set up our cursor palette
    getCursorPalette(state)->colors[1] = RGB(0,0,0);
    getCursorPalette(state)->colors[2] = state->paintColors[state->paintColorIndex];

    // Set up our cursor sprite
    tile_mem[CHARBLOCK_OBJ_1][0] = *(Tile*) cursorSpriteData;
    sprite_setTileIndex(state->cursorSprite, 512);
    sprite_setPalette(state->cursorSprite, state->cursorPaletteIndex);

    state->initialized = true;
}

void updateCursorPosition(EtchASketchState* state) {
    // Movement keys
    if (key_is_down(KEY_RIGHT)) {
        state->x = (state->x + 1) % M3_WIDTH;
    } 
    else if (key_is_down(KEY_LEFT)) {
        state->x = state->x ? (state->x - 1) : M3_WIDTH;
    }

    if (key_is_down(KEY_DOWN)) {
        state->y = (state->y + 1) % M3_HEIGHT;
    } else if (key_is_down(KEY_UP)) {
        state->y = state->y ? (state->y - 1) : M3_HEIGHT;
    }

    // Set cursor position
    sprite_setX(state->cursorSprite, state->x - 4);
    sprite_setY(state->cursorSprite, state->y - 4);
}

void applyPaint(EtchASketchState* state) {
    // Holding A draws the color
    if (key_is_down(KEY_A)) {
        mode3_plot(state->x, state->y, state->paintColors[state->paintColorIndex]);
    }
}

void selectPaintColor(EtchASketchState* state) { 
    // Select changes the paint color
    if (key_pressed(KEY_SELECT)) {
        state->paintColorIndex = (state->paintColorIndex + 1) % ETCH_A_SKETCH_NUM_PAINT_COLORS;
        getCursorPalette(state)->colors[2] = state->paintColors[state->paintColorIndex];
    }
}

void applyEraserState(EtchASketchState* state) {
    // Holding B activates the eraser
    if (key_is_down(KEY_B)) {
        for (int ix = -ETCH_A_SKETCH_ERASER_SIZE/2; ix <= ETCH_A_SKETCH_ERASER_SIZE/2; ++ix) {
            for (int iy = -ETCH_A_SKETCH_ERASER_SIZE/2; iy <= ETCH_A_SKETCH_ERASER_SIZE/2; ++iy) {
                mode3_plot(state->x + ix, state->y + iy, state->backgroundColor);
            }
        }
    }
    if (key_pressed(KEY_B)) {
        getCursorPalette(state)->colors[2] = state->backgroundColor;
    }
    if (key_released(KEY_B)) {
        getCursorPalette(state)->colors[2] = state->paintColors[state->paintColorIndex];
    }
}

void applyReset(EtchASketchState* state) {
    // Start clears the screen
    if (key_pressed(KEY_START)) {
        mode3_fill(state->backgroundColor);
    }
}

void etchASketchFrame(EtchASketchState* state) {
    if (!state->initialized){
        etchASketch_init(state);
    }

    applyReset(state);
    updateCursorPosition(state);
    selectPaintColor(state);
    applyPaint(state);
    applyEraserState(state);
}