#include "include/str.h"
#include "string.h"
#include <stdlib.h>

void destroy_str(ptr* pointer) {
    str* s = pointer->to;
    free(s->value);
    free(s);
}

str* new_str(char* value) {
    ptr* pointer = smalloc(sizeof(str), &destroy_str);
    str* string = pointer->to;
    string->self = *pointer;
    size_t length = strlen(value);
    string->value = malloc(sizeof(char)*(length+1));
    strcpy(string->value, value);
    return string;
}

bool compare_str(str* one, str* other) {
    if (one->length != other->length) {
        return false;
    }
    if (strcmp(one->value, other->value)==0) {
        return true;
    } else {
        return false;
    }
}