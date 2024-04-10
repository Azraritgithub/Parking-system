#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED
#include <stdio.h>
// Define a structure to represent a vehicle
struct Vehicle {
    int count;    // Variable to store the count of vehicles
    float amount; // Variable to store the total amount associated with vehicles
};

// Define an enumeration to represent different types of vehicles
enum VehicleType { BUS = 0, CAR, ERIKSHA, MOTOR_BIKE, NUM_VEHICLE_TYPES };

// Declare an array to store data for each vehicle type
struct Vehicle vehicles[NUM_VEHICLE_TYPES];
#endif