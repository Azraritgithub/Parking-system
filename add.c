#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "file.h"

void addCar() {
    Car cars[MAX_CARS];
    int count = loadFromFile(cars);
    int slot;
    char plate_number[20];

    printf("Enter plate number: ");
    scanf("%s", plate_number);

    printf("Enter slot number (1 to %d): ", MAX_CARS);
    scanf("%d", &slot);

    if (slot < 1 || slot > MAX_CARS) {
        printf("Invalid slot number.\n");
        return;
    }

    // Check if the slot is already taken
    for (int i = 0; i < count; i++) {
        if (cars[i].slot_number == slot) {
            printf("Slot number %d is already occupied.\n", slot);
            return;
        }
    }

    // Add the new car
    cars[count].slot_number = slot;
    strncpy(cars[count].plate_number, plate_number, sizeof(cars[count].plate_number) - 1);
    count++;

    saveToFile(cars, count);
    printf("Car added successfully.\n");
}
