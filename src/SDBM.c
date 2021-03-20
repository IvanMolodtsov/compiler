#include "include/SDBM.h"

unsigned int SDBMHash(char* str, unsigned int length) {
	unsigned int hash = 0;
	unsigned int i = 0;

	for (i = 0; i < length; str++, i++)
	{
		hash = (*str) + (hash << 6) + (hash << 16) - hash;
	}

	return hash;
}