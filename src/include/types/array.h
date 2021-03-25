#ifndef ARRAY_H 
#define ARRAY_H

#include "ptr.h"

typedef struct Array
{
    ptr self;
    ptr** body;
    size_t length;
} array;

array* new_array(size_t size);
ptr* arr_get(array* arr,size_t i);
void arr_set(array* arr,size_t i, ptr* value);

#endif