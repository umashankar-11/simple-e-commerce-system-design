#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PRODUCTS 10
#define MAX_REVIEWS 5
#define NAME_LEN 50

typedef struct {
    int rating;
    char review[100];
} Review;

typedef struct {
    char productName[NAME_LEN];
    Review reviews[MAX_REVIEWS];
    int reviewCount;
} Product;

Product products[MAX_PRODUCTS];

void initializeProducts() {
    strcpy(products[0].productName, "Laptop");
    products[0].reviewCount = 2;
    products[0].reviews[0].rating = 5;
    strcpy(products[0].reviews[0].review, "Excellent product!");
    products[0].reviews[1].rating = 4;
    strcpy(products[0].reviews[1].review, "Good value for money.");

    strcpy(products[1].productName, "Smartphone");
    products[1].reviewCount = 1;
    products[1].reviews[0].rating = 3;
    strcpy(products[1].reviews[0].review, "Average performance.");
}

void displayProductReviews(int productIndex) {
    printf("Reviews for %s:\n", products[productIndex].productName);
    for (int i = 0; i < products[productIndex].reviewCount; i++) {
        printf("Rating: %d\n", products[productIndex].reviews[i].rating);
        printf("Review: %s\n\n", products[productIndex].reviews[i].review);
    }
}

void addProductReview(int productIndex, int rating, char *review) {
    if (products[productIndex].reviewCount < MAX_REVIEWS) {
        products[productIndex].reviews[products[productIndex].reviewCount].rating = rating;
        strcpy(products[productIndex].reviews[products[productIndex].reviewCount].review, review);
        products[productIndex].reviewCount++;
        printf("Review added successfully!\n");
    } else {
        printf("Maximum reviews reached for this product.\n");
    }
}

int main() {
    int choice, rating, productIndex;
    char review[100];

    initializeProducts();

    while (1) {
        printf("\nProduct Reviews & Ratings\n");
        printf("1. View Product Reviews\n");
        printf("2. Add Product Review\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();  

        switch (choice) {
            case 1:
                printf("Enter product index (0 for Laptop, 1 for Smartphone): ");
                scanf("%d", &productIndex);
                displayProductReviews(productIndex);
                break;
            case 2:
                printf("Enter product index (0 for Laptop, 1 for Smartphone): ");
                scanf("%d", &productIndex);
                printf("Enter rating (1-5): ");
                scanf("%d", &rating);
                getchar();  
                printf("Enter your review: ");
                fgets(review, 100, stdin);
                review[strcspn(review, "\n")] = '\0';  
                addProductReview(productIndex, rating, review);
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
