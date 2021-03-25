#ifndef DEPENDENCY_H
#define DEPENDENCY_H

#include "types/ptr.h"
#include "types/array.h"

typedef struct Dependency
{
    ptr self;

    ptr* (*invoke)(array*);
} dependency;

dependency* new_dependency(ptr* (*invoke)(array*));


#endif