#include "main.h"

typedef struct supplier {
    char supplierID[4];
    char supplier_name[30];
    char contact_number[15];
    char address[100];
    char email_address[30];
}supplier;

void create_supplier() {
    printf("\n-----------Supplier Creation-----------\n");

    char line[200], oldID[3], ID[3];
    int newID;

    supplier s;
    FILE* fp;

    strcpy(s.supplierID, "S");   //set the first value to supplierID as "S"

    fp = fopen("supplier.txt", "r");
    if (fp == NULL) {
        printf("File does not exist.\n");   //if file does not exists, then tell user file doesn't exists.
        strcpy(ID, "01");   //if there is not initial ID, start with "01"
    } else {
        while (!feof(fp)) {
            fgets(line, 200, fp);   //read file and take get last line values from file into line
        }
        fclose(fp);

        memcpy(oldID, &line[1], 2);   //copy the second and third value of line into oldID
        oldID[2] = '\0';   //set null terminator
        newID = atoi(oldID);   //convert the string into integer data type
        newID = newID++;   //increment the integer by 1
        sprintf(ID, "%02d", newID);   //convert the integer into string data type while retaining 2 digits
    }

    strcat(s.supplierID, ID);   //concatenate s.supplierID with initial alphabet with ID to form a unique ID for the file

    //Enter supplier information
    printf("\nEnter supplier name: ");
    gets(s.supplier_name);

    printf("Enter supplier contact number: ");
    gets(s.contact_number);

    printf("Enter supplier address: ");
    gets(s.address);

    printf("Enter supplier email address: ");
    gets(s.email_address);

    printf("\n---------------------------------------\n\n");

    printf("Supplier ID: %s\n", s.supplierID);
    printf("Supplier name: %s\n", s.supplier_name);
    printf("Supplier contact number: %s\n", s.contact_number);
    printf("Supplier address: %s\n", s.address);
    printf("Supplier email address: %s\n", s.email_address);
    printf("\n");

    //append into supplier.txt with supplier information
    fp = fopen("supplier.txt", "a");
    if (fp == NULL) {
        printf("File does not exist.\n");
    } else {
        fprintf(fp, "%s:%s:%s:%s:%s:", s.supplierID, s.supplier_name, s.contact_number, s.address, s.email_address);
        fprintf(fp, "\n");
    }
    fclose(fp);
}