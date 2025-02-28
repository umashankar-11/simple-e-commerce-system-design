#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PRODUCTS 10
#define NAME_LEN 50

typedef struct {
    char productName[NAME_LEN];
    int quantity;
    float price;
} Product;

Product inventory[MAX_PRODUCTS];

void initializeInventory() {
    strcpy(inventory[0].productName, "Laptop");
    inventory[0].quantity = 50;
    inventory[0].price = 899.99;

    strcpy(inventory[1].productName, "Smartphone");
    inventory[1].quantity = 30;
    inventory[1].price = 499.99;
}

void viewInventory() {
    printf("\nInventory:\n");
    printf("| Product Name | Quantity | Price    |\n");
    printf("\n");
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (strlen(inventory[i].productName) > 0) {
            printf("| %-13s | %-8d | $%-7.2f |\n", inventory[i].productName, inventory[i].quantity, inventory[i].price);
        }
    }
    printf("\n");
}

void updateStock(char *productName, int quantity) {
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (strcmp(inventory[i].productName, productName) == 0) {
            inventory[i].quantity += quantity;
            printf("Updated stock for %s. New quantity: %d\n", productName, inventory[i].quantity);
            return;
        }
    }
    printf("Product %s not found.\n", productName);
}

void removeProduct(char *productName) {
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (strcmp(inventory[i].productName, productName) == 0) {
            strcpy(inventory[i].productName, "");
            inventory[i].quantity = 0;
            inventory[i].price = 0.0;
            printf("Product %s removed from inventory.\n", productName);
            return;
        }
    }
    printf("Product %s not found.\n", productName);
}

int main() {
    int choice, quantity;
    char productName[NAME_LEN];

    initializeInventory();

    while (1) {
        printf("\nInventory Management\n");
        printf("1. View Inventory\n");
        printf("2. Update Stock\n");
        printf("3. Remove Product\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();  

        switch (choice) {
            case 1:
                viewInventory();
                break;
            case 2:
                printf("Enter product name to update stock: ");
                fgets(productName, NAME_LEN, stdin);
                productName[strcspn(productName, "\n")] = '\0';  
                printf("Enter quantity to add/subtract: ");
                scanf("%d", &quantity);
                updateStock(productName, quantity);
                break;
            case 3:
                printf("Enter product name to remove: ");
                fgets(productName, NAME_LEN, stdin);
                productName[strcspn(productName, "\n")] = '\0';  
                removeProduct(productName);
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
