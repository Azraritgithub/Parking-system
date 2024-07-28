#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include "add.c"
#include "count and total.c"
#include "file.c"
#include "global.c"
#include "menu.c"
#include "reset.c"


int main() {
    loadData();  // Load data from file
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
                saveData();  // Save data to file
                printf("\nExiting...");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.");
        }
        printf("\nPress Enter to continue...");
        while (getchar() != '\n'); // Discard any remaining characters in the buffer
    }
    return 0;
}
