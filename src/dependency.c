#include "include/dependency.h"
#include "stdlib.h"

void destruct_dependency(ptr* pointer) {
    dependency* d = (dependency*) pointer;
    free(d->invoke);
    free(d);
}

dependency* new_dependency(ptr* (*invoke)(array*)) {
    ptr* pointer = smalloc(sizeof(dependency), &destruct_dependency);
    dependency* d = pointer->to;
    d->self = *pointer;
    d->invoke = invoke;
    return d;
}