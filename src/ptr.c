#include "include/ptr.h"


ptr* smalloc(size_t size) {
    void* mem = malloc(size);
    if (mem == NULL) {
        return NULL;
    }

    ptr* pointer = malloc(sizeof(ptr));
    if (pointer == NULL) {
        free(mem);
        return NULL;
    }

    pointer->to = mem;
    pointer->size = size;
    return pointer;
}

void del(ptr* pointer) {
    free(pointer->to);
    free(pointer);
}