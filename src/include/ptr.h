#ifndef PTR_H 
#define PTR_H

#include <stddef.h>

typedef struct Pointer
{
    void* to;
    size_t size;
    void(* destructor)(struct Pointer*);
} ptr;

ptr* smalloc(size_t size, void (* destructor)(ptr*));

void ptr_set(ptr*, void*);

void del(ptr* pointer);

#endif