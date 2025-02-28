#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PRODUCTS 10
#define MAX_USERS 5
#define NAME_LEN 50

typedef struct {
    char productName[NAME_LEN];
    float price;
    int rating;
} Product;

typedef struct {
    char userName[NAME_LEN];
    int purchasedProductIndices[MAX_PRODUCTS];
    int purchaseCount;
} User;

Product products[MAX_PRODUCTS];
User users[MAX_USERS];

void initializeProducts() {
    strcpy(products[0].productName, "Laptop");
    products[0].price = 899.99;
    products[0].rating = 5;

    strcpy(products[1].productName, "Smartphone");
    products[1].price = 499.99;
    products[1].rating = 4;

    strcpy(products[2].productName, "Headphones");
    products[2].price = 199.99;
    products[2].rating = 4;

    strcpy(products[3].productName, "Smartwatch");
    products[3].price = 299.99;
    products[3].rating = 3;

    strcpy(products[4].productName, "Tablet");
    products[4].price = 399.99;
    products[4].rating = 5;
}

void initializeUsers() {
    strcpy(users[0].userName, "John");
    users[0].purchasedProductIndices[0] = 0;
    users[0].purchaseCount = 1;

    strcpy(users[1].userName, "Jane");
    users[1].purchasedProductIndices[0] = 1;
    users[1].purchaseCount = 1;
}

void displayRecommendedProducts(User user) {
    printf("\nRecommended products for %s:\n", user.userName);
    int recommendedCount = 0;
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        int isPurchased = 0;
        for (int j = 0; j < user.purchaseCount; j++) {
            if (user.purchasedProductIndices[j] == i) {
                isPurchased = 1;
                break;
            }
        }
        if (!isPurchased) {
            printf("%s | Price: $%.2f | Rating: %d\n", products[i].productName, products[i].price, products[i].rating);
            recommendedCount++;
        }
    }
    if (recommendedCount == 0) {
        printf("No recommendations available.\n");
    }
}

void showMenu() {
    printf("\nProduct Recommendation System\n");
    printf("1. View Recommendations\n");
    printf("2. Exit\n");
}

int main() {
    int choice, userIndex;
    initializeProducts();
    initializeUsers();

    while (1) {
        showMenu();
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();  

        switch (choice) {
            case 1:
                printf("Enter user index (0 for John, 1 for Jane): ");
                scanf("%d", &userIndex);
                if (userIndex >= 0 && userIndex < MAX_USERS) {
                    displayRecommendedProducts(users[userIndex]);
                } else {
                    printf("Invalid user index.\n");
                }
                break;
            case 2:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
