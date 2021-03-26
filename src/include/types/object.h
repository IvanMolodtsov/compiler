#ifndef OBJECT_H 
#define OBJECT_H

#include "any.h"
#include "array.h"
#include "string.h"

size_t hash(string* key, size_t size);

#define default_size 7919;

typedef struct Field
{
    any self;
    any* data;
    string* key;
    struct Field* next;
} field;

field* new_field(string* key,any* data );

typedef struct Object
{
    any self;
    size_t size;
    array* fields;
} object;

object* new_object(size_t size);

any* get(object* table, string* key);
void set(object* table, string* key, any* value);

#endif