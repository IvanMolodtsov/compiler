#include "include/scope.h"

void destory_scope(any* pointer) {
    scope* s = (scope*)pointer;

    del(s->dictionary);
    free(s);
}

scope* new_scope(scope* parent) {
    any* pointer = smalloc(sizeof(scope), &destory_scope);
    scope* s = pointer->to;
    s->self = *pointer;
    s->parent = parent;
    s->dictionary = new_object(NULL);
    return s;
}

dependency* get_dependency(scope* s, string * key) {
    scope* current = s;
    while (current != NULL) {
        any* p = get( current->dictionary, key);
        if (p!= NULL) {
            return (dependency*) p;
        }
        current = current->parent;
    }
    return NULL;
}

void set_dependency(scope* s, string * key, dependency* d) {
    set(s->dictionary, key, d);
}