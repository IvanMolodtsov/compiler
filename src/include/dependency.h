#ifndef DEPENDENCY_H
#define DEPENDENCY_H

#include "types/any.h"
#include "types/array.h"

typedef struct Dependency
{
    any self;

    any* (*invoke)(array*);
} dependency;

dependency* new_dependency(any* (*invoke)(array*));


#endif