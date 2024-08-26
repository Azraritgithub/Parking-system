#include <stdio.h>
#include "file.c"  // Including file operations to reset data

void resetParkingLot() {
    FILE *file = fopen(FILENAME, "w");
    if (!file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    // Simply clear the file content
    fclose(file);
    printf("Parking lot reset successfully.\n");
}
