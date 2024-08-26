#ifndef MAIN_H
#define MAIN_H

#define MAX_CARS 100
#define FILENAME "data.txt"

typedef struct {
    char plate_number[20];
    int slot_number;
} Car;

void addCar();
void removeCar();
void listCars();
void saveToFile(Car cars[], int count);
int loadFromFile(Car cars[]);

#endif

