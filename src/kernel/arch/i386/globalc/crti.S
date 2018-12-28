/* x86 crti.S */
.section .init
.global _init
.type _init, @function
_init:
	push %ebp
	movl %esp, %ebp
	/* GCC crtbegin.o's .init section will be here. */

.section .fini
.global _fini
.type _fini, @function
_fini:
	push %ebp
	movl %esp, %ebp
	/* GCC crtbegin.o's .fini section will be here. */

