#ifndef _STDLIB_H
#define _STDLIB_H

#include <sys/cdefs.h>
#include <stddef.h>
#include <stdint.h>

void itoa(long int, char*, uint8_t, size_t);
__attribute__((__noreturn__)) void abort(void);

#endif
