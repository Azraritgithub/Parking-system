#include "main.h"
#include <stdio.h>

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

    while (getchar() != '\n'); // Discard any remaining characters in the buffer

    return choice;
}
