#include "main.h"
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