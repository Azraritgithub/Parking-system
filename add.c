#include "main.h"
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