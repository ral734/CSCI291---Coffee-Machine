#include <stdio.h>
#include <stdlib.h>

// for espresso

#define espressobeans 8
#define espressowater 30
#define espressomilk 0
#define espressochocolatesyrup 0
static float espresso_price=3.5; // Define prices as static variables

// for cappucino

#define cappucinobeans 8
#define cappucinowater 30
#define cappucinomilk 70
#define cappucinochocolatesyrup 0
static float cappucino_price=4.5; // Define prices as static variables

// for mocha

#define mochabeans 8
#define mochawater 39
#define mochamilk 160
#define mochachocolatesyrup 30
static float mocha_price=5.5; // Define prices as static variables

// Define admin password

#define adminpassword 123456

// Define low threshold values for ingredients
#define lowthreshold_beans 50
#define lowthreshold_water 150
#define lowthreshold_milk 230
#define lowthreshold_chocolatesyrup 50

// Function prototypes
void order_coffee(int choice);
void espresso();
void cappucino();
void mocha();
void admin_mode();
void display_ingredients();
void replenish_ingredients();
void change_coffee_price();
int confirm_selection(int coffee_type, float price);

// Global variables
float total_amount = 0;
int beans = 200;
int water = 1000;
int milk = 1000;
int chocolatesyrup = 1000;

int main() {
    int choice;
    while (1) 
    {
        // Display main menu
        printf("Main Menu: \n");
        printf("1. Order Coffee\n");
        printf("2. Enter Admin Mode\n");
        printf("3. End\n");

        // Get user choice
        printf("Enter your desired choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            // Display coffee menu
            printf("Select choice of Coffee:\n");
            printf("1. Espresso\n");
            printf("2. Cappucino\n");
            printf("3. Mocha\n");
            scanf("%d", &choice);
            
            // Order coffee
            order_coffee(choice);
        } 
        else if (choice == 2) 
        {
            // Enter admin mode
            admin_mode();
        } 
        else if (choice == 3) 
        {
            // End program
            printf("Exiting program.\n");
            break;
        } 
        else 
        {
            // Invalid choice
            printf("Invalid choice.\n");
        }
    }

    return 0;
}

// Function to order coffee
void order_coffee(int choice) 
{
    // Check if ingredients are available
    switch (choice) 
    {
        case 1:
            if (beans >= espressobeans && water >= espressowater) 
            {
                // Confirm selection
                if (confirm_selection(1, espresso_price)) 
                {
                    espresso();
                }
            } 
            else 
            {
                // Ingredients not available
                printf("Espresso: Unavailable due to temporarily insufficient ingredients.\n");
            }
            break;
        case 2:
            if (beans >= cappucinobeans && water >= cappucinowater && milk >= cappucinomilk) 
            {
                // Confirm selection
                if (confirm_selection(2, cappucino_price)) 
                {
                    cappucino();
                }
            } 
            else 
            {
                // Ingredients not available
                printf("Cappucino: Unavailable due to temporarily insufficient ingredients.\n");
            }
            break;
        case 3:
            if (beans >= mochabeans && water >=mochawater && milk >= mochamilk && chocolatesyrup >= mochachocolatesyrup) 
            {
                // Confirm selection
                if (confirm_selection(3, mocha_price)) 
                {
                    // Make mocha
                    mocha();
                }
            } 
            else 
            {
                // Ingredients not available
                printf("Mocha: Unavailable due to temporarily insufficient ingredients.\n");
            }
            break;
        default:
        // Invalid coffee choice
            printf("Invalid coffee choice.\n");
            break;
    }
}

// Function to confirm selection
int confirm_selection(int coffee_type, float price) 
{
    int confirm;
    // Display coffee selection and price
    if (coffee_type == 1) 
    {
        printf("You selected Espresso. Price: %.2f AED\n", price);
    } 
    else if (coffee_type == 2) 
    {
        printf("You selected Cappucino. Price: %.2f AED\n", price);
    } 
    else if (coffee_type == 3) 
    {
        printf("You selected Mocha. Price: %.2f AED\n", price);
    } 
    else 
    {
        printf("Invalid coffee type.\n");
        return 0;
    }
    // confirmation 
    printf("Do you want to proceed? (1 for Yes / 0 for No): ");
    scanf("%d", &confirm);
    return confirm;
}

// function for espresso
void espresso() {
    float pay = 0;
    float coin;
    printf("Selected Espresso, Price: %.2f AED\n", espresso_price);
    while (pay < espresso_price) 
    {
        printf("Insert coin (1 AED or 0.5 AED): ");
        scanf("%f", &coin);
        if (coin == 1 || coin == 0.5) {
            if (pay + coin > espresso_price) 
            {
                printf("Excessive coins inserted. Please add only the amount needed.\n");
            } else 
            {
                pay += coin;
                printf("Total inserted: %.2f AED\n", pay);
            }
        } else 
        {
            printf("Invalid coin. Please insert 1 AED or 0.5 AED.\n");
        }
    }

    if (pay == espresso_price) 
    {
        printf("Successfully Made Espresso!\n");
        total_amount += espresso_price;
        beans -= espressobeans;
        water -= espressowater;
        milk -= espressomilk;
        chocolatesyrup -= espressochocolatesyrup;
    }
}

