#include "include/SDBM.h"


unsigned int SDBMHash(string* stringing, unsigned int length) {
	unsigned int hash = 0;
	unsigned int i = 0;

	for (i = 0; i < length; i++)
	{
		symbol* s = arr_get(stringing->value, i);
		hash = (s->symbol) + (hash << 6) + (hash << 16) - hash;
	}

	return hash;
}