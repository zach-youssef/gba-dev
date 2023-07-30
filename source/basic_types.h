#ifndef BASIC_TYPES_H
#define BASIC_TYPES_H

#define ALIGN(n)    __attribute__((aligned(n)))

typedef enum bool {
	false = 0,
	true = 1,
} bool;

typedef unsigned char 	u8;
typedef unsigned short 	u16;
typedef unsigned int 	u32;

typedef signed short s16;

typedef u16 rgb15;

inline rgb15 RGB(u32 red, u32 green, u32 blue) {
	return red | (green << 5) | (blue << 10);
}

#endif //BASIC_TYPES_H