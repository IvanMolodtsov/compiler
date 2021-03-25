#ifndef STR_H
#define STR_H

#include "symbol.h"
#include "array.h"

typedef struct String {
    ptr self;
    array* value; 
    size_t length;
} str;

str* new_str(char* value);

bool compare_str(str* one, str* other);

#endif