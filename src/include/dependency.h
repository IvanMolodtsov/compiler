#ifndef DEPENDENCY_H
#define DEPENDENCY_H

#include "ptr.h"

typedef struct Dependency
{
    ptr self;

    ptr* (*invoke)(ptr**);
} dependency;

dependency* new_dependency(ptr* (*invoke)(ptr**));


#endif