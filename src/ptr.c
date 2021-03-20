#include "include/ptr.h"

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

void del(ptr* pointer) {
    pointer->destructor(pointer);
}