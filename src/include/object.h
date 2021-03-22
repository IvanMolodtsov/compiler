#ifndef OBJECT_H 
#define OBJECT_H

#include "ptr.h"
#include "array.h"

size_t hash(char* key, size_t size);

typedef struct Field
{
    ptr self;
    ptr* data;
    char* key;
    struct Field* next;
} field;

field* new_field(char* key,ptr* data );

typedef struct Object
{
    ptr self;
    size_t size;
    array* fields;
} object;

object* new_object(size_t size);

ptr* get(object* table, char* key);
void set(object* table, char* key, ptr* value);

#endif