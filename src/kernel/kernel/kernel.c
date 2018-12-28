#include <kernel/tty.h>
#include <boot/boot.h>
#include <boot/multiboot.h>

void Kernel_Main(unsigned long magic, unsigned long addr)
{
	/* Initialize terminal interface */
	TTY_Init();

	//TODO: Move all of memory stuff to memory.c
	// Plan to implement SMAP_DetectMemory() call in boot.S
	if (magic != MULTIBOOT_BOOTLOADER_MAGIC)
	{
		TTY_WriteString("Invalid magic number");
		return;
	}
	
	TTY_WriteString("Hello, Kernel World!\n");
	TTY_WriteString("Detecting SMAP...\n");
	multiboot_info_t *mbi;
	mbi = (multiboot_info_t *) addr;

	TTY_WriteString("Now, keep reading and implement more!\n");
}
