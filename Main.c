#include <stdio.h>  // Include standard input-output functions header file
#include <conio.h>  // Include console input-output functions header file
#include <stdlib.h> // Include standard library functions header file

// Define a structure to represent a vehicle
struct Vehicle {
    int count;    // Variable to store the count of vehicles
    float amount; // Variable to store the total amount associated with vehicles
};

// Define an enumeration to represent different types of vehicles
enum VehicleType { BUS = 0, CAR, ERIKSHA, MOTOR_BIKE, NUM_VEHICLE_TYPES };

// Declare an array to store data for each vehicle type
struct Vehicle vehicles[NUM_VEHICLE_TYPES];

// Function to add a vehicle of specified type
void addVehicle(enum VehicleType type) {
    vehicles[type].count++;           // Increment the count of vehicles of specified type
    vehicles[type].amount += 100;     // Add 100 to the total amount associated with that type
    // Print a message indicating the successful addition of the vehicle
    printf("\nAdd %s successfully", type == BUS ? "bus" :
                                   type == CAR ? "car" :
                                   type == ERIKSHA ? "Eriksha" :
                                   type == MOTOR_BIKE ? "motor bike" : "");
}

// Function to display the count and total amount of each vehicle type
void display() {
    printf("\nTotal bus: %d", vehicles[BUS].count);         // Print count of buses
    printf("\nTotal car: %d", vehicles[CAR].count);         // Print count of cars
    printf("\nTotal Eriksha: %d", vehicles[ERIKSHA].count); // Print count of Eriksas
    printf("\nTotal motor bike: %d", vehicles[MOTOR_BIKE].count); // Print count of motor bikes
    // Print the total count of all vehicles
    printf("\nTotal count: %d", vehicles[BUS].count + vehicles[CAR].count +
                                vehicles[ERIKSHA].count + vehicles[MOTOR_BIKE].count);
    // Print the total amount associated with all vehicles
    printf("\nTotal Amount: %f", vehicles[BUS].amount + vehicles[CAR].amount +
                                  vehicles[ERIKSHA].amount + vehicles[MOTOR_BIKE].amount);
}

// Function to reset count and total amount for each vehicle type to zero
void reset() {
    // Iterate through each vehicle type and reset count and amount to zero
    for (int i = 0; i < NUM_VEHICLE_TYPES; i++) {
        vehicles[i].count = 0;
        vehicles[i].amount = 0;
    }
}

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
