#include <kernel/tty.h>

void Kernel_Main(void)
{
	/* Initialize terminal interface */
	TTY_Init();
	TTY_WriteString("Hello, asd World!\n");
	TTY_WriteString("Now, keep reading and implement more!\n");
}
