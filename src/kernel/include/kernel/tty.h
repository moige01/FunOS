#ifndef _KERNEL_TTY_H
#define _KERNEL_TTY_H

#include <stddef.h>

void TTY_Init(void);
void TTY_WriteString(const char*);
void TTY_Write(const char*, size_t);

#endif
