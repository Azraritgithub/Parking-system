#include <stdio.h>
#include "main.h"
#include "add.c"    // Ensure function prototypes are available in main.h
#include "remove.c"
#include "list.c"

void displayMenu() {
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
}
