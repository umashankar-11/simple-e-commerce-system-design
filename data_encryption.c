#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_USERS 5
#define MAX_LENGTH 100

typedef struct {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} User;

User users[MAX_USERS];

void encrypt(char* input, char* output) {
    for (int i = 0; input[i] != '\0'; i++) {
        output[i] = input[i] + 5;  
    }
    output[strlen(input)] = '\0';
}

void decrypt(char* input, char* output) {
    for (int i = 0; input[i] != '\0'; i++) {
        output[i] = input[i] - 5;  
    }
    output[strlen(input)] = '\0';
}

void initializeUsers() {
    strcpy(users[0].username, "user1");
    strcpy(users[0].password, "password123");

    strcpy(users[1].username, "user2");
    strcpy(users[1].password, "123456789");

    strcpy(users[2].username, "user3");
    strcpy(users[2].password, "qwertyuiop");

    strcpy(users[3].username, "user4");
    strcpy(users[3].password, "mypassword");

    strcpy(users[4].username, "user5");
    strcpy(users[4].password, "adminadmin");
}

void displayUsers() {
    char decryptedPassword[MAX_LENGTH];
    printf("\nUser List:\n");
    for (int i = 0; i < MAX_USERS; i++) {
        decrypt(users[i].password, decryptedPassword);
        printf("Username: %s, Password: %s\n", users[i].username, decryptedPassword);
    }
}

void authenticate(char* username, char* password) {
    char encryptedPassword[MAX_LENGTH];
    encrypt(password, encryptedPassword);

    for (int i = 0; i < MAX_USERS; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, encryptedPassword) == 0) {
            printf("Authentication successful for %s\n", username);
            return;
        }
    }
    printf("Authentication failed for %s\n", username);
}

void showMenu() {
    printf("\nE-commerce System with Data Encryption\n");
    printf("1. View Users\n");
    printf("2. Authenticate User\n");
    printf("3. Exit\n");
}

int main() {
    int choice;
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];

    initializeUsers();

    while (1) {
        showMenu();
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();  

        switch (choice) {
            case 1:
                displayUsers();
                break;
            case 2:
                printf("Enter username: ");
                fgets(username, MAX_LENGTH, stdin);
                username[strcspn(username, "\n")] = '\0';  
                printf("Enter password: ");
                fgets(password, MAX_LENGTH, stdin);
                password[strcspn(password, "\n")] = '\0';  
                authenticate(username, password);
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
