#include "include/ptr.h"


ptr* smalloc(size_t size) {
    void* mem = malloc(size);
    if (mem == NULL) {
        return;
    }

    ptr* pointer = malloc(sizeof(ptr));
    if (pointer == NULL) {
        free(mem);
        return;
    }

    pointer->to = mem;
    pointer->size = size;
    return pointer;
}

void del(ptr* pointer) {
    free(pointer->to);
    free(pointer);
}