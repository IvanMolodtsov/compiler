#ifndef SCOPE_H 
#define SCOPE_H

#include "types/ptr.h"
#include "dependency.h"
#include "types/object.h"
#include "types/str.h"

typedef struct Scope {
    ptr self;
    object* dictionary;
    struct Scope *parent;
} scope;

scope* new_scope(scope* parent);

dependency* get_dependency(scope* s, str * key);
void set_dependency(scope* s, str * key, dependency* d);

#endif