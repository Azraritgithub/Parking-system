#include <stdio.h>
#include "main.h"
#include "file.c"  // Including file.c for file operations

void listCars() {
    Car cars[MAX_CARS];
    int count = loadFromFile(cars);

    if (count == 0) {
        printf("No cars in the parking lot.\n");
        return;
    }

    printf("Parked Cars:\n");
    for (int i = 0; i < count; i++) {
        printf("Slot %d: %s\n", cars[i].slot_number, cars[i].plate_number);
    }
}
