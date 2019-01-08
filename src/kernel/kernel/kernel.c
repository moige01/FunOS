#include <kernel/tty.h>
#include <boot/boot.h>
#include <boot/multiboot.h>
#include <stdio.h>

void Kernel_Main(unsigned long magic, unsigned long addr)
{
	/* Initialize terminal interface */
	TTY_Init();

	//TODO: Move all of memory stuff to memory.c
	// Plan to implement SMAP_DetectMemory() call in boot.S
	if (magic != MULTIBOOT_BOOTLOADER_MAGIC)
	{
		printf("Invalid magic number\n");
		return;
	}
	
	printf("Hello, Kernel World!\n");
	printf("Detecting SMAP...\n");
	multiboot_info_t *mbi;
	mbi = (multiboot_info_t *) addr;
	printf("mem_low -> %c\n", mbi->mem_lower);

	printf("Now, keep reading and implement more!\n");
}
