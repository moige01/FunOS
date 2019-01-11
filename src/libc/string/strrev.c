#include <string.h>
#include <stddef.h>

void strrev(char* str)
{
	register int i;
	register int j;
	unsigned char a;
	size_t len = strlen((const char*) str);

	for (i = 0, j = len - 1; i < j; i++, j--) {
		a = str[i];
		str[i] = str[j];
		str[j] = a;
	}
}
