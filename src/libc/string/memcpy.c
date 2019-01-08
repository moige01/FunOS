#include <string.h>

void* memcpy(void* restrict dstptr, const void* restrict srcptr, size_t size)
{
	unsigned char* dst = (unsigned char*) dstptr;
	const unsigned char* src = (const unsigned char*) srcptr;
	register size_t i;

	for (i = 0; i < size; i++)
		dst[i] = src[i];

	return dstptr;
}
