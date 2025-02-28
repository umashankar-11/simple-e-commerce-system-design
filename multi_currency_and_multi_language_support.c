#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PRODUCTS 5
#define NAME_LEN 50
#define MAX_LANGUAGES 3
#define MAX_CURRENCIES 3

typedef struct {
    char productName[NAME_LEN];
    float price;
} Product;

typedef struct {
    char language[NAME_LEN];
    char greeting[100];
} Language;

typedef struct {
    char currency[NAME_LEN];
    float conversionRate;
} Currency;

Product products[MAX_PRODUCTS];
Language languages[MAX_LANGUAGES];
Currency currencies[MAX_CURRENCIES];

void initializeProducts() {
    strcpy(products[0].productName, "Laptop");
    products[0].price = 899.99;

    strcpy(products[1].productName, "Smartphone");
    products[1].price = 499.99;

    strcpy(products[2].productName, "Headphones");
    products[2].price = 199.99;

    strcpy(products[3].productName, "Smartwatch");
    products[3].price = 299.99;

    strcpy(products[4].productName, "Tablet");
    products[4].price = 399.99;
}

void initializeLanguages() {
    strcpy(languages[0].language, "English");
    strcpy(languages[0].greeting, "Hello!");

    strcpy(languages[1].language, "Spanish");
    strcpy(languages[1].greeting, "¡Hola!");

    strcpy(languages[2].language, "French");
    strcpy(languages[2].greeting, "Bonjour!");
}

void initializeCurrencies() {
    strcpy(currencies[0].currency, "USD");
    currencies[0].conversionRate = 1.0;

    strcpy(currencies[1].currency, "EUR");
    currencies[1].conversionRate = 0.85;

    strcpy(currencies[2].currency, "GBP");
    currencies[2].conversionRate = 0.75;
}

void displayProducts(int currencyIndex) {
    printf("\nAvailable Products:\n");
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        printf("%s | Price: %.2f %s\n", products[i].productName, products[i].price * currencies[currencyIndex].conversionRate, currencies[currencyIndex].currency);
    }
}

void displayGreeting(int languageIndex) {
    printf("\nGreeting in %s: %s\n", languages[languageIndex].language, languages[languageIndex].greeting);
}

void showMenu() {
    printf("\nMulti-Currency and Multi-Language Support\n");
    printf("1. View Products\n");
    printf("2. View Greeting\n");
    printf("3. Exit\n");
}

int main() {
    int choice, langIndex, currencyIndex;
    
    initializeProducts();
    initializeLanguages();
    initializeCurrencies();

    while (1) {
        showMenu();
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();  

        switch (choice) {
            case 1:
                printf("Enter currency index (0 for USD, 1 for EUR, 2 for GBP): ");
                scanf("%d", &currencyIndex);
                if (currencyIndex >= 0 && currencyIndex < MAX_CURRENCIES) {
                    displayProducts(currencyIndex);
                } else {
                    printf("Invalid currency index.\n");
                }
                break;
            case 2:
                printf("Enter language index (0 for English, 1 for Spanish, 2 for French): ");
                scanf("%d", &langIndex);
                if (langIndex >= 0 && langIndex < MAX_LANGUAGES) {
                    displayGreeting(langIndex);
                } else {
                    printf("Invalid language index.\n");
                }
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