// function for cappucino
void cappucino() 
{
    float pay = 0;
    float coin;
    printf("Selected Cappucino, Price: %.2f AED\n", cappucino_price);
    while (pay < cappucino_price) 
    {
        printf("Insert coin (1 AED or 0.5 AED): ");
        scanf("%f", &coin);
        if (coin == 1 || coin == 0.5) 
        {
            if (pay + coin > cappucino_price) 
            {
                printf("Excessive coins inserted. Please add only the amount needed.\n");
            } else 
            {
                pay += coin;
                printf("Total inserted: %.2f AED\n", pay);
            }
        } else 
        {
            printf("Invalid coin. Please insert 1 AED or 0.5 AED.\n");
        }
    }

    if (pay == cappucino_price) 
    {
        printf("Successfully Made Cappucino!\n");
        total_amount += cappucino_price;
        beans -= cappucinobeans;
        water -= cappucinowater;
        milk -= cappucinomilk;
        chocolatesyrup -= cappucinochocolatesyrup;
    }
}

// function for mocha
void mocha() 
{
    float pay = 0;
    float coin;
    printf("Selected Mocha, Price: %.2f AED\n", mocha_price);
    while (pay < mocha_price) {
        printf("Insert coin (1 AED or 0.5 AED): ");
        scanf("%f", &coin);
        if (coin == 1 || coin == 0.5) {
            if (pay + coin > mocha_price) 
            {
                printf("Excessive coins inserted. Please add only the amount needed.\n");
            } 
            else 
            {
                pay += coin;
                printf("Total inserted: %.2f AED\n", pay);
            }
        } 
        else 
        {
            printf("Invalid coin. Please insert 1 AED or 0.5 AED.\n");
        }
    }

    if (pay == mocha_price) 
    {
        printf("Successfully Made Mocha!\n");
        total_amount += mocha_price;
        beans -= mochabeans;
        water -= mochawater;
        milk -= mochamilk;
        chocolatesyrup -= mochachocolatesyrup;
    }
}

// function for admin mode
void admin_mode() {
    int password;
    printf("Enter Admin Password: ");
    scanf("%d", &password);

    if (password == adminpassword) 
    {
        int adminmode_choice;
        while (1) 
        {
            printf("Admin Menu:\n");
            printf("1: Display the quantity of each ingredient and total sale amount\n");
            printf("2: Replenish ingredients\n");
            printf("3: Change coffee price\n");
            printf("0: Exit Admin Mode\n");
            printf("Enter your choice: ");
            scanf("%d", &adminmode_choice);

            switch (adminmode_choice) 
            {
                case 1:
                    display_ingredients();
                    break;
                case 2:
                    replenish_ingredients();
                    break;
                case 3:
                    change_coffee_price();
                    break;
                case 0:
                    printf("Exiting Admin Mode.\n");
                    return;
                default:
                    printf("Invalid choice. Please try again.\n");
                    break;
            }
        }
    } 
    else 
    {
        printf("Incorrect password. Access denied.\n");
    }
}

// function to display ingredients and check total sales amount
void display_ingredients() 
{
    printf("Current ingredient levels:\n");
    printf("Beans: %d\n", beans);
    printf("Water: %d\n", water);
    printf("Milk: %d\n", milk);
    printf("Chocolate Syrup: %d\n", chocolatesyrup);
    printf("Total sales amount: %.2f AED\n", total_amount);
   
    // reset total sales amount

    int reset;
    printf("Do you want to reset the total sales amount to zero? (1 for Yes / 0 for No): ");
    scanf("%d", &reset);
    if (reset == 1) {
        total_amount = 0;
        printf("Total sales amount reset to zero.\n");
        printf("Please collect the money from the machine.\n");
    }
}

void replenish_ingredients() 
{
    beans = rand()% 101+150;   // 150-250
    water = rand()% 401+800;             // 800-1200
    milk = rand()% 401+100;          // 800-1200
    chocolatesyrup = rand()%401+100;    // 800-1200

    printf("Ingredients Replenished, Current Ingredient Levels:\n");
    printf("Beans: %d\n", beans);
    printf("Water: %d\n", water);
    printf("Milk: %d\n", milk);
    printf("Chocolate Syrup: %d\n", chocolatesyrup);
}

// function to change coffee price
void change_coffee_price() 
{
    int coffee_choice;
    float new_price;
    printf("Select coffee to change price:\n");
    printf("1. Espresso\n");
    printf("2. Cappucino\n");
    printf("3. Mocha\n");
    scanf("%d", &coffee_choice);

    printf("Enter new price: ");
    scanf("%f", &new_price);

    switch (coffee_choice) 
    {
        case 1:
            espresso_price = new_price;
            printf("Espresso price updated to %.2f AED\n", espresso_price);
            break;
        case 2:
            cappucino_price = new_price;
            printf("Cappucino price updated to %.2f AED\n", cappucino_price);
            break;
        case 3:
            mocha_price = new_price;
            printf("Mocha price updated to %.2f AED\n", mocha_price);
            break;
        default:
            printf("Invalid coffee choice.\n");
            break;
    }
}