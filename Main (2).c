#include <stdio.h>
#include <stdlib.h>

// Global variables for tracking counts and amounts
int nob = 0, noc = 0, noE = 0, noby = 0, count = 0;
float amt = 0;

// Function to add a bus
void addBus() {
    nob++;
    amt += 100.0;
    count++;
    printf("\nBus added successfully.");
}

// Function to add a car
void addCar() {
    noc++;
    amt += 100.0;
    count++;
    printf("\nCar added successfully.");
}

// Function to add an ERiksha
void addERiksha() {
    noE++;
    amt += 100.0;
    count++;
    printf("\nERiksha added successfully.");
}

// Function to add a motorbike
void addMotorbike() {
    noby++;
    amt += 100.0;
    count++;
    printf("\nMotorbike added successfully.");
}

// Function to display all the counts and total amount
void displayData() {
    printf("\nTotal buses: %d", nob);
    printf("\nTotal cars: %d", noc);
    printf("\nTotal ERikshas: %d", noE);
    printf("\nTotal motorbikes: %d", noby);
    printf("\nTotal count: %d", count);
    printf("\nTotal amount: %.2f", amt);
}

// Function to reset all counts and amount
void resetData() {
    nob = 0;
    noc = 0;
    noE = 0;
    noby = 0;
    count = 0;
    amt = 0;
    printf("\nData reset successfully.");
}

// Function to display the menu and get the user's choice
int showMenu() {
    int choice;
    printf("\nMenu:");
    printf("\n[1] Add Bus");
    printf("\n[2] Add Car");
    printf("\n[3] Add ERiksha");
    printf("\n[4] Add Motorbike");
    printf("\n[5] Display Data");
    printf("\n[6] Reset Data");
    printf("\n[7] Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    // Clear input buffer after reading integer input
    while (getchar() != '\n'); // Discard any remaining characters in the buffer

    return choice;
}

// Main function
int main() {
    // No need to load data from file since we're not using file handling

    while (1) {
        int choice = showMenu();
        switch (choice) {
            case 1:
                addBus();
                break;
            case 2:
                addCar();
                break;
            case 3:
                addERiksha();
                break;
            case 4:
                addMotorbike();
                break;
            case 5:
                displayData();
                break;
            case 6:
                resetData();
                break;
            case 7:
                printf("\nExiting...");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.");
        }
        // Wait for user input to proceed
        printf("\nPress Enter to continue...");
        // Clear the input buffer before waiting for user input
        while (getchar() != '\n'); // Discard any remaining characters in the buffer
    }

    return 0;
}
