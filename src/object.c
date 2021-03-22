#include "include/object.h"
#include "include/SDBM.h"
#include "stdlib.h"
#include "string.h"

size_t hash(char* key, size_t size) {
    size_t len = strlen(key);
    unsigned int hash = SDBMHash(key, len);
    return hash % size;
}

void destroy_field(ptr* pointer) {
    field* next;
    field* f =(field*) pointer->to;
    while (f != NULL) {
        next = f->next;
        free(f->key);
        del(f->data);
        free(f);
        f=next;
    }
}

void destroy_obj(ptr* pointer) {

    object* o =(object*) pointer->to;
    
    del (o->fields);
    free(o);
}

object* new_object(size_t size) {

    size_t s;

    if (size == NULL) {
        s = default_size;
    } else {
        s = size;
    }

    field** fields = new_array(s);
    if (fields == NULL) {
        return NULL;
    }

    ptr * pointer = smalloc(sizeof(object),&destroy_obj);
    
    if (pointer == NULL) {
        del(fields);
        return NULL;
    }
    
    object* newObject = pointer->to;
    newObject->self = *pointer;
    newObject->fields = fields;
    newObject->size = s;
}

field* new_field(char* key,ptr* data ) {
    ptr* p = smalloc(sizeof(field), &destroy_field);
    if (p == NULL) {
        return NULL;
    }
    field* f = p->to;
    f->self = *p;
    f->key = malloc(strlen(key)+1);
    strcpy( f->key,key);

    f->data = data;
    f->next = NULL;
    return f;
}

ptr* get(object* table, char* key) {
    size_t i = hash(key, table->size);
    field* val = arr_get(table->fields, i);
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

void set(object* table, char* key, ptr* value) {
    size_t i = hash(key, table->size);
    field* val = arr_get(table->fields, i);
    if (val == NULL) {
        arr_set(table->fields, i, new_field(key, value));
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

    prev->next = new_field(key, value);
}