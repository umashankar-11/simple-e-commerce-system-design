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
    strcpy(orders[0].status, "Confirmed");

    strcpy(orders[1].orderID, "ORD002");
    strcpy(orders[1].productName, "Smartphone");
    orders[1].quantity = 2;
    orders[1].totalPrice = 999.98;
    strcpy(orders[1].status, "Shipped");
}

void viewOrderStatus(char *orderID) {
    for (int i = 0; i < MAX_ORDERS; i++) {
        if (strcmp(orders[i].orderID, orderID) == 0) {
            printf("Order ID: %s\n", orders[i].orderID);
            printf("Product: %s\n", orders[i].productName);
            printf("Quantity: %d\n", orders[i].quantity);
            printf("Total Price: $%.2f\n", orders[i].totalPrice);
            printf("Status: %s\n", orders[i].status);
            return;
        }
    }
    printf("Order with ID %s not found.\n", orderID);
}

void updateOrderStatus(char *orderID, char *status) {
    for (int i = 0; i < MAX_ORDERS; i++) {
        if (strcmp(orders[i].orderID, orderID) == 0) {
            strcpy(orders[i].status, status);
            printf("Order ID %s status updated to '%s'.\n", orderID, status);
            return;
        }
    }
    printf("Order with ID %s not found.\n", orderID);
}

int main() {
    int choice;
    char orderID[ORDER_ID_LEN], status[20];

    initializeOrders();

    while (1) {
        printf("\nOrder Confirmation & Tracking\n");
        printf("1. View Order Status\n");
        printf("2. Update Order Status\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();  

        switch (choice) {
            case 1:
                printf("Enter Order ID to view status: ");
                fgets(orderID, ORDER_ID_LEN, stdin);
                orderID[strcspn(orderID, "\n")] = '\0';  
                viewOrderStatus(orderID);
                break;
            case 2:
                printf("Enter Order ID to update status: ");
                fgets(orderID, ORDER_ID_LEN, stdin);
                orderID[strcspn(orderID, "\n")] = '\0'; 
                printf("Enter new status: ");
                fgets(status, 20, stdin);
                status[strcspn(status, "\n")] = '\0';  
                updateOrderStatus(orderID, status);
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
