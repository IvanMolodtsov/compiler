#include "include/types/str.h"
#include "string.h"
#include <stdlib.h>

void destroy_str(ptr* pointer) {
    str* s = pointer->to;
    del(s->value);
    free(s);
}

str* new_str(char* value) {
    ptr* pointer = smalloc(sizeof(str), &destroy_str);
    str* string = pointer->to;
    string->self = *pointer;
    size_t length = strlen(value);
    string->value = new_array(length);
    for (int i =0; i< length; ++i) {
        char c = *(value + i);
        arr_set(string->value, i, new_symbol(c));
    }
    return string;
}

bool compare_str(str* s1, str* s2) {
    if (s1->length != s2->length) {
        return false;
    }

    for (int i =0; i< s1->length; ++i) {
        symbol* c1 = arr_get(s1->value, i);
        symbol* c2 = arr_get(s2->value, i);
        if (!compare_symbol(c1,c2)) {
            return false;
        }
    }
    return true;
}