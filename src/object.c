#include "include/types/object.h"
#include "include/SDBM.h"
#include "stdlib.h"

size_t hash(string* key, size_t size) {
    unsigned int hash = SDBMHash(key->value, key->length);
    return hash % size;
}

void destory_field(any* pointer) {
    field* next;
    field* f =(field*) pointer->to;
    while (f != NULL) {
        next = f->next;
        del(f->key);
        del(f->data);
        free(f);
        f=next;
    }
}

void destory_obj(any* pointer) {

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

    any * pointer = smalloc(sizeof(object),&destory_obj);
    
    if (pointer == NULL) {
        del(fields);
        return NULL;
    }
    
    object* newObject = pointer->to;
    newObject->self = *pointer;
    newObject->fields = fields;
    newObject->size = s;
}

field* new_field(string* key,any* data ) {
    any* p = smalloc(sizeof(field), &destory_field);
    if (p == NULL) {
        return NULL;
    }
    field* f = p->to;
    f->self = *p;
    f->key = key;

    f->data = data;
    f->next = NULL;
    return f;
}

any* get(object* table, string* key) {
    size_t i = hash(key, table->size);
    field* val = arr_get(table->fields, i);
    if (val == NULL) {
        return NULL;
    }

    while(val != NULL) {
        if (compare_string(val->key, key)) {
            return val->data;
        }
        val = val->next;
    }

    return NULL;
    
}

void set(object* table, string* key, any* value) {
    size_t i = hash(key, table->size);
    field* val = arr_get(table->fields, i);
    if (val == NULL) {
        arr_set(table->fields, i, new_field(key, value));
        return;
    }

    field* prev;

    while(val != NULL) {
        if (compare_string(val->key, key)) {
            val->data = value;
            return;
        }
        prev = val;
        val = prev->next;
    }

    prev->next = new_field(key, value);
}