#include "include/array.h"

void destroy_array(ptr* pointer) {
    array* arr =(array*) pointer->to;
    for (size_t i = 0; i < arr->length; ++i) {
        del(arr->body[i]);
    }
    free(arr->body);
    free(arr);
}

array* newArray(size_t size) {
    ptr* pointer = smalloc(sizeof(array), &destroy_array);
    array* arr = pointer->to;
    arr->self = *pointer;
    arr->body = calloc(size, sizeof(ptr*));
    arr->length = size;
    return arr;
}