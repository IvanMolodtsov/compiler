// #include "include/ptr.h"
// #include "include/object.h"
#include "stdlib.h"
#include <libusb-1.0/libusb.h>
#include <stdio.h>

int main() {
    // ptr* a = smalloc(sizeof(int), NULL);
    // int val = 5;
    // ptr_set(a, &val);
    // printf("%i\n",a->size);
    // printf("%i\n",*((int *)a->to));
    // object* o = new_object(10);

    // set(o,"key1", a);

    // ptr* b = get(o, "key1");
    // printf("%i\n",b->size);

    // del(o);
    // printf("%i\n",o->size);
    // ptr* c = get(o, "key1");
    // printf("end");
    // int VID = 951;
    // int PID = 1665;
    int res = libusb_init(NULL);  
    if (res != 0) {
        printf("Error initialising libusb.\n");
        return 1;
    } 
    // инициализация
    libusb_device_handle *handle = libusb_open_device_with_vid_pid(NULL, 0x0951, 0x1665);
    if (handle == NULL) {
        printf("access denied\n");
    } else {
        printf("DA\n");
    }
    // libusb_device **devList = NULL;
    // int numUsbDevs = libusb_get_device_list (NULL, &devList);
    // for(int i=0; i< numUsbDevs; i++) {
    //     libusb_device *dev = devList[i];
    //     libusb_device_handle *handle = NULL;
    //     int retVal = libusb_open (dev, &handle);
    //     if (retVal != LIBUSB_SUCCESS)
    //         printf("error");
        
    // }
}