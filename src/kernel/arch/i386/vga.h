#ifndef ARCH_I386_VGA_H
#define ARCH_I386_VGA_H

#include <stdint.h>

enum VGA_Color {
	VGA_COLOR_BLACK,
	VGA_COLOR_BLUE,
	VGA_COLOR_GREEN,
	VGA_COLOR_CYAN,
	VGA_COLOR_RED,
	VGA_COLOR_MAGENTA,
	VGA_COLOR_BROWN,
	VGA_COLOR_LIGHT_GREY,
	VGA_COLOR_DARK_GREY,
	VGA_COLOR_LIGHT_BLUE,
	VGA_COLOR_LIGHT_GREEN,
	VGA_COLOR_LIGHT_CYAN,
	VGA_COLOR_LIGHT_RED,
	VGA_COLOR_LIGHT_MAGENTA,
	VGA_COLOR_LIGHT_BROWN,
	VGA_COLOR_WHITE,
};

/**
This function declare the background and charset colors.
Each Character are 16-bits length. The low byte de fine the character,
and the high byte define other aspects like color, and blink.
TODO: Add explication of what is happening and why
@param: fg -> enum VGA_Color: Character color
@param: bg -> enum VGA_Color: Background color
**/
static inline uint8_t VGA_EntryColor(enum VGA_Color fg, enum VGA_Color bg)
{
	return fg | bg << 4;
}

/**
Put character into VGA text framebuffer.
TODO: Add explication of what is happening and why

@param: uc -> char: Character to enter
@param color -> uint8_t: Color to assign. This is the return of "VGA_EntryColor" function
@return: void
**/
static inline uint16_t VGA_Entry(unsigned char uc, uint8_t color)
{
	return (uint16_t) uc | (uint16_t) color << 8;
}

#endif
