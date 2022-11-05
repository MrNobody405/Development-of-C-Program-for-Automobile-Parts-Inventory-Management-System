#include "main.h"
#include "warehouse_choice.h"

typedef struct parts {
    char partsID[4];
    char section[15];
    int quantity;
    char supplierID[4];
}parts;

void parts_inventory_update() {
    int warehouse = warehouse_choice();
    char path[8];
    if (warehouse == 1) {
        strcpy(path, "WBZ.txt");
    }
    else if (warehouse == 2) {
        strcpy(path, "WSL.txt");
    }
    else if (warehouse == 3) {
        strcpy(path, "WAR.txt");
    }
    else if (warehouse == 4) {
        strcpy(path, "WFS.txt");
    }
    else {
        strcpy(path, "WGS.txt");
    }

    printf("\n--------Part Inventory Update--------\n");

    parts p;
    FILE *fp, *fp1;
    char searchID[4], str[30], line[30], a[30], b[30];
    int amount = 0, ans, i = 0, j = 1, x = 1;

    fp = fopen(path, "r");
    if (fp == NULL) {
        printf("File does not exist.");
    } else {
        fp1 = fopen("temp.txt", "w");   //write into temporary file all the data of the specified file
        if (fp1 == NULL) {
            printf("File cannot be created.");
        } else {
            while ((fgets(a, 30, fp)) != NULL)
            {
                fprintf(fp1, a);
            }
            fclose(fp);
            fclose(fp1);

            fp = fopen(path, "r");
            while (j) {
                printf("Enter ID: ");
                gets(searchID);

                rewind(fp);    //rewind pointer to start of file to search of matching string
                while ((fgets(str, 30, fp)) != NULL) {
                    if (strstr(str, searchID) != NULL) {   // if found keyword
                        strcpy(line, str);   //copy that line into line array
                        j = 0;
                    }
                }
                if (j == 1) {
                    printf("ID not found. Please ensure ID entered is correct.\n");
                }
            }
            fclose(fp);

            char* store = strtok(line, ":");   //separate the line by ":" and store each value into temp 2D array
            char* temp[4];

            while (store != NULL) {
                temp[i++] = store;
                store = strtok(NULL, ":");
            }

            printf("\nPart ID: %s\n", temp[0]);
            printf("Section: %s\n", temp[1]);
            printf("Supplier ID: %s\n", temp[2]);
            printf("Quantity :%s\n", temp[3]);

            strcpy(p.partsID, temp[0]);   //copy the string into parts structure
            strcpy(p.section, temp[1]);
            strcpy(p.supplierID, temp[2]);
            p.quantity = atoi(temp[3]);   //convert quantity into integer data type

            while (x) {
                printf("\n1. Increase\n");
                printf("2. Decrease\n");
                printf("Enter a number to increase or decrease part quantity: ");
                scanf("%d", &ans);
                if (ans == 1) {
                    x = 0;   //escape sequence from this while loop
                    printf("\nEnter amount to increase: ");
                    scanf("%d", &amount);;
                    p.quantity = p.quantity + amount;
                    printf("New quantity: %d\n", p.quantity);
                }
                else if (ans == 2) {
                    printf("\nEnter amount to decrease: ");
                    scanf("%d", &amount);
                    x = 0;   //escape sequence from this while loop
                    if (amount > p.quantity) {    //check if the quantity of the part is less than amount requested or not
                        printf("\nInsufficient parts. Please ensure there are sufficient amount of parts available.\n");
                    }
                    else {
                        p.quantity = p.quantity - amount;
                        printf("New quantity: %d\n", p.quantity);
                    }
                }
                else {
                    printf("Invalid input.");
                }
            }

            //replace line with updated quantity
            fp = fopen(path, "w");
            fp1 = fopen("temp.txt", "r");   //read from temp.txt file
            if ((fp == NULL) || (fp1 == NULL)) {
                printf("File cannot be opened.");
            } else {
                while ((fgets(b, 30, fp1)) != NULL) { // Continue to read line if not end of file
                    if (strstr(b, p.partsID)) {   //if line in file matches with the partsID, it replaces the line with updated data
                        fprintf(fp, "%s:%s:%s:%d", p.partsID, p.section, p.supplierID, p.quantity);
                            fprintf(fp, "\n");
                    }
                    else {
                        fprintf(fp, b);   //else it continues copies from temp.txt file to specified file
                    }
                }
            }
            fclose(fp);
            fclose(fp1);
            printf("\n---------------------------------------\n\n");
        }
    }
}