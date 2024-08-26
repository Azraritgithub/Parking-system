#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "file.c"  // Including file.c for file operations

void removeCar() {
    Car cars[MAX_CARS];
    int count = loadFromFile(cars);
    int slot;

    printf("Enter slot number to remove car from: ");
    scanf("%d", &slot);

    int i;
    for (i = 0; i < count; i++) {
        if (cars[i].slot_number == slot) {
            break;
        }
    }

    if (i == count) {
        printf("No car found in slot %d.\n", slot);
        return;
    }

    // Shift cars to remove the specified slot
    for (int j = i; j < count - 1; j++) {
        cars[j] = cars[j + 1];
    }
    count--;

    saveToFile(cars, count);
    printf("Car removed successfully.\n");
}
