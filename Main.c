#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Vehicle {
    int count;
    float amount;
};

  enum VehicleType { BUS = 0, CAR, ERIKSHA, MOTOR_BIKE, NUM_VEHICLE_TYPES };

struct Vehicle vehicles[NUM_VEHICLE_TYPES];

void addVehicle(enum VehicleType type) {
    vehicles[type].count++;
    vehicles[type].amount += 100;
    printf("\nAdd %s successfully", type == BUS ? "bus" :
                                   type == CAR ? "car" :
                                   type == ERIKSHA ? "Eriksha" :
                                   type == MOTOR_BIKE ? "motor bike" : "");
}

void display() {
    printf("\nTotal bus: %d", vehicles[BUS].count);
    printf("\nTotal car: %d", vehicles[CAR].count);
    printf("\nTotal Eriksha: %d", vehicles[ERIKSHA].count);
    printf("\nTotal motor bike: %d", vehicles[MOTOR_BIKE].count);
    printf("\nTotal count: %d", vehicles[BUS].count + vehicles[CAR].count +
                                vehicles[ERIKSHA].count + vehicles[MOTOR_BIKE].count);
    printf("\nTotal Amount: %f", vehicles[BUS].amount + vehicles[CAR].amount +
                                  vehicles[ERIKSHA].amount + vehicles[MOTOR_BIKE].amount);
}

void reset() {
    for (int i = 0; i < NUM_VEHICLE_TYPES; i++) {
        vehicles[i].count = 0;
        vehicles[i].amount = 0;
    }
}

int menu() {
    int ch;
    printf("\n[1] Add bus");
    printf("\n[2] Add car");
    printf("\n[3] Add Eriksha");
    printf("\n[4] Add motor bike");
    printf("\n[5] Display");
    printf("\n[6] Reset");
    printf("\n[7] Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &ch);
    return ch;
}

int main() {
    while (1) {
        switch (menu()) {
            case 1:
                addVehicle(BUS);
                break;
            case 2:
                addVehicle(CAR);
                break;
            case 3:
                addVehicle(ERIKSHA);
                break;
            case 4:
                addVehicle(MOTOR_BIKE);
                break;
            case 5:
                display();
                break;
            case 6:
                reset();
                break;
            case 7:
                exit(0);
            default:
                printf("\nWrong choice");
        }
        getch();
    }
    return 0;
}
