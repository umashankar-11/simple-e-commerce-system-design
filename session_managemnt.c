#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_USERS 5
#define MAX_SESSIONS 5
#define MAX_LENGTH 50

typedef struct {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} User;

typedef struct {
    char username[MAX_LENGTH];
    int isActive;
} Session;

User users[MAX_USERS];
Session sessions[MAX_SESSIONS];

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

int authenticateUser(char* username, char* password) {
    for (int i = 0; i < MAX_USERS; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return 1;
        }
    }
    return 0;
}

void createSession(char* username) {
    for (int i = 0; i < MAX_SESSIONS; i++) {
        if (!sessions[i].isActive) {
            strcpy(sessions[i].username, username);
            sessions[i].isActive = 1;
            printf("Session created for %s\n", username);
            return;
        }
    }
    printf("Maximum sessions reached.\n");
}

void endSession(char* username) {
    for (int i = 0; i < MAX_SESSIONS; i++) {
        if (sessions[i].isActive && strcmp(sessions[i].username, username) == 0) {
            sessions[i].isActive = 0;
            printf("Session ended for %s\n", username);
            return;
        }
    }
    printf("No active session found for %s\n", username);
}

void showMenu() {
    printf("\nSession Management System\n");
    printf("1. Login\n");
    printf("2. Logout\n");
    printf("3. Exit\n");
}

int main() {
    int choice;
    char username[MAX_LENGTH], password[MAX_LENGTH];

    initializeUsers();

    while (1) {
        showMenu();
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();  

        switch (choice) {
            case 1:
                printf("Enter username: ");
                fgets(username, MAX_LENGTH, stdin);
                username[strcspn(username, "\n")] = '\0';  

                printf("Enter password: ");
                fgets(password, MAX_LENGTH, stdin);
                password[strcspn(password, "\n")] = '\0';  

                if (authenticateUser(username, password)) {
                    createSession(username);
                } else {
                    printf("Invalid credentials!\n");
                }
                break;
            case 2:
                printf("Enter username to logout: ");
                fgets(username, MAX_LENGTH, stdin);
                username[strcspn(username, "\n")] = '\0';  
                endSession(username);
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
