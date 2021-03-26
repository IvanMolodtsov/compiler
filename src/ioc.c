#include "include/ioc.h"

void init_ioc() {
    IOC.current = new_scope(NULL);
}

any* resolve(string* key, array* params) {
    dependency* d;
    d = get_dependency(IOC.current, key);
    if (d == NULL) {
        return NULL;
    }
    any* (*invoke)(any**) = d->invoke;
    any* ret = invoke(params);
    return ret;
}

void register_dependency(string* key, any* (*invoke)(any**)) {
    dependency* d = new_dependency(invoke);
    set_dependency(IOC.current, key, d);
}