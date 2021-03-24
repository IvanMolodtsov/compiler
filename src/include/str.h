#ifndef STR_H
#define STR_H

#include "ptr.h"
#include "stdbool.h"

typedef struct String {
    ptr self;
    char* value; 
    size_t length;
} str;

str* new_str(char* value);

bool compare_str(str* one, str* other);

#endif