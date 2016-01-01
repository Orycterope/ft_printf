#include "utf.h"

long long convert_utf(wint_t arg) //long long suffisant ?
{
	unsigned char power;
	int rang;
	unsigned long long out;

	if (arg <= 0x7F)
		return (arg);
	power = 0x3F;
	rang = 0;
	out = 0;
	while (arg > (wint_t)power)
	{
		out += (long long)((arg & 0x3F) | 0x80) << (rang++ * 8);
		power /= 2;
		arg >>= 6;
	}
	out += (long long)((unsigned char)(~power << 1) | arg) << (rang * 8);
	return (out);
}
