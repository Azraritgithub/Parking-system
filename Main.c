#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CARS 100
#define FILENAME "parking_lot.txt"

// Define a structure to represent a car
typedef struct {
    char plate_number[20];
    int slot_number;
} Car;

// Function prototypes
void addCar();
void removeCar();
void listCars();
void saveToFile(Car cars[], int count);
int loadFromFile(Car cars[]);
int getIntegerInput();
void clearInputBuffer();

// Main function
int main() {
    int choice;

    while (1) {
        printf("Parking System Management\n");
        printf("1. Add Car\n");
        printf("2. Remove Car\n");
        printf("3. List Cars\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        choice = getIntegerInput(); // Get validated integer input

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
                printf("Exiting...\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}

// Function to get an integer input from the user with validation
int getIntegerInput() {
    int input;
    char term;

    while (1) {
        if (scanf("%d", &input) == 1) {
            clearInputBuffer();
            return input;
        } else {
            clearInputBuffer();
            printf("Invalid input. Please enter a number: ");
        }
    }
}

// Function to clear the input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF); // Discard invalid input
}

// Function to add a car to the parking lot
void addCar() {
    Car cars[MAX_CARS];
    int count = loadFromFile(cars);
    int slot;
    char plate_number[20];

    printf("Enter plate number (max 19 characters): ");
    if (scanf("%19s", plate_number) != 1) {
        clearInputBuffer();
        printf("Invalid plate number input.\n");
        return;
    }

    printf("Enter slot number (1 to %d): ", MAX_CARS);
    slot = getIntegerInput(); // Get validated integer input

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
    cars[count].plate_number[sizeof(cars[count].plate_number) - 1] = '\0'; // Ensure null termination
    count++;

    saveToFile(cars, count);
    printf("Car added successfully.\n");
}

// Function to remove a car from the parking lot
void removeCar() {
    Car cars[MAX_CARS];
    int count = loadFromFile(cars);
    int slot;

    printf("Enter slot number to remove car from: ");
    slot = getIntegerInput(); // Get validated integer input

    if (slot < 1 || slot > MAX_CARS) {
        printf("Invalid slot number.\n");
        return;
    }

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

// Function to list all cars in the parking lot
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

// Function to save car data to a file
void saveToFile(Car cars[], int count) {
    FILE *file = fopen(FILENAME, "w");
    if (!file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%d %s\n", cars[i].slot_number, cars[i].plate_number);
    }

    fclose(file);
}

// Function to load car data from a file
int loadFromFile(Car cars[]) {
    FILE *file = fopen(FILENAME, "r");
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
