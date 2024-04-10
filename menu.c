#include "main.h"
// Function to display menu options and prompt user for input
int menu() {
    int ch;
    printf("\n[1] Add bus");        // Option to add a bus
    printf("\n[2] Add car");         // Option to add a car
    printf("\n[3] Add Eriksha");     // Option to add an Eriksha
    printf("\n[4] Add motor bike");  // Option to add a motor bike
    printf("\n[5] Display");         // Option to display vehicle data
    printf("\n[6] Reset");           // Option to reset vehicle data
    printf("\n[7] Exit");            // Option to exit the program
    printf("\nEnter your choice: ");
    scanf("%d", &ch); // Read user's choice
    return ch;        // Return user's choice
}