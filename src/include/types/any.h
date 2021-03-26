#ifndef ANY_H 
#define ANY_H

#include <stddef.h>

typedef struct Pointer
{
    void* to;
    void(* destructor)(struct Pointer*);
} any;

any* smalloc(size_t size, void (* destructor)(any*));


void any_set(any*, void*);

void del(any* pointer);

#endif