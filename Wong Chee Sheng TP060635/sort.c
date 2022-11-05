#include "main.h"

void sort() {
	char warehouseFiles[5][8] = { "WBZ.txt", "WSL.txt", "WAR.txt", "WFS.txt", "WGS.txt" };
	int i, j, c;
	char store[100][30], temp[100][30], allID[100][4], sortID[100][4], fileLines[100][30];
	FILE* fp;

	static int ctr = 0;
	for (i = 0; i < 5; i++) {
		int countline = 0;
		fp = fopen(warehouseFiles[i], "r");
		if (fp == NULL) {
			printf("File does not exist.");
		} else {
			for (c = getc(fp); c != EOF; c = getc(fp)) {
				if (c == '\n') {
					countline = countline + 1;
				}
			}
		}
		fclose(fp);

		fp = fopen(warehouseFiles[i], "r");
		if (fp == NULL) {
			printf("File does not exist.");
		} else {
			for (j = 0; j < countline; j++) {
				fgets(temp, 30, fp);
				strcpy(store, temp);
				strcpy(fileLines[ctr], store);   //copies each lines from file to fileLines
				strncpy(allID[ctr], store, 3);   //copies three first three values of each line into allID array
				allID[ctr][3] = '\0';   //set the third index to a null terminat
				ctr++;   //+1 to ctr to store IDs from other files
			}
		}
		fclose(fp);
	}

	for (i = 0; i < ctr; i++) {   //sort store array by ascending order using nested loops
		for (j = i + 1; j < ctr; j++) {
			if (strcmp(allID[i], allID[j]) > 0) {   // Compare lexicographically, if s1 < s2, returns negative, if s1 > s2, return positive
				strcpy(sortID, allID[i]);
				strcpy(allID[i], allID[j]);
				strcpy(allID[j], sortID);
			}
		}
	}

	printf("\nParts displayed in order:\n\n");

	for (i = 0; i < ctr; i++) {
		for (j = 0; j < ctr; j++)
		if (strstr(fileLines[j], allID[i])) {   //if filesLines has allID, it prints the lines according to allID arrangement
			char* store = strtok(fileLines[j], ":");
			char* temp1[4];
			int x = 0;
			while (store != NULL) {
				temp1[x++] = store;
				store = strtok(NULL, ":");
			}
			printf("Part ID: %s\n", temp1[0]);
			printf("Section: %s\n", temp1[1]);
			printf("Supplier ID: %s\n", temp1[2]);
			printf("Quantity :%s\n", temp1[3]);
		}
	}

	printf("\n---------------------------------------\n\n");
}
