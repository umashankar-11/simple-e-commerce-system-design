#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PRODUCTS 10
#define MAX_WISHLIST 5
#define NAME_LEN 50

typedef struct {
    char productName[NAME_LEN];
    float price;
} Product;

typedef struct {
    Product wishlist[MAX_WISHLIST];
    int wishlistCount;
} User;

Product products[MAX_PRODUCTS];
User users[1]; 

void initializeProducts() {
    strcpy(products[0].productName, "Laptop");
    products[0].price = 899.99;

    strcpy(products[1].productName, "Smartphone");
    products[1].price = 499.99;
}

void displayProducts() {
    printf("\nAvailable Products:\n");
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (strlen(products[i].productName) > 0) {
            printf("| %-12s | $%-7.2f |\n", products[i].productName, products[i].price);
        }
    }
}

void addToWishlist(int productIndex) {
    if (users[0].wishlistCount < MAX_WISHLIST) {
        users[0].wishlist[users[0].wishlistCount] = products[productIndex];
        users[0].wishlistCount++;
        printf("Product %s added to your wishlist.\n", products[productIndex].productName);
    } else {
        printf("Wishlist is full. Remove an item to add a new one.\n");
    }
}

void removeFromWishlist(int productIndex) {
    int found = 0;
    for (int i = 0; i < users[0].wishlistCount; i++) {
        if (strcmp(users[0].wishlist[i].productName, products[productIndex].productName) == 0) {
            for (int j = i; j < users[0].wishlistCount - 1; j++) {
                users[0].wishlist[j] = users[0].wishlist[j + 1];
            }
            users[0].wishlistCount--;
            printf("Product %s removed from your wishlist.\n", products[productIndex].productName);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Product not found in your wishlist.\n");
    }
}

void viewWishlist() {
    printf("\nYour Wishlist:\n");
    if (users[0].wishlistCount == 0) {
        printf("Wishlist is empty.\n");
    } else {
        for (int i = 0; i < users[0].wishlistCount; i++) {
            printf("| %-12s | $%-7.2f |\n", users[0].wishlist[i].productName, users[0].wishlist[i].price);
        }
    }
}

void showMenu() {
    printf("\nWishlist Management\n");
    printf("1. View Products\n");
    printf("2. Add to Wishlist\n");
    printf("3. Remove from Wishlist\n");
    printf("4. View Wishlist\n");
    printf("5. Exit\n");
}

int main() {
    int choice, productIndex;

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
                addToWishlist(productIndex);
                break;
            case 3:
                printf("Enter product index to remove from wishlist (0 for Laptop, 1 for Smartphone): ");
                scanf("%d", &productIndex);
                removeFromWishlist(productIndex);
                break;
            case 4:
                viewWishlist();
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
