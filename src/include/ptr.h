#ifndef PTR_H 
#define PTR_H

#include "stdlib.h"

typedef struct Pointer
{
    void* to;
    size_t size;
    void(* destructor)(struct Pointer*);
} ptr;

ptr* smalloc(size_t size, void (* destructor)(ptr*));

void del(ptr* pointer);

#endif