#include <stdio.h>

/* Header containing helper macros or definitions */

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))
#define MIN(x, y) (((x) < (y) ? (x) : (y))
#define MAX(x, y) (((x) > (y) ? (x) : (y))

/* Bit check, set, clear and toggle */

#define BIT_SET(a, b) ((a) |= (1UL << (b)))
#define BIT_CLEAR(a, b) ((a) &= ~(1UL << (b)))
#define BIT_TOGGLE(a, b) ((a) ^= (1UL << (b)))
#define BIT_CHECK(a, b) (!!(((a) >> (b)) & 1UL))

/* Debug macros */

#define ASSERT(x)			\
	do { 				\
		if(!(x)) {		\
			printf("ASSERT failed: %s at %s:%d\n", #x, __FILE__, __LINE__); \
			abort();	\
		}			\
	} while (0)

#define PANIC(reason)			\
	do {				\
		printf("PANIC: %s at %s:%d\n", reason, __FILE__, __LINE__); \
		abort();		\
	} while (0)

