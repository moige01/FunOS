#include <kernel/tty.h>
#include <funos/kernel.h>
#include <arch/i386/boot/boot.h>
#include <arch/i386/boot/multiboot.h>
#include <stdlib.h>
#include <stdio.h>

void Kernel_Early(unsigned long int magic, multiboot_info_t* mbi)
{
	/* Initialize terminal interface */
	TTY_Init();
	puts("TTY initialized!");

	if (magic != MULTIBOOT_BOOTLOADER_MAGIC)
	{
		puts("Invalid magic number\n");
		abort();
	}

	puts("Initializing memory...");
	MEM_Init(mbi);
	puts("Memory initialized!\n");
}

void Kernel_Main(void)
{
	printf("Welcome to: FunOS!\n");
	printf("Version: 0.1.0 Alpha\n");

	for(;;);
}
