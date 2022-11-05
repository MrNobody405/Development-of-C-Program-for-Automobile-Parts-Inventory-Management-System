#include "main.h"
#include "warehouse_choice.h"

typedef struct parts {
    char partsID[4];
    int quantity;
    char supplierID[4];
}parts;

void create() {
    int warehouse = warehouse_choice();   //to see which warehouse the part is being created for

    parts p;
    FILE* fp, * fp1;

    char path[8], section[15], line[30], oldID[3], ID[3], a[200], b[200], c[200], linesfromfile[30], supplier[4];
    int newID;

    if (warehouse == 1) {    //opens the specific warehouse that is chosen
        strcpy(path, "WBZ.txt");
        strcpy(p.partsID, "A");   //initialize the alphabet as "A" for partsID in WBZ.txt file
    }
    else if (warehouse == 2) {
        strcpy(path, "WSL.txt");
        strcpy(p.partsID, "B");   //initialize the alphabet as "B" for partsID in WBZ.txt file
    }
    else if (warehouse == 3) {
        strcpy(path, "WAR.txt");
        strcpy(p.partsID, "C");   //initialize the alphabet as "C" for partsID in WBZ.txt file
    }
    else if (warehouse == 4) {
        strcpy(path, "WFS.txt");
        strcpy(p.partsID, "D");   //initialize the alphabet as "D" for partsID in WBZ.txt file
    }
    else {
        strcpy(path, "WGS.txt");
        strcpy(p.partsID, "E");   //initialize the alphabet as "E" for partsID in WBZ.txt file
    }

    int i = 1;
    while (i) {
        int option = 0;
        printf("\n-------------Part Creation-------------\n");
        printf("\t1. Engine\n");
        printf("\t2. Body Work\n");
        printf("\t3. Air-Con\n");
        printf("\t4. Brake\n");
        printf("\t5. Transmission\n");
        printf("\t6. Wiring\n");
        printf("\t7. Radio\n");
        printf("---------------------------------------\n");
        printf("Please enter your option: ");
        scanf("%d", &option);
        getchar();
        switch (option) {
        case 1:
            strcpy(section, "Engine");
            i = 0;
            break;
        case 2:
            strcpy(section, "Body Work");
            i = 0;
            break;
        case 3:
            strcpy(section, "Air-Con");
            i = 0;
            break;
        case 4:
            strcpy(section, "Brake");
            i = 0;
            break;
        case 5:
            strcpy(section, "Transmission");
            i = 0;
            break;
        case 6:
            strcpy(section, "Wiring");
            i = 0;
            break;
        case 7:
            strcpy(section, "Radio");
            i = 0;
            break;
        default:
            printf("Invalid input. Please enter a number.\n");
        }

        fp = fopen(path, "r");
        if (fp == NULL) {
            printf("File does not exist.\n");
        } else {
            while (fgets(linesfromfile, 30, fp) != NULL) {   //read lines from file
                if (strstr(linesfromfile, section)) {   //check if section already exists. If exists, set i back to 1 so that while loops continues
                    printf("The part for this section exists. Please check again or choose another section.\n");
                    i = 1;
                }
            }
        }
        fclose(fp);

    }

    fp = fopen(path, "r");
    if (fp == NULL) {
        printf("File does not exists.");
        strcpy(ID, "01");   //if file is empty, set ID as "01" for the first ID in file
    } else {
        while (!feof(fp)) {
            fgets(line, 30, fp);   //read file and take get last line values from file into line
        }

        memcpy(oldID, &line[1], 2);   //copy the first two value of line into oldID
        oldID[2] = '\0';   //set null terminator
        newID = atoi(oldID);   //convert the string into integer data type
        newID = newID++;   //increment the integer by 1
        sprintf(ID, "%02d", newID);   //convert the integer into string data type while retaining 2 digits
    }
    fclose(fp);

    strcat(p.partsID, ID);   //concatenate p.partsID with initial alphabet with ID to form a unique ID for the file
    printf("\nNew part ID: %s\n", p.partsID);

    printf("\nEnter quantity: ");
    scanf("%d", &p.quantity);   //initialize the quantity for the part
    getchar();

    int y = 1;
    fp = fopen("supplier.txt", "r");
    if ((fp == NULL)) {
        printf("File cannot be opened.");
    }
    else {
        while (y) {
            printf("\nEnter supplier ID: ");
            //scanf("%s", p.supplierID);   //enter the supplier ID to be added in the supplier.txt file
            gets(supplier);

            rewind(fp);

            while ((fgets(c, 30, fp)) != NULL) { // Continue to read line if not end of file
                if (strstr(c, supplier) != NULL) {
                    strcpy(p.supplierID, supplier);
                    y = 0;
                    break;
                }
            }
            if (y == 1) {
                printf("Invalid supplier ID.\n");
            }
        }
    }
    fclose(fp);

    printf("\nNew part ID: %s\n", p.partsID);
    printf("Section: %s\n", section);
    printf("Quantity: %d\n", p.quantity);
    printf("Supplier ID: %s\n\n", p.supplierID);

    fp = fopen(path, "a");
    fprintf(fp, "%s:%s:%s:%d", p.partsID, section, p.supplierID, p.quantity);
    fprintf(fp, "\n");
    fclose(fp);


    fp = fopen("supplier.txt", "r");
    if (fp == NULL) {
        printf("File does not exist.");
    }
    else {
        fp1 = fopen("temp.txt", "w");   //write into temporary file all the data of the specified file
        while ((fgets(a, 200, fp)) != NULL) {
            fprintf(fp1, a);
        }
        fclose(fp);
        fclose(fp1);
    }

    fp1 = fopen("temp.txt", "r");
    if (fp1 == NULL) {
        printf("File does not exist.");
    }
    else {
        fp = fopen("supplier.txt", "w");   //write into temporary file all the data of the specified file
        while ((fgets(b, 200, fp1)) != NULL) {
            if (strstr(b, p.supplierID)) {
                b[strlen(b) - 1] = '\0';
                if (b[strlen(b) - 1] == ':') {
                    fprintf(fp, "%s%s\n", b, p.partsID);
                } else {
                    fprintf(fp, "%s, %s\n", b, p.partsID);
                }
            } else {
                fputs(b, fp);
            }
        }
        fclose(fp);
        fclose(fp1);
    }
}