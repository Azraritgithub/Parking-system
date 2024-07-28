#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CARS 100
#define FILENAME "parking_lot.txt"

typedef struct {
    char plate_number[20];
    int slot_number;
} Car;

void addCar();
void removeCar();
void listCars();
void saveToFile(Car cars[], int count);
int loadFromFile(Car cars[]);

int main() {
    int choice;

    while (1) {
        printf("Parking System Management\n");
        printf("1. Add Car\n");
        printf("2. Remove Car\n");
        printf("3. List Cars\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCar();
                break;
            case 2:
                removeCar();
                break;
            case 3:
                listCars();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}

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

void saveToFile(Car cars[], int count) {
    FILE *file = fopen("parking_lot.txt", "w");
    if (!file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%d %s\n", cars[i].slot_number, cars[i].plate_number);
    }

    fclose(file);
}

int loadFromFile(Car cars[]) {
    FILE *file = fopen("parking_lot.txt", "r");
    if (!file) {
        return 0; // No file exists, so no cars are loaded
    }

    int count = 0;
    while (fscanf(file, "%d %19s", &cars[count].slot_number, cars[count].plate_number) == 2) {
        count++;
    }

    fclose(file);
    return count;
}
