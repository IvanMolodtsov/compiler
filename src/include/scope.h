#ifndef SCOPE_H 
#define SCOPE_H

#include "types/any.h"
#include "dependency.h"
#include "types/object.h"
#include "types/string.h"

typedef struct Scope {
    any self;
    object* dictionary;
    struct Scope *parent;
} scope;

scope* new_scope(scope* parent);

dependency* get_dependency(scope* s, string * key);
void set_dependency(scope* s, string * key, dependency* d);

#endif