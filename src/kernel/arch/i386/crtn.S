/* x86 crtn.S */
.section .init
	/* GCC crtend.o .init section will be here. */
	popl %ebp
	ret

.section .fini
	/* GCC crtend.o .fini section will be here. */
	popl %ebp
	ret
