#include "main.h"
#include <stdio.h>

void saveData() {
    FILE *file = fopen("data.txt", "w");
    if (file == NULL) {
        printf("\nError opening file for writing.");
        return;
    }
    fprintf(file, "%d %d %d %d %d %.2f\n", nob, noc, noE, noby, count, amt);
    fclose(file);
    printf("\nData saved successfully.");
}

void loadData() {
    FILE *file = fopen("data.txt", "r");
    if (file == NULL) {
        printf("\nNo data file found. Starting with default values.");
        return;
    }
    fscanf(file, "%d %d %d %d %d %f", &nob, &noc, &noE, &noby, &count, &amt);
    fclose(file);
}
