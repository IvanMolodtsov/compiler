#ifndef DEPENDENCY_H
#define DEPENDENCY_H

#include "ptr.h"
#include "array.h"

typedef struct Dependency
{
    ptr self;

    ptr* (*invoke)(array*);
} dependency;

dependency* new_dependency(ptr* (*invoke)(array*));


#endif