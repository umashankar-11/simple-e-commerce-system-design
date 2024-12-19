#include <stdio.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_USERNAME_LEN 50
#define MAX_PASSWORD_LEN 50
#define MAX_PRODUCTS 100
#define MAX_PRODUCT_NAME_LEN 100
#define MAX_CART_ITEMS 10


typedef struct {
    char username[MAX_USERNAME_LEN];
    char password[MAX_PASSWORD_LEN];
} User;

typedef struct {
    char name[MAX_PRODUCT_NAME_LEN];
    float price;
} Product;

typedef struct {
    int productIndex;
    int quantity;
} CartItem;


User users[MAX_USERS];
Product products[MAX_PRODUCTS];
CartItem cart[MAX_CART_ITEMS];


int userCount = 0;
int productCount = 0;
int cartItemCount = 0;


void loadUsers() {
    FILE *file = fopen("users.txt", "r");
    if (file == NULL) return;

    while (fscanf(file, "%s %s\n", users[userCount].username, users[userCount].password) != EOF) {
        userCount++;
    }

    fclose(file);
}


void saveUsers() {
    FILE *file = fopen("users.txt", "w");
    for (int i = 0; i < userCount; i++) {
        fprintf(file, "%s %s\n", users[i].username, users[i].password);
    }
    fclose(file);
}


int authenticate(char *username, char *password) {
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return 1;
        }
    }
    return 0;
}


void signup() {
    if (userCount >= MAX_USERS) {
        printf("User limit reached.\n");
        return;
    }
    char username[MAX_USERNAME_LEN], password[MAX_PASSWORD_LEN];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    strcpy(users[userCount].username, username);
    strcpy(users[userCount].password, password);
    userCount++;

    saveUsers();
    printf("Signup successful!\n");
}


int login() {
    char username[MAX_USERNAME_LEN], password[MAX_PASSWORD_LEN];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    if (authenticate(username, password)) {
        printf("Login successful!\n");
        return 1;
    } else {
        printf("Invalid credentials.\n");
        return 0;
    }
}


void loadProducts() {
    FILE *file = fopen("products.txt", "r");
    if (file == NULL) return;

    while (fscanf(file, "%s %f\n", products[productCount].name, &products[productCount].price) != EOF) {
        productCount++;
    }

    fclose(file);
}


void displayProducts() {
    printf("Product Catalog:\n");
    for (int i = 0; i < productCount; i++) {
        printf("%d. %s - $%.2f\n", i + 1, products[i].name, products[i].price);
    }
}


void addToCart(int productIndex, int quantity) {
    if (cartItemCount < MAX_CART_ITEMS) {
        cart[cartItemCount].productIndex = productIndex;
        cart[cartItemCount].quantity = quantity;
        cartItemCount++;
        printf("Added to cart.\n");
    } else {
        printf("Cart is full.\n");
    }
}


void viewCart() {
    printf("Shopping Cart:\n");
    float total = 0;
    for (int i = 0; i < cartItemCount; i++) {
        int productIndex = cart[i].productIndex;
        printf("%d. %s - $%.2f x %d\n", i + 1, products[productIndex].name, products[productIndex].price, cart[i].quantity);
        total += products[productIndex].price * cart[i].quantity;
    }
    printf("Total: $%.2f\n", total);
}


void removeFromCart(int index) {
    if (index < 0 || index >= cartItemCount) {
        printf("Invalid cart item.\n");
        return;
    }
    for (int i = index; i < cartItemCount - 1; i++) {
        cart[i] = cart[i + 1];
    }
    cartItemCount--;
    printf("Item removed from cart.\n");
}


void placeOrder() {
    printf("Placing order...\n");
    viewCart();
    printf("Order placed successfully!\n");
    cartItemCount = 0;  // Clear cart after placing order
}


void displayMenu() {
    printf("\n1. Login\n");
    printf("2. Signup\n");
    printf("3. View Products\n");
    printf("4. Add to Cart\n");
    printf("5. View Cart\n");
    printf("6. Remove from Cart\n");
    printf("7. Place Order\n");
    printf("8. Exit\n");
}


int main() {
    loadUsers();
    loadProducts();
    
    int loggedIn = 0;
    int choice;

    while (1) {
        displayMenu();
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            loggedIn = login();
        } else if (choice == 2) {
            signup();
        } else if (choice == 3) {
            displayProducts();
        } else if (choice == 4) {
            if (loggedIn) {
                int productIndex, quantity;
                printf("Enter product number: ");
                scanf("%d", &productIndex);
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                addToCart(productIndex - 1, quantity);
            } else {
                printf("Please login first.\n");
            }
        } else if (choice == 5) {
            if (loggedIn) {
                viewCart();
            } else {
                printf("Please login first.\n");
            }
        } else if (choice == 6) {
            if (loggedIn) {
                int index;
                printf("Enter item number to remove: ");
                scanf("%d", &index);
                removeFromCart(index - 1);
            } else {
                printf("Please login first.\n");
            }
        } else if (choice == 7) {
            if (loggedIn) {
                placeOrder();
            } else {
                printf("Please login first.\n");
            }
        } else if (choice == 8) {
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
