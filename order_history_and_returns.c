#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ORDERS 10
#define ORDER_ID_LEN 20
#define PRODUCT_NAME_LEN 50

typedef struct {
    char orderID[ORDER_ID_LEN];
    char productName[PRODUCT_NAME_LEN];
    int quantity;
    float totalPrice;
    char status[20];
} Order;

Order orders[MAX_ORDERS];

void initializeOrders() {
    strcpy(orders[0].orderID, "ORD001");
    strcpy(orders[0].productName, "Laptop");
    orders[0].quantity = 1;
    orders[0].totalPrice = 899.99;
    strcpy(orders[0].status, "Delivered");

    strcpy(orders[1].orderID, "ORD002");
    strcpy(orders[1].productName, "Smartphone");
    orders[1].quantity = 2;
    orders[1].totalPrice = 999.98;
    strcpy(orders[1].status, "Delivered");
}

void viewOrderHistory() {
    printf("Order History:\n");
    printf("| Order ID | Product Name  | Quantity | Total Price | Status  |\n");
    printf("\n");
    for (int i = 0; i < MAX_ORDERS; i++) {
        if (strlen(orders[i].orderID) > 0) {
            printf("| %-8s | %-13s | %-8d | $%-10.2f | %-7s |\n", orders[i].orderID, orders[i].productName, orders[i].quantity, orders[i].totalPrice, orders[i].status);
        }
    }
    printf("\n");
}

void processReturn(char *orderID) {
    for (int i = 0; i < MAX_ORDERS; i++) {
        if (strcmp(orders[i].orderID, orderID) == 0 && strcmp(orders[i].status, "Delivered") == 0) {
            strcpy(orders[i].status, "Returned");
            printf("Order ID %s has been successfully returned.\n", orderID);
            return;
        }
    }
    printf("Order with ID %s cannot be returned.\n", orderID);
}

int main() {
    int choice;
    char orderID[ORDER_ID_LEN];

    initializeOrders();

    while (1) {
        printf("\nOrder History and Returns\n");
        printf("1. View Order History\n");
        printf("2. Return an Order\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();  

        switch (choice) {
            case 1:
                viewOrderHistory();
                break;
            case 2:
                printf("Enter Order ID to return: ");
                fgets(orderID, ORDER_ID_LEN, stdin);
                orderID[strcspn(orderID, "\n")] = '\0';  
                processReturn(orderID);
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
