#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_USERS 100
#define MAX_LENGTH 50

typedef struct {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} User;

User users[MAX_USERS];
int userCount = 0;

void registerUser() {
    if (userCount >= MAX_USERS) {
        printf("User limit reached. Cannot register more users.\n");
        return;
    }
    
    char username[MAX_LENGTH], password[MAX_LENGTH];
    printf("Enter username: ");
    scanf("%s", username);
    
    printf("Enter password: ");
    scanf("%s", password);
    
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0) {
            printf("Username already exists. Please try a different one.\n");
            return;
        }
    }
    
    strcpy(users[userCount].username, username);
    strcpy(users[userCount].password, password);
    userCount++;
    
    printf("Registration successful!\n");
}

int authenticateUser() {
    char username[MAX_LENGTH], password[MAX_LENGTH];
    printf("Enter username: ");
    scanf("%s", username);
    
    printf("Enter password: ");
    scanf("%s", password);
    
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return 1;
        }
    }
    
    return 0;
}

void displayMenu() {
    printf("\n--- Main Menu ---\n");
    printf("1. Register\n");
    printf("2. Login\n");
    printf("3. Exit\n");
    printf("Enter choice: ");
}

int main() {
    int choice, authenticated = 0;
    
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                registerUser();
                break;
                
            case 2:
                authenticated = authenticateUser();
                if (authenticated) {
                    printf("Login successful! Welcome.\n");
                } else {
                    printf("Invalid username or password.\n");
                }
                break;
                
            case 3:
                printf("Exiting the system. Goodbye!\n");
                exit(0);
                
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}
