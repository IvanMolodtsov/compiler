#ifndef OBJECT_H 
#define OBJECT_H

#include "ptr.h"
#include "array.h"
#include "str.h"

size_t hash(str* key, size_t size);

#define default_size 7919;

typedef struct Field
{
    ptr self;
    ptr* data;
    str* key;
    struct Field* next;
} field;

field* new_field(str* key,ptr* data );

typedef struct Object
{
    ptr self;
    size_t size;
    array* fields;
} object;

object* new_object(size_t size);

ptr* get(object* table, str* key);
void set(object* table, str* key, ptr* value);

#endif