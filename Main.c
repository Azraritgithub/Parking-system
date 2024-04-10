#include <stdio.h>  // Include standard input-output functions header file
#include <conio.h>  // Include console input-output functions header file
#include <stdlib.h> // Include standard library functions header file


#include "main.h"
#include "add.c"
#include "count and total.c"
#include "reset.c"
#include "menu.c"









// Main function
int main() {
    // Main loop for displaying the menu and performing actions based on user's choice
    while (1) {
        switch (menu()) {
            case 1:
                addVehicle(BUS);         // Add a bus
                break;
            case 2:
                addVehicle(CAR);         // Add a car
                break;
            case 3:
                addVehicle(ERIKSHA);     // Add an Eriksha
                break;
            case 4:
                addVehicle(MOTOR_BIKE);  // Add a motor bike
                break;
            case 5:
                display();               // Display vehicle data
                break;
            case 6:
                reset();                 // Reset vehicle data
                break;
            case 7:
                exit(0);                 // Exit the program
            default:
                printf("\nWrong choice"); // Print message for wrong choice
        }
        getch(); // Wait for user input before continuing
    }
    return 0; // Return 0 to indicate successful program execution
}
