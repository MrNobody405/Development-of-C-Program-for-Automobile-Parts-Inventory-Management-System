#include "main.h"
#include "sort.h"
#include "partsLess.h"

void parts_inventory_tracking() {
    int i = 1, num = 0;

    while (i) {
        printf("\n-------Parts Inventory Tracking-------\n");
        printf("\t1. Sort all by Part ID\n");
        printf("\t2. Parts less than 10\n");
        printf("---------------------------------------\n");
        printf("Please enter an option: ");
        scanf("%d", &num);
        getchar();
        switch (num) {
        case 1:
            sort();
            i = 0;
            break;
        case 2:
            partsLess();
            i = 0;
            break;
        default:
            printf("Invalid input.\n");
        }
    }
}