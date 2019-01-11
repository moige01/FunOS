#include <kernel/tty.h>
#include <funos/kernel.h>
#include <boot/boot.h>
#include <boot/multiboot.h>
#include <stdlib.h>
#include <stdio.h>

void Kernel_Main(unsigned long int magic, multiboot_info_t* mbi)
{
	/* Initialize terminal interface */
	TTY_Init();

	//TODO: Move all of memory stuff to memory.c
	// Plan to implement SMAP_DetectMemory() call in boot.S
	if (magic != MULTIBOOT_BOOTLOADER_MAGIC)
	{
		puts("Invalid magic number\n");
		abort();
	}
	multiboot_memory_map32_t* mmap;
	mmap = mbi->mmap_addr; 

	puts("Hello, Kernel World!");
	puts("Detecting SMAP...\n");

	if (BIT_CHECK(mbi->flags, 0)) {
		puts("BIOS Memory:");
		printf("mbi->mem_lower = %d KiB, ", mbi->mem_lower);
		printf("mbi->mem_upper = %d KiB\n", mbi->mem_upper);
	}

	if (BIT_CHECK(mbi->flags, 6)) {
		puts("\nMemory Map:");
		printf("mbi->mmap_addr = 0x%x, ", mbi->mmap_addr);
		printf("mbi->mmap_len = 0x%x\n \n", mbi->mmap_length);

		while (mmap < mbi->mmap_addr + mbi->mmap_length) {
			printf("mmap->addr_high 0x%x, ", mmap->addr_high);
			printf("mmap->addr_low 0x%x, ", mmap->addr_low);
			printf("mmap->len_high 0x%x, ", mmap->len_high);
			printf("mmap->len_low 0x%x, ", mmap->len_low);
			printf("mmap->type 0x%x\n", mmap->type);

			mmap = (multiboot_memory_map32_t*) ((unsigned int) mmap + mmap->size + sizeof(mmap->size));
		}
	}

	puts("\nNow, keep reading and implement more!\n");
}
