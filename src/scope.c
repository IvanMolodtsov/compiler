#include "include/scope.h"

void destroy_scope(ptr* pointer) {
    scope* s = (scope*)pointer;

    del(s->dictionary);
    free(s);
}

scope* new_scope(scope* parent) {
    ptr* pointer = smalloc(sizeof(scope), &destroy_scope);
    scope* s = pointer->to;
    s->self = *pointer;
    s->parent = parent;
    s->dictionary = new_object(NULL);
    return s;
}

dependency* get_dependency(scope* s, str * key) {
    scope* current = s;
    while (current != NULL) {
        ptr* p = get( current->dictionary, key);
        if (p!= NULL) {
            return (dependency*) p;
        }
        current = current->parent;
    }
    return NULL;
}

void set_dependency(scope* s, str * key, dependency* d) {
    set(s->dictionary, key, d);
}