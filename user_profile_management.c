#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_USERS 5
#define NAME_LEN 50
#define EMAIL_LEN 50

typedef struct {
    char username[NAME_LEN];
    char password[NAME_LEN];
    char email[EMAIL_LEN];
    int age;
} User;

User users[MAX_USERS];

void initializeUsers() {
    strcpy(users[0].username, "admin");
    strcpy(users[0].password, "admin123");
    strcpy(users[0].email, "admin@example.com");
    users[0].age = 30;

    strcpy(users[1].username, "user1");
    strcpy(users[1].password, "password1");
    strcpy(users[1].email, "user1@example.com");
    users[1].age = 25;
}

int findUserByUsername(char *username) {
    for (int i = 0; i < MAX_USERS; i++) {
        if (strcmp(users[i].username, username) == 0) {
            return i;
        }
    }
    return -1;
}

void updateProfile(int index) {
    printf("Enter new password: ");
    fgets(users[index].password, NAME_LEN, stdin);
    users[index].password[strcspn(users[index].password, "\n")] = '\0';  

    printf("Enter new email: ");
    fgets(users[index].email, EMAIL_LEN, stdin);
    users[index].email[strcspn(users[index].email, "\n")] = '\0';  

    printf("Enter new age: ");
    scanf("%d", &users[index].age);
    getchar();  

    printf("Profile updated successfully!\n");
}

void viewProfile(int index) {
    printf("Username: %s\n", users[index].username);
    printf("Email: %s\n", users[index].email);
    printf("Age: %d\n", users[index].age);
}

int main() {
    int choice, userIndex;
    char username[NAME_LEN];

    initializeUsers();

    while (1) {
        printf("\n1. View Profile\n2. Update Profile\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);
        getchar();  

        switch (choice) {
            case 1:
                printf("Enter username to view profile: ");
                fgets(username, NAME_LEN, stdin);
                username[strcspn(username, "\n")] = '\0';  

                userIndex = findUserByUsername(username);
                if (userIndex != -1) {
                    viewProfile(userIndex);
                } else {
                    printf("User not found!\n");
                }
                break;
            case 2:
                printf("Enter username to update profile: ");
                fgets(username, NAME_LEN, stdin);
                username[strcspn(username, "\n")] = '\0';  

                userIndex = findUserByUsername(username);
                if (userIndex != -1) {
                    updateProfile(userIndex);
                } else {
                    printf("User not found!\n");
                }
                break;
            case 3:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
