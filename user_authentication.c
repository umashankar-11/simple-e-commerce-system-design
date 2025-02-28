#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_USERS 5
#define USERNAME_LEN 50
#define PASSWORD_LEN 50

typedef struct {
    char username[USERNAME_LEN];
    char password[PASSWORD_LEN];
} User;

User users[MAX_USERS];

void initializeUsers() {
    
    strcpy(users[0].username, "user1");
    strcpy(users[0].password, "password1");
    
    strcpy(users[1].username, "user2");
    strcpy(users[1].password, "password2");
    
    strcpy(users[2].username, "user3");
    strcpy(users[2].password, "password3");
    
    strcpy(users[3].username, "user4");
    strcpy(users[3].password, "password4");
    
    strcpy(users[4].username, "user5");
    strcpy(users[4].password, "password5");
}

int authenticateUser(char *username, char *password) {
    for (int i = 0; i < MAX_USERS; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return 1; 
        }
    }
    return 0; 
}

int main() {
    char username[USERNAME_LEN];
    char password[PASSWORD_LEN];
    
    initializeUsers();
    
    printf("Enter username: ");
    fgets(username, USERNAME_LEN, stdin);
    username[strcspn(username, "\n")] = '\0';  
    
    printf("Enter password: ");
    fgets(password, PASSWORD_LEN, stdin);
    password[strcspn(password, "\n")] = '\0';  
    
    if (authenticateUser(username, password)) {
        printf("Login successful!\n");
    } else {
        printf("Invalid username or password.\n");
    }

    return 0;
}
