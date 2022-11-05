#include "main.h"

void display_parts() {
    printf("\n-----------All parts details-----------\n\n");
    FILE* fp;
    char line[30];
    char warehouse[5][4] = { "WBZ", "WSL", "WAR", "WFS", "WGS" };
    char warehouseFiles[5][8] = { "WBZ.txt", "WSL.txt", "WAR.txt", "WFS.txt", "WGS.txt" };
    int i;

    for (i = 0; i < 5; i++) {
        printf("%s warehouse records: \n", warehouse[i]);
        fp = fopen(warehouseFiles[i], "r");
        if (fp == NULL) {
            printf("File does not exist.");   //if file doesn't exist, it'll print that file doesn't exist.
        } else {
            while ((fgets(line, 30, fp)) != NULL) {   //gets each line into line array
                char* store = strtok(line, ":");   //separate the line using strtok of ":"
                char* temp[4];
                int a = 0;
                while (store != NULL) {   //if store is not null, the string token will be stored into temp
                    temp[a++] = store;
                    store = strtok(NULL, ":");    //store each string into temp
                }

                printf("ID: %s\n", temp[0]);
                printf("Section: %s\n", temp[1]);
                printf("Supplier ID: %s\n", temp[2]);
                printf("Quantity :%s\n", temp[3]);
            }
            printf("---------------------------------------\n\n");
            fclose(fp);
        }
    }
}