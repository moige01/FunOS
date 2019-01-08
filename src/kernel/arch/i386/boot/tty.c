#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include <kernel/tty.h>
#include <string.h>

// See vga.h to view documentation about colors and charsets
#include "vga.h"

static uint16_t* const VGA_MEMORY = (uint16_t*) 0xB8000;
static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;

size_t tty_Row;
size_t tty_Column;
uint8_t tty_Color;
uint16_t* tty_Buffer;

void TTY_Init(void)
{
	tty_Row = 0;
	tty_Column = 0;
	tty_Color = VGA_EntryColor(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
	tty_Buffer = VGA_MEMORY;

	for (size_t y = 0; y < VGA_HEIGHT; y++) {
		for (size_t x = 0; x < VGA_WIDTH; x++) {
			const size_t index = (y * VGA_WIDTH) + x;
			tty_Buffer[index] = VGA_Entry(' ', tty_Color);
		}
	}
}

static void TTY_PutEntryAt(char c, uint8_t color, size_t x, size_t y)
{
	const size_t index = y * VGA_WIDTH + x;
	tty_Buffer[index] = VGA_Entry(c, color);
}

static void TTY_Scroll(void) {
	for (size_t y = 0; y < VGA_HEIGHT; y++) {
		for (size_t x = 0; x < VGA_WIDTH; x++) {
			const size_t index = (y * VGA_WIDTH) + x;
			const size_t new_index = (y + 1) * VGA_WIDTH + x;
			tty_Buffer[index] = tty_Buffer[new_index];
		}
	}

	for (size_t x = 0; x < VGA_WIDTH ; x++)
		TTY_PutEntryAt(' ', tty_Color, x, VGA_HEIGHT-1);

	tty_Row = VGA_HEIGHT - 1;
}

static void TTY_PutChar(char c)
{
	switch(c) {
		case '\n':
			tty_Row++;
			tty_Column = -1;
			break;
		default:
			TTY_PutEntryAt(c, tty_Color, tty_Column, tty_Row);
	}

	if (++tty_Column == VGA_WIDTH) {
		tty_Column = 0;
		if (++tty_Row == VGA_HEIGHT)
			tty_Row = 0;
	}

	if (tty_Row >= VGA_HEIGHT)
		TTY_Scroll();
}

void TTY_Write(const char* data, size_t size)
{
	for (size_t i = 0; i < size; i++)
		TTY_PutChar(data[i]);
}

void TTY_WriteString(const char* data)
{
	TTY_Write(data, strlen(data));
}
