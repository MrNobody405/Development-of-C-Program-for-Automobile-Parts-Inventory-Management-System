#include "main.h"

typedef struct parts {
    char partsID[4];
    char section[15];
    char quantity[4];
    char supplierID[4];
}parts;

void search() {
    printf("\n----------------Search-----------------\n");
    parts p;
    FILE* fp;
    char warehouseFiles[5][8] = { "WBZ.txt", "WSL.txt", "WAR.txt", "WFS.txt", "WGS.txt" };
    int i, x = 1, y = 1, ctr = 0, option;

    char str[30], searchID[4], str1[200], str2[200];

    while (x) {
        printf("Enter ID: ");
        gets(searchID);
        for (i = 0; i < 5; i++) {
            fp = fopen(warehouseFiles[i], "r");
            if (fp == NULL) {
                printf("File does not exist.");
            } else {
                rewind(fp);
                while ((fgets(str, 30, fp)) != NULL) {
                    if (strstr(str, searchID) != NULL) {   // if found keyword
                        x = 0;
                        char* store = strtok(str, ":");   //separate the line by ":" and store each value into temp 2D array
                        char* temp[4];
                        while (store != NULL) {
                            temp[ctr++] = store;
                            store = strtok(NULL, ":");
                        }
                        strcpy(p.partsID, temp[0]);   //copy the string into parts structure
                        strcpy(p.section, temp[1]);
                        strcpy(p.supplierID, temp[2]);   //copy the supplier ID into p.supplierID to ltr compare in supplier.txt
                        strcpy(p.quantity, temp[3]);
                    }
                }
            }
            fclose(fp);
        }
        if (x == 1) {
            printf("ID not found. Please ensure ID entered is correct.\n");   //if ID is not found
        }
    }

    while (y) {
        printf("\n\t1. Search part details\n");
        printf("\t2. Search supplier details\n");
        printf("Enter option: ");
        scanf("%d", &option);
        if (option == 1) {
            y = 0;
            printf("\nPart ID: %s\n", p.partsID);
            printf("Section: %s\n", p.section);
            printf("Supplier ID: %s\n", p.supplierID);
            printf("Quantity :%s\n", p.quantity);
        } else if (option == 2) {
            y = 0;
            fp = fopen("supplier.txt", "r");
            if (fp == NULL) {
                printf("File does not exist.");
            } else {
                while ((fgets(str1, 200, fp)) != NULL) {
                    if (strstr(str1, p.supplierID)) {             // if found keyword
                        strcpy(str2, str1);
                    }
                }
            }
            fclose(fp);

            char* store1 = strtok(str2, ":");
            char* temp1[6];
            int j = 0;

            while (store1 != NULL) {
                temp1[j++] = store1;
                store1 = strtok(NULL, ":");
            }

            printf("\nSupplier ID: %s\n", temp1[0]);
            printf("Supplier name: %s\n", temp1[1]);
            printf("Supplier contact number :%s\n", temp1[2]);
            printf("Supplier address :%s\n", temp1[3]);
            printf("Supplier email address :%s\n", temp1[4]);
            printf("Parts ID that the supplier supplies: %s", temp1[5]);
        } else {
            printf("Invalid input.\n");
        }
    }

    printf("\n---------------------------------------\n\n");
}