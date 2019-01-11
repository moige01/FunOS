#include <string.h>
#include <stddef.h>

size_t strlen(const char* str)
{
	const char* sc;

	for (sc = str; *sc; ++sc)
		;

	return (sc - str);
}
