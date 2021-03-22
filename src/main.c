#include "include/ptr.h"
#include "include/ioc.h"
#include "include/test.h"
#include <stdlib.h>
#include <stdio.h>
ptr* function(ptr** args) {
    int* a = args[0]->to;
    int* b = args[1]->to;

    int c = *a + *b;
    ptr* p = smalloc(sizeof(int), NULL);
    p->to = &c;
    return p;
}
 
void main() {
    init_ioc();

    register_dependency("key", &function);
    
    int a = 5;
    ptr* p1 = smalloc(sizeof(int), NULL);
    p1->to = &a;
    int b = 2;
    ptr* p2 = smalloc(sizeof(int), NULL);
    p2->to = &b;

    ptr* args[2];
    args[0] = p1;
    args[1] = p2;

    ptr* p3 = resolve("key", args);
    int* c = p3->to;
    printf("%i", *c);
}