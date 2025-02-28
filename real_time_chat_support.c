#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_MESSAGES 100
#define MAX_LENGTH 256

typedef struct {
    char sender[MAX_LENGTH];
    char message[MAX_LENGTH];
} ChatMessage;

ChatMessage messages[MAX_MESSAGES];
int messageCount = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* sendMessage(void* arg) {
    char sender[MAX_LENGTH], message[MAX_LENGTH];

    while (1) {
        printf("Enter your name: ");
        fgets(sender, MAX_LENGTH, stdin);
        sender[strcspn(sender, "\n")] = '\0'; 
        
        printf("Enter message: ");
        fgets(message, MAX_LENGTH, stdin);
        message[strcspn(message, "\n")] = '\0';  

        pthread_mutex_lock(&mutex);
        if (messageCount < MAX_MESSAGES) {
            strcpy(messages[messageCount].sender, sender);
            strcpy(messages[messageCount].message, message);
            messageCount++;
        }
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

void* receiveMessage(void* arg) {
    while (1) {
        pthread_mutex_lock(&mutex);
        if (messageCount > 0) {
            printf("\nMessages:\n");
            for (int i = 0; i < messageCount; i++) {
                printf("%s: %s\n", messages[i].sender, messages[i].message);
            }
        }
        pthread_mutex_unlock(&mutex);
        sleep(1);  
    }
    return NULL;
}

void showMenu() {
    printf("\nReal-Time Chat Support System\n");
    printf("1. Start Chat\n");
    printf("2. Exit\n");
}

int main() {
    pthread_t senderThread, receiverThread;
    int choice;

    while (1) {
        showMenu();
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();  

        switch (choice) {
            case 1:
                pthread_create(&senderThread, NULL, sendMessage, NULL);
                pthread_create(&receiverThread, NULL, receiveMessage, NULL);
                pthread_join(senderThread, NULL);
                pthread_join(receiverThread, NULL);
                break;
            case 2:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
