#ifndef SCOPE_H 
#define SCOPE_H

#include "ptr.h"
#include "dependency.h"
#include "object.h"

typedef struct Scope {
    ptr self;
    object* dictionary;
    struct Scope *parent;
} scope;

scope* new_scope(scope* parent);

dependency* get_dependency(scope* s, char * key);
void set_dependency(scope* s, char * key, dependency* d);

#endif