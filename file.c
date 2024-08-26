#include <stdio.h>
#include "main.h"

void saveToFile(Car cars[], int count) {
    FILE *file = fopen(FILENAME, "w");
    if (!file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%d %s\n", cars[i].slot_number, cars[i].plate_number);
    }

    fclose(file);
}

int loadFromFile(Car cars[]) {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        return 0; // No file exists, so no cars are loaded
    }

    int count = 0;
    while (fscanf(file, "%d %19s", &cars[count].slot_number, cars[count].plate_number) == 2) {
        count++;
    }

    fclose(file);
    return count;
}
