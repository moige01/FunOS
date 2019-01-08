#include <stdio.h>

#include <kernel/tty.h>

int putchar(int ic) {
	char c = (char) ic;
	TTY_Write(&c, sizeof(c));

	return ic;
}
