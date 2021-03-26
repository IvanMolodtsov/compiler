#include "include/types/string.h"
#include <string.h>
#include <stdlib.h>

void destory_string(any* pointer) {
    string* s = pointer->to;
    del(s->value);
    free(s);
}

string* new_string(char* value) {
    any* pointer = smalloc(sizeof(string), &destory_string);
    string* stringing = pointer->to;
    stringing->self = *pointer;
    size_t length = strlen(value);
    stringing->value = new_array(length);
    for (int i =0; i< length; ++i) {
        char c = value[i];
        arr_set(stringing->value, i, new_symbol(c));
    }
    return stringing;
}

bool compare_string(string* s1, string* s2) {
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