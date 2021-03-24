#include "include/ioc.h"

void init_ioc() {
    IOC.current = new_scope(NULL);
}

ptr* resolve(str* key, array* params) {
    dependency* d;
    d = get_dependency(IOC.current, key);
    if (d == NULL) {
        return NULL;
    }
    ptr* (*invoke)(ptr**) = d->invoke;
    ptr* ret = invoke(params);
    return ret;
}

void register_dependency(str* key, ptr* (*invoke)(ptr**)) {
    dependency* d = new_dependency(invoke);
    set_dependency(IOC.current, key, d);
}