#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PAYMENTS 10
#define PAYMENT_ID_LEN 20
#define CARD_NUMBER_LEN 20

typedef struct {
    char paymentID[PAYMENT_ID_LEN];
    char cardNumber[CARD_NUMBER_LEN];
    float amount;
    char status[20];
} Payment;

Payment payments[MAX_PAYMENTS];

void initializePayments() {
    strcpy(payments[0].paymentID, "PAY001");
    strcpy(payments[0].cardNumber, "1234-5678-9876-5432");
    payments[0].amount = 199.99;
    strcpy(payments[0].status, "Completed");

    strcpy(payments[1].paymentID, "PAY002");
    strcpy(payments[1].cardNumber, "2345-6789-8765-4321");
    payments[1].amount = 299.99;
    strcpy(payments[1].status, "Pending");
}

void viewPaymentStatus(char *paymentID) {
    for (int i = 0; i < MAX_PAYMENTS; i++) {
        if (strcmp(payments[i].paymentID, paymentID) == 0) {
            printf("Payment ID: %s\n", payments[i].paymentID);
            printf("Card Number: %s\n", payments[i].cardNumber);
            printf("Amount: $%.2f\n", payments[i].amount);
            printf("Status: %s\n", payments[i].status);
            return;
        }
    }
    printf("Payment with ID %s not found.\n", paymentID);
}

void updatePaymentStatus(char *paymentID, char *status) {
    for (int i = 0; i < MAX_PAYMENTS; i++) {
        if (strcmp(payments[i].paymentID, paymentID) == 0) {
            strcpy(payments[i].status, status);
            printf("Payment ID %s status updated to '%s'.\n", paymentID, status);
            return;
        }
    }
    printf("Payment with ID %s not found.\n", paymentID);
}

void processPayment(char *paymentID, char *cardNumber, float amount) {
    printf("Processing payment...\n");
    printf("Payment ID: %s\n", paymentID);
    printf("Card Number: %s\n", cardNumber);
    printf("Amount: $%.2f\n", amount);
    printf("Payment Completed Successfully!\n");
}

int main() {
    int choice;
    char paymentID[PAYMENT_ID_LEN], status[20], cardNumber[CARD_NUMBER_LEN];
    float amount;

    initializePayments();

    while (1) {
        printf("\nPayment Integration System\n");
        printf("1. View Payment Status\n");
        printf("2. Update Payment Status\n");
        printf("3. Process Payment\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();  

        switch (choice) {
            case 1:
                printf("Enter Payment ID to view status: ");
                fgets(paymentID, PAYMENT_ID_LEN, stdin);
                paymentID[strcspn(paymentID, "\n")] = '\0';  
                viewPaymentStatus(paymentID);
                break;
            case 2:
                printf("Enter Payment ID to update status: ");
                fgets(paymentID, PAYMENT_ID_LEN, stdin);
                paymentID[strcspn(paymentID, "\n")] = '\0';  
                printf("Enter new status: ");
                fgets(status, 20, stdin);
                status[strcspn(status, "\n")] = '\0';  
                updatePaymentStatus(paymentID, status);
                break;
            case 3:
                printf("Enter Payment ID: ");
                fgets(paymentID, PAYMENT_ID_LEN, stdin);
                paymentID[strcspn(paymentID, "\n")] = '\0';  
                printf("Enter Card Number: ");
                fgets(cardNumber, CARD_NUMBER_LEN, stdin);
                cardNumber[strcspn(cardNumber, "\n")] = '\0';  
                printf("Enter Amount: ");
                scanf("%f", &amount);
                getchar();  
                processPayment(paymentID, cardNumber, amount);
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
