#ifndef OBJECT_H 
#define OBJECT_H

#include "stdlib.h"
#include "string.h"
#include "ptr.h"

size_t hash(char* key, size_t size);

typedef struct Field
{
    ptr* data;
    char* key;
    struct Field* next;
} field;

field* newField(char* key,ptr* data );

typedef struct Object
{
    size_t size;
    field** fields;
} obj;

obj* object(size_t size);

ptr* get(obj* table, char* key);
void set(obj* table, char* key, ptr* value);

#endif