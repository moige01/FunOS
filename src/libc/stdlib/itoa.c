#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

void itoa(long int num, char* str, uint8_t base, size_t len)
{
	register unsigned int i = 0;
	long int digit;
	bool is_signed = false;

	if (num < 0) {
		num = -num;
		is_signed = true;
	}

	do {
		digit = num % base;

		if (digit < 0xA)
			str[i++] = '0' + digit;
		else
			str[i++] = 'A' + digit - 0xA;

		num /= base;
	} while (num && (i < (len - 1)));

	if (is_signed)
		str[i++] = '-';
	
	str[i] = '\0';
	strrev(str);
}
