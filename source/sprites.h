#ifndef SPRITES_H
#define SPRITES_H

#include "basic_types.h"
#include "memory.h"

typedef struct spriteAttr
{
    u16 attr0;
    u16 attr1;
    u16 attr2;
    u16 fill;
} ALIGN(4) spriteAttr;

typedef struct spriteAffine
{
    u16 fill0[3];
    s16 pa;
    u16 fill1[3];
    s16 pb;
    u16 fill2[3];
    s16 pc;
    u16 fill3[3];
    s16 pd;
} ALIGN(4) spriteAffine;

// Attribute Masks & Offsets
typedef enum SpriteAttr0Masks  {
    MaskY =             0xFF00,
    MaskObjectMode =    0xFCFF,
    MaskGfxMode =       0xF3FF,
    MaskMosaic =        0xEFFF,
    MaskColorMode =     0xDFFF,
    MaskShape =         0x3FFF
} SpriteAttr0Masks;

typedef enum SpriteAttr0Offsets  {
    OffsetY = 0x0,
    OffsetObjectMode = 0x8,
    OffsetGfxMode = 0xA,
    OffsetMosaic = 0xC,
    OffsetColorMode = 0xD,
    OffsetShape = 0xE
} SpriteAttr0Offsets;

typedef enum SpriteAttr1Masks  {
    MaskX =                 0xFE00,
    MaskAffineIndex =       0xC1FF,
    MaskHorizontalFlip =    0xEFFF,
    MaskVerticalFlip =      0xDFFF,
    MaskSize =              0x3FFF
} SpriteAttr1Masks;

typedef enum SpriteAttr1Offsets  {
    OffsetX =                 0x0,
    OffsetAffineIndex =       0x9,
    OffsetHorizontalFlip =    0xC,
    OffsetVerticalFlip =      0xD,
    OffsetSize =              0xE
} SpriteAttr1Offsets;

typedef enum SpriteAttr2Masks  {
    MaskTileIndex = 0xFC00,
    MaskPriority = 0xF3FF,
    MaskPaletteBank = 0x0FFF
} SpriteAttr2Masks;

typedef enum SpriteAttr2Offsets  {
    OffsetTileIndex = 0x0,
    OffsetPriority = 0xA,
    OffsetPaletteBank = 0xC
} SpriteAttr2Offsets;

typedef union SpriteAttrMask {
    SpriteAttr0Masks attr0;
    SpriteAttr1Masks attr1;
    SpriteAttr2Masks attr2;
    int mask;
} SpriteAttrMask;

typedef union SpriteAttrOffset {
    SpriteAttr0Offsets attr0;
    SpriteAttr1Offsets attr1;
    SpriteAttr2Offsets attr2;
    int offset;
} SpriteAttrOffset;

// Attribute 'enums'

typedef enum SpriteObjectMode  {
    ModeNormal = 0b00,
    ModeAffine = 0b01,
    ModeDisabled = 0b10,
    ModeDoubledAffine = 0b11
} SpriteObjectMode;

typedef enum SpriteGfxMode  {
    GfxNormal = 0b00,
    GfxAlpha = 0b01,
    GfxWindow = 0b10
} SpriteGfxMode;

typedef enum SpriteColorMode  {
    ColorMode16 = 0,
    ColorMode256 = 1
} SpriteColorMode;

typedef enum SpriteShape  {
    ShapeSquare = 0b00,
    ShapeWide = 0b01,
    ShapeTall = 0b10
} SpriteShape;

typedef enum SpriteSize  {
    Size8 = 0b00,
    Size16 = 0b01,
    Size32 = 0b10,
    Size64 = 0b11
} SpriteSize;

// Sprite attribute memory
#define SPRITE_ATTRS ((spriteAttr*) MEMORY_OAM)

// Attribute setters
inline void sprite_setAttribute(u16* attr, int value, 
                                SpriteAttrMask mask, 
                                SpriteAttrOffset offset) {
    *attr &= mask.mask;
    *attr |= ((value << offset.offset) & ~mask.mask);
}

inline void sprite_setX(spriteAttr* sprite, int x) {
    SpriteAttrMask mask = {MaskX};
    SpriteAttrOffset offset = {OffsetX};
    sprite_setAttribute(&sprite->attr1, x, mask, offset);
}

inline void sprite_setY(spriteAttr* sprite, int y) {
    SpriteAttrMask mask = {MaskY};
    SpriteAttrOffset offset = {OffsetY};
    sprite_setAttribute(&sprite->attr0, y, mask, offset);
}

inline void sprite_setPalette(spriteAttr* sprite, int paletteIndex) {
    SpriteAttrMask mask = {MaskPaletteBank};
    SpriteAttrOffset offset = {OffsetPaletteBank};
    sprite_setAttribute(&sprite->attr2, paletteIndex, mask, offset);
}

inline void sprite_setTileIndex(spriteAttr* sprite, int tileIndex) {
    SpriteAttrMask mask = {MaskTileIndex};
    SpriteAttrOffset offset = {OffsetTileIndex};
    sprite_setAttribute(&sprite->attr2, tileIndex, mask, offset);
}

#endif