#include "include/object.h"
#include "include/SDBM.h"
#include "stdlib.h"

size_t hash(char* key, size_t size) {
    size_t len = strlen(key);
    unsigned int hash = SDBMHash(key, len);
    return hash % size;
}

void destroy_obj(ptr* pointer) {

    obj* o =(obj*) pointer->to;
    
    char * k;
    for (int i =0; i<o->size ; ++i) {
        field* f = o->fields[i];
        field* next;
        while (f != NULL) {
            free(f->key);
            k = f->key;
            next = f->next;
            del(f->data);
            free(f);
            f=next;
        }
    }
    printf("%s\n", k);
    free(o->fields);
    free(o);
}

obj* object(size_t size) {
    field** fields = calloc(size, sizeof(field*));
    if (fields == NULL) {
        return NULL;
    }

    ptr * pointer = smalloc(sizeof(obj),&destroy_obj);
    obj* newObject = pointer->to;

    if (newObject == NULL) {
        free(fields);
        return NULL;
    }

    newObject->self = *pointer;
    newObject->fields = fields;
    newObject->size = size;
}

field* newField(char* key,ptr* data ) {
    field* f = malloc(sizeof(field));
    if (f == NULL) {
        return NULL;
    }
    f->key = malloc(strlen(key)+1);
    strcpy( f->key,key);

    f->data = data;
    f->next = NULL;
    return f;
}

ptr* get(obj* table, char* key) {
    size_t i = hash(key, table->size);
    field* val = table->fields[i];
    if (val == NULL) {
        return NULL;
    }

    while(val != NULL) {
        if (strcmp(val->key, key) == 0) {
            return val->data;
        }
        val = val->next;
    }

    return NULL;
    
}

void set(obj* table, char* key, ptr* value) {
    size_t i = hash(key, table->size);
    field* val = table->fields[i];
    if (val == NULL) {
        table->fields[i] = newField(key, value);
        return;
    }

    field* prev;

    while(val != NULL) {
        if (strcmp(val->key, key) == 0) {
            val->data = value;
            return;
        }
        prev = val;
        val = prev->next;
    }

    prev->next = newField(key, value);
}