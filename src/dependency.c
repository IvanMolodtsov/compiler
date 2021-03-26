#include "include/dependency.h"
#include "stdlib.h"

void destruct_dependency(any* pointer) {
    dependency* d = (dependency*) pointer;
    free(d->invoke);
    free(d);
}

dependency* new_dependency(any* (*invoke)(array*)) {
    any* pointer = smalloc(sizeof(dependency), &destruct_dependency);
    dependency* d = pointer->to;
    d->self = *pointer;
    d->invoke = invoke;
    return d;
}