#include "include/ptr.h"

void main() {
    ptr* a = smalloc(sizeof(int));
    int val = 5;
    int* p = a->to;
    *p = val;
    del(a);
}