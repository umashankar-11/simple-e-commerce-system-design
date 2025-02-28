#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PRODUCTS 10
#define NAME_LEN 50

typedef struct {
    char productName[NAME_LEN];
    float price;
    float weight;
} Product;

Product products[MAX_PRODUCTS];

void initializeProducts() {
    strcpy(products[0].productName, "Laptop");
    products[0].price = 899.99;
    products[0].weight = 2.5;

    strcpy(products[1].productName, "Smartphone");
    products[1].price = 499.99;
    products[1].weight = 0.3;
}

float calculateShippingCost(float weight, char *location) {
    float baseRate = 5.0;
    float locationMultiplier = 1.0;

    if (strcmp(location, "International") == 0) {
        locationMultiplier = 2.5;
    } else if (strcmp(location, "Domestic") == 0) {
        locationMultiplier = 1.2;
    }

    return baseRate + (weight * locationMultiplier);
}

void checkout(int productIndex, char *location) {
    float price = products[productIndex].price;
    float weight = products[productIndex].weight;
    float shippingCost = calculateShippingCost(weight, location);

    printf("Total price for %s: $%.2f\n", products[productIndex].productName, price);
    printf("Shipping cost for %s: $%.2f\n", products[productIndex].productName, shippingCost);
    printf("Final amount: $%.2f\n", price + shippingCost);
}

void displayProducts() {
    printf("\nAvailable Products:\n");
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (strlen(products[i].productName) > 0) {
            printf("| %-12s | $%-7.2f | Weight: %-4.2f kg |\n", products[i].productName, products[i].price, products[i].weight);
        }
    }
}

void showMenu() {
    printf("\nShipping Calculation\n");
    printf("1. View Products\n");
    printf("2. Checkout with Shipping\n");
    printf("3. Exit\n");
}

int main() {
    int choice, productIndex;
    char location[20];

    initializeProducts();

    while (1) {
        showMenu();
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();  

        switch (choice) {
            case 1:
                displayProducts();
                break;
            case 2:
                printf("Enter product index (0 for Laptop, 1 for Smartphone): ");
                scanf("%d", &productIndex);
                printf("Enter shipping location (Domestic/International): ");
                fgets(location, sizeof(location), stdin);
                location[strcspn(location, "\n")] = '\0';  
                checkout(productIndex, location);
                break;
            case 3:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
