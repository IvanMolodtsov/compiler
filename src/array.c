#include "include/types/array.h"
#include "stdlib.h"

void destroy_array(ptr* pointer) {
    array* arr =(array*) pointer->to;
    for (size_t i = 0; i < arr->length; ++i) {
        del(arr->body[i]);
    }
    free(arr->body);
    free(arr);
}

array* new_array(size_t size) {
    ptr* pointer = smalloc(sizeof(array), &destroy_array);
    array* arr = pointer->to;
    arr->self = *pointer;
    arr->body = calloc(size, sizeof(ptr*));
    arr->length = size;
    return arr;
}

ptr* arr_get(array* arr,size_t i) {
    return arr->body[i];
}

void arr_set(array* arr,size_t i, ptr* value) {
    del(arr->body[i]);
    arr->body[i] = value;
}