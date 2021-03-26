#include "include/types/any.h"
#include "stdlib.h"

void destory(any* pointer) {
    free(pointer->to);
    free(pointer);
}

any* smalloc(size_t size, void (* destructor)(any*)) {
    void* mem = malloc(size);
    if (mem == NULL) {
        return NULL;
    }

    any* pointer = malloc(sizeof(any));
    if (pointer == NULL) {
        free(mem);
        return NULL;
    }

    if (destructor == NULL) {
        pointer->destructor = &destory;
    }  else {
        pointer->destructor = destructor;
    }

    pointer->to = mem;
    return pointer;
}

void del(any* pointer) {
    if (pointer != NULL) {
        pointer->destructor(pointer);
    }
}