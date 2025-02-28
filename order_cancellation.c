#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PRODUCTS 10
#define MAX_ORDERS 5
#define NAME_LEN 50

typedef struct {
    char productName[NAME_LEN];
    float price;
    int quantity;
} Product;

typedef struct {
    char orderID[10];
    Product orderedProduct;
    char orderStatus[20];
} Order;

Product products[MAX_PRODUCTS];
Order orders[MAX_ORDERS];
int orderCount = 0;

void initializeProducts() {
    strcpy(products[0].productName, "Laptop");
    products[0].price = 899.99;
    products[0].quantity = 50;

    strcpy(products[1].productName, "Smartphone");
    products[1].price = 499.99;
    products[1].quantity = 30;
}

void placeOrder(int productIndex, int quantity) {
    if (products[productIndex].quantity >= quantity) {
        Order newOrder;
        sprintf(newOrder.orderID, "ORD%03d", orderCount + 1);
        newOrder.orderedProduct = products[productIndex];
        newOrder.orderedProduct.quantity = quantity;
        strcpy(newOrder.orderStatus, "Placed");

        orders[orderCount] = newOrder;
        orderCount++;

        products[productIndex].quantity -= quantity;
        printf("Order placed successfully! Order ID: %s\n", newOrder.orderID);
    } else {
        printf("Insufficient stock for %s.\n", products[productIndex].productName);
    }
}

void cancelOrder(char *orderID) {
    for (int i = 0; i < orderCount; i++) {
        if (strcmp(orders[i].orderID, orderID) == 0) {
            if (strcmp(orders[i].orderStatus, "Placed") == 0) {
                printf("Order %s cancelled successfully.\n", orderID);
                orders[i].orderedProduct.quantity += orders[i].orderedProduct.quantity;
                strcpy(orders[i].orderStatus, "Cancelled");
                return;
            } else {
                printf("Order %s cannot be cancelled as it's already shipped.\n", orderID);
                return;
            }
        }
    }
    printf("Order ID %s not found.\n", orderID);
}

void viewOrders() {
    printf("\nYour Orders:\n");
    for (int i = 0; i < orderCount; i++) {
        printf("Order ID: %s | Product: %s | Quantity: %d | Status: %s\n",
               orders[i].orderID, orders[i].orderedProduct.productName, orders[i].orderedProduct.quantity, orders[i].orderStatus);
    }
}

void showMenu() {
    printf("\nOrder Cancellation\n");
    printf("1. Place Order\n");
    printf("2. Cancel Order\n");
    printf("3. View Orders\n");
    printf("4. Exit\n");
}

int main() {
    int choice, productIndex, quantity;
    char orderID[10];

    initializeProducts();

    while (1) {
        showMenu();
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();  

        switch (choice) {
            case 1:
                printf("Enter product index (0 for Laptop, 1 for Smartphone): ");
                scanf("%d", &productIndex);
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                placeOrder(productIndex, quantity);
                break;
            case 2:
                printf("Enter order ID to cancel: ");
                scanf("%s", orderID);
                cancelOrder(orderID);
                break;
            case 3:
                viewOrders();
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
