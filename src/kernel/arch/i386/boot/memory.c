#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <arch/i386/boot/boot.h>
#include <funos/kernel.h>
#include <arch/i386/boot/multiboot.h>

/*
* TODO: Parse Multiboot Info Table to Page Fram Allocation.
*/

void MEM_Init(multiboot_info_t* mbi)
{
	if(!(BIT_CHECK(mbi->flags, 6 && BIT_CHECK(mbi->flags, 0)))) goto mem_failure;

	#ifdef DEBUG 
	multiboot_memory_map32_t* mmap;
	mmap = mbi->mmap_addr;

	puts("BIOS Memory:");
	printf("mbi->mem_lower = %d KiB, ", mbi->mem_lower);
	printf("mbi->mem_upper = %d KiB\n", mbi->mem_upper);

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
	#endif

	return;
mem_failure:
	printf("Panic: Multiboot does not contain required sections!\n");
	abort();
}

