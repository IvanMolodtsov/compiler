#ifndef ARRAY_H 
#define ARRAY_H

#include "any.h"

typedef struct Array
{
    any self;
    any** body;
    size_t length;
} array;

array* new_array(size_t size);
any* arr_get(array* arr,size_t i);
void arr_set(array* arr,size_t i, any* value);

#endif