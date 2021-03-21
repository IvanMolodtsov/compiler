#ifndef ARRAY_H 
#define ARRAY_H

#include "ptr.h"

typedef struct Array
{
    ptr self;
    ptr** body;
    size_t length;
} array;

array* newArray(size_t size);
ptr* get(array* arr,size_t i);
void set(array* arr,size_t i, ptr* value);

#endif