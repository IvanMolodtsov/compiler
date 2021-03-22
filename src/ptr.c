#include "include/ptr.h"
#include "stdlib.h"
#include "string.h"

void destroy(ptr* pointer) {
    free(pointer->to);
    free(pointer);
}

ptr* smalloc(size_t size, void (* destructor)(ptr*)) {
    void* mem = malloc(size);
    if (mem == NULL) {
        return NULL;
    }

    ptr* pointer = malloc(sizeof(ptr));
    if (pointer == NULL) {
        free(mem);
        return NULL;
    }

    if (destructor == NULL) {
        pointer->destructor = &destroy;
    }  else {
        pointer->destructor = destructor;
    }

    pointer->to = mem;
    pointer->size = size;
    
    return pointer;
}

void ptr_set(ptr* pointer, void* value) {
    memcpy(pointer->to, value, pointer->size);
}

void del(ptr* pointer) {
    if (pointer != NULL) {
        pointer->destructor(pointer);
    }
}