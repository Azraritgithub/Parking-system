#include "main.h"

// Function to reset count and total amount for each vehicle type to zero
void reset() {
    // Iterate through each vehicle type and reset count and amount to zero
    for (int i = 0; i < NUM_VEHICLE_TYPES; i++) {
        vehicles[i].count = 0;
        vehicles[i].amount = 0;
    }
}