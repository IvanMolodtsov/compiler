#include "include/ptr.h"
#include "include/object.h"

void main() {
    ptr* a = smalloc(sizeof(int), NULL);
    int val = 5;
    ptr_set(a, &val);
    printf("%i\n",a->size);
    printf("%i\n",*((int *)a->to));
    object* o = new_object(10);

    set(o,"key1", a);

    ptr* b = get(o, "key1");
    printf("%i\n",b->size);

    del(o);
    printf("%i\n",o->size);
    ptr* c = get(o, "key1");
    printf("end");

}