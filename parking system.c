#include <stdio.h>
#include <stdlib.h>

int main() { // Mian function

    while (1) { // infinite loop to keep the program running until the user chooses to exit

        // printing menu options
        printf("----------------Parking System Management----------------\n");
        printf("1. Park a car\n");
        printf("2. Remove a car\n");
        printf("3. View available spots\n");
        printf("4. Exit\n");
        printf("-------------------------------------------------------------\n");

        int choice;// variable to store user's choice
        printf("Enter your choice: ");// Asking user to input their choice
        scanf("%d", &choice);// Reading user's choice

        switch (choice) { //Switch statement to handle different choices
            case 1: // if user chooses option 1

                            printf("To park a car \n");//printing a message indicating parking
                            break;// Exiting the switch statement


            case 2:// if user chooses option 2
                printf("Enter the spot number to remove the car:\n ");// prompting user to enter spot number to remove a car

                break;// Exiting the switch statement

            case 3:// if user chooses option 3
                printf(" View Available spots: \n"); //printing a message indicating viewing available spots
                break;//Exiting the switch statement
            case 4:// if user chooses option 4
                exit(0);// Exiting the program with status code0
            default://if user chooses an invalid option
                printf("Invalid choice\n");// printing a message indicating invalid choice
        }
    }

    return 0;
}

