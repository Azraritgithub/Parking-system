#ifndef MAIN_H
#define MAIN_H

// Global variables for tracking counts and amounts
extern int nob, noc, noE, noby, count;
extern float amt;

// Function declarations
void addBus();
void addCar();
void addERiksha();
void addMotorbike();
void displayData();
void resetData();
int showMenu();
void saveData();
void loadData();
void displayData();

#endif // MAIN_H
