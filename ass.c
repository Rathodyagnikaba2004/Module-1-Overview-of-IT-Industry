#include <stdio.h>
#include <string.h>

// Structure to hold food item details
struct FoodItem {
    int id;
    char name[30];
    float price;
};

// Predefined food menu
struct FoodItem menu[] = {
    {1, "noodle", 250.0},
    {2, "Burger", 12............0.0},
    {3, "Sandwich", 100.0},                
    {4, "Pasta", 180.0},
    {5, "French Fries", 80.0}
};

#define MENU_SIZE sizeof(menu)/sizeof(menu[0])

// Function to display food menu
void displayMenu() {
    printf("\n===== Available Food Items =====\n");  
    for (int i = 0; i < MENU_SIZE; i++) {
        printf("%d. %-15s ₹%.2f\n", menu[i].id, menu[i].name, menu[i].price);
    }
    printf("================================\n");
}

// Function to get food price based on ID 
float getFoodPrice(int id) {
    for (int i = 0; i < MENU_SIZE; i++) {
        if (menu[i].id == id) {
            return menu[i].price;
        }
    }
    return 0.0; // If invalid ID
}

// Function to get food nam e
char* getFoodName(int id) {
    for (int i = 0; i < MENU_SIZE; i++) {   
        if (menu[i].id == id) {
     return menu[i].name;
        }
    }
    return "Unknown Item";
}

int main() {
    int foodID, quantity;
    char choice;
    float totalBill = 0.0;

    printf("******** Welcome to Food Billing System ********\n");

    do {
        // Step 1: Display the menu
        displayMenu();

        // Step 2: Take order
        printf("Enter the food item number you want to order: ");
        scanf("%d", &foodID);

        // Step 3: Get quantity
        printf("Enter quantity for %s: ", getFoodName(foodID));
        scanf("%d", &quantity);

        // Step 4: Calculate subtotal and add to total
        float itemPrice = getFoodPrice(foodID);
        float subtotal = itemPrice * quantity;

        if (itemPrice == 0.0) {
            printf("Invalid item selected. Please try again.\n");
        } else {
            totalBill += subtotal;
            printf("You added %d x %s (₹%.2f each) = ₹%.2f to your bill.\n", quantity, getFoodName(foodID), itemPrice, subtotal);
        }

        // Step 5: Ask user to continue
        printf("Do you want to order more items? (y/n): ");
        scanf(" %c", &choice);  // Space before %c to consume newline

    } while (choice == 'y' || choice == 'Y');

    // Step 6: Final Bill
    printf("\n******** Final Bill ********\n");
    printf("Total Amount to Pay: ₹%.2f\n", totalBill);
    printf("Thank you for your order! Visit again.\n");

    return 0;
}
