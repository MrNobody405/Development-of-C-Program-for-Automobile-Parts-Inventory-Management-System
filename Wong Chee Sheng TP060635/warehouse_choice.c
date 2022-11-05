#include "main.h"

int warehouse_choice() {   //function to choose which warehouse
    int warehouse, i = 1;
    while (i) {
        printf("\n---------------Warehouse---------------\n");
        printf("\t1. WBZ\n");
        printf("\t2. WSL\n");
        printf("\t3. WAR\n");
        printf("\t4. WFS\n");
        printf("\t5. WGS\n");
        printf("---------------------------------------\n");
        printf("Please enter your option: ");
        scanf("%d", &warehouse);
        getchar();   //clear keyboard buffer
        switch (warehouse) {   //check if option entered is valid or not. If valid, the option is returned.
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            i = 0;   //break from while loop
            break;
        default:
            printf("Invalid input. Please enter a number.\n");   //If invalid input entered, it loops.
        }
    }
    return warehouse;
}