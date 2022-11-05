#include "main.h"
#include "warehouse_choice.h"

typedef struct parts {
    char partsID[4];
    char section[15];
    int quantity;
    char supplierID[4];
}parts;

void partsLess() {
    int warehouse = warehouse_choice();
    char path[8];
    if (warehouse == 1) {
        strcpy(path, "WBZ.txt");
    }
    else if (warehouse == 2) {
        strcpy(path, "WSL.txt");
    }
    else if (warehouse == 2) {
        strcpy(path, "WAR.txt");
    }
    else if (warehouse == 2) {
        strcpy(path, "WFS.txt");
    }
    else {
        strcpy(path, "WGS.txt");
    }

    FILE* fp;
    parts p;
    char str[30], line[30], quantity[3];

    printf("Parts with less than 10 quantity:\n\n");
    fp = fopen(path, "r");
    if (fp == NULL) {
        printf("File does not exist.");
    } else {
        while ((fgets(str, 30, fp)) != NULL) {
            char* store = strtok(str, ":");
            char* temp[4];
            int i = 0;
            while (store != NULL) {
                temp[i++] = store;
                store = strtok(NULL, ":");
            }

            strcpy(p.partsID, temp[0]);   //copy the string into parts structure
            p.quantity = atoi(temp[3]);   //convert quantity into integer data type

            if (p.quantity < 10) {
                printf("Part ID: %s\n", p.partsID);
            }
        }
    }
    fclose(fp);
    printf("\n---------------------------------------\n\n");
}