#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PRODUCTS 10
#define DISCOUNT_CODE_LEN 10
#define NAME_LEN 50

typedef struct {
    char productName[NAME_LEN];
    float price;
} Product;

typedef struct {
    char discountCode[DISCOUNT_CODE_LEN];
    float discountPercentage;
} Discount;

Product products[MAX_PRODUCTS];
Discount discounts[3];

void initializeProducts() {
    strcpy(products[0].productName, "Laptop");
    products[0].price = 899.99;

    strcpy(products[1].productName, "Smartphone");
    products[1].price = 499.99;
}

void initializeDiscounts() {
    strcpy(discounts[0].discountCode, "DISCOUNT10");
    discounts[0].discountPercentage = 10.0;

    strcpy(discounts[1].discountCode, "DISCOUNT20");
    discounts[1].discountPercentage = 20.0;

    strcpy(discounts[2].discountCode, "DISCOUNT30");
    discounts[2].discountPercentage = 30.0;
}

float applyDiscount(char *code, float price) {
    for (int i = 0; i < 3; i++) {
        if (strcmp(discounts[i].discountCode, code) == 0) {
            printf("Discount applied: %.2f%%\n", discounts[i].discountPercentage);
            return price - (price * (discounts[i].discountPercentage / 100));
        }
    }
    printf("Invalid discount code.\n");
    return price;
}

void displayProducts() {
    printf("\nAvailable Products:\n");
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (strlen(products[i].productName) > 0) {
            printf("| %-12s | $%-7.2f |\n", products[i].productName, products[i].price);
        }
    }
}

void checkout(int productIndex, char *discountCode) {
    float price = products[productIndex].price;
    float finalPrice = applyDiscount(discountCode, price);
    printf("Final price for %s: $%.2f\n", products[productIndex].productName, finalPrice);
}

void showMenu() {
    printf("\nDiscount Management\n");
    printf("1. View Products\n");
    printf("2. Checkout with Discount\n");
    printf("3. Exit\n");
}

int main() {
    int choice, productIndex;
    char discountCode[DISCOUNT_CODE_LEN];

    initializeProducts();
    initializeDiscounts();

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
                printf("Enter discount code: ");
                fgets(discountCode, DISCOUNT_CODE_LEN, stdin);
                discountCode[strcspn(discountCode, "\n")] = '\0';  
                checkout(productIndex, discountCode);
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
