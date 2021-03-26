#include "include/types/any.h"
#include "include/ioc.h"
#include "include/test.h"
#include "include/readFile.h"
#include <stdlib.h>
#include "errno.h"
#include <stdio.h>

any* function(array* args) {
    int* a = arr_get(args, 0)->to;
    int* b = arr_get(args, 1)->to;

    int c = *a + *b;
    any* p = smalloc(sizeof(int), NULL);
    p->to = &c;
    return p;
}
 
void main() {
    
    init_ioc();



    register_dependency(new_string("key"), &function);
    
    int a = 5;
    any* p1 = smalloc(sizeof(int), NULL);
    p1->to = &a;
    int b = 2;
    any* p2 = smalloc(sizeof(int), NULL);
    p2->to = &b;

    array* args = new_array(2);
    arr_set(args, 0,p1);
    arr_set(args, 1,p2);

    any* p3 = resolve(new_string("key"), args);
    int* c = p3->to;
    printf("res =\"%i\"; sloud be 7\n", *c);

    // file* f = openFile("./example.txt");
    // printf("Error %d\n", errno);
    // char c = next(f);
    // printf("%c \n", c);
    // c = next(f);
    // printf("%c", c);
    // c = next(f);
    // printf("%c", c);
    // c = next(f);
    // printf("%c", c);
    // del(args);
}