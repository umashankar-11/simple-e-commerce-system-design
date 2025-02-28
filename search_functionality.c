#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PRODUCTS 10
#define NAME_LEN 50
#define DESC_LEN 100

typedef struct {
    int productID;
    char name[NAME_LEN];
    char description[DESC_LEN];
    float price;
    int quantity;
} Product;

Product catalog[MAX_PRODUCTS];

void initializeCatalog() {
    catalog[0].productID = 1;
    strcpy(catalog[0].name, "Laptop");
    strcpy(catalog[0].description, "15-inch Laptop with Intel i7");
    catalog[0].price = 899.99;
    catalog[0].quantity = 10;

    catalog[1].productID = 2;
    strcpy(catalog[1].name, "Smartphone");
    strcpy(catalog[1].description, "5.5-inch display with Snapdragon 888");
    catalog[1].price = 499.99;
    catalog[1].quantity = 20;

    catalog[2].productID = 3;
    strcpy(catalog[2].name, "Headphones");
    strcpy(catalog[2].description, "Noise-cancelling over-ear headphones");
    catalog[2].price = 150.50;
    catalog[2].quantity = 30;

    catalog[3].productID = 4;
    strcpy(catalog[3].name, "Tablet");
    strcpy(catalog[3].description, "10-inch tablet with 4GB RAM");
    catalog[3].price = 299.99;
    catalog[3].quantity = 15;

    catalog[4].productID = 5;
    strcpy(catalog[4].name, "Smartwatch");
    strcpy(catalog[4].description, "Fitness smartwatch with heart-rate monitor");
    catalog[4].price = 199.99;
    catalog[4].quantity = 25;
}

void displayProduct(Product product) {
    printf("| %-2d | %-15s | %-30s | $%-6.2f | %-8d |\n", 
           product.productID, product.name, product.description, product.price, product.quantity);
}

void searchByName(char *searchTerm) {
    int found = 0;
    printf("Search Results:\n");
    printf("\n");
    printf("| ID | Name  | Description  | Price  | Quantity |\n");
    printf("\n");

    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (strstr(catalog[i].name, searchTerm) != NULL) {
            displayProduct(catalog[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("No products found with the name '%s'.\n", searchTerm);
    }
    printf("\n");
}

void searchByID(int id) {
    int found = 0;
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (catalog[i].productID == id) {
            printf("Product Found:\n");
            printf("\n");
            printf("| ID | Name | Description  | Price  | Quantity |\n");
            printf("\n");
            displayProduct(catalog[i]);
            printf("\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Product with ID %d not found.\n", id);
    }
}

void searchByDescription(char *searchTerm) {
    int found = 0;
    printf("Search Results:\n");
    printf("\n");
    printf("| ID | Name  | Description | Price  | Quantity |\n");
    printf("\n");

    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (strstr(catalog[i].description, searchTerm) != NULL) {
            displayProduct(catalog[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("No products found with the description '%s'.\n", searchTerm);
    }
    printf("\n");
}

int main() {
    int choice, id;
    char searchTerm[NAME_LEN];

    initializeCatalog();

    while (1) {
        printf("\nSearch Menu\n");
        printf("1. Search by Name\n");
        printf("2. Search by ID\n");
        printf("3. Search by Description\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                printf("Enter product name to search: ");
                fgets(searchTerm, NAME_LEN, stdin);
                searchTerm[strcspn(searchTerm, "\n")] = '\0';  
                searchByName(searchTerm);
                break;
            case 2:
                printf("Enter product ID to search: ");
                scanf("%d", &id);
                searchByID(id);
                break;
            case 3:
                printf("Enter description to search: ");
                fgets(searchTerm, NAME_LEN, stdin);
                searchTerm[strcspn(searchTerm, "\n")] = '\0';  
                searchByDescription(searchTerm);
                break;
            case 4:
                printf("Exiting search system.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
