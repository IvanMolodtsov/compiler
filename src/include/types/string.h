#ifndef STRING_H
#define STRING_H

#include "symbol.h"
#include "array.h"

typedef struct String {
    any self;
    array* value; 
    size_t length;
} string;

string* new_string(char* value);

bool compare_string(string* one, string* other);

char* toCstringing(string*);

#endif