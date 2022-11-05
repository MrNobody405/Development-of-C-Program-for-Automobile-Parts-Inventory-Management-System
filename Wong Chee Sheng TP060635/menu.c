#include "main.h"
#include "create.h"
#include "create_supplier.h"
#include "display_parts.h"
#include "parts_inventory_update.h"
#include "parts_inventory_tracking.h"
#include "search.h"

void menu() {
    int option;
    do {
        printf("---------------Main menu---------------\n");
        printf("\t1. Create parts\n");
        printf("\t2. Create supplier\n");
        printf("\t3. Display parts\n");
        printf("\t4. Parts Inventory Update\n");
        printf("\t5. Parts Inventory Tracking\n");
        printf("\t6. Search\n");
        printf("\t7. Exit\n");
        printf("---------------------------------------\n");
        printf("Please enter your option: ");
        scanf("%d", &option);
        getchar();
        switch (option) {
        case 1:
            create();   //calling create() to create a part into respective file
            break;
        case 2:
            create_supplier();   //calling create_supplier() to create new supplier into supplier file
            break;
        case 3:
            display_parts();   //calling display_parts() to display parts data from all files
            break;
        case 4:
            parts_inventory_update();   //calling parts_inventory_creation to insert warehouses, parts, part_id, quantity in text files
            break;
        case 5:
            parts_inventory_tracking();   //calling parts_inventory_tracking to display all parts details with quantity in ascending order and display parts with less than quantity of ten
            break;
        case 6:
            search();   //to display the parts record when searched by parts ID and supplier details as well
            break;
        case 7:
            break;
        default:
            printf("Wrong value entered.\n");
        }
    } while (option != 7);
}