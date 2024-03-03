#include <stdio.h>
#include <stdbool.h>

// Function prototypes
void mainMenu();
void checkBalance(float balance);
float moneyDeposit(float balance);
float moneyWithdraw(float balance);
void menuExit();
void errorMessage();
bool checkPin();

int main() {
    // Local Declarations
    int option;
    float balance = 15000.00;
    int choose;
    bool again = true;

    while (again) {
        mainMenu();

        printf("--------------------------------------------\n");
        printf("Your Selection:\t");
        scanf("%d", &option);

        switch (option) {
            case 1:
                if (checkPin()) {
                    checkBalance(balance);
                }
                break;
            case 2:
                if (checkPin()) {
                    balance = moneyDeposit(balance);
                }
                break;
            case 3:
                if (checkPin()) {
                    balance = moneyWithdraw(balance);
                }
                break;
            case 4:
                menuExit();
                return 0;
            default:
                errorMessage();
                break;
        }

        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("Would you like to do another transaction:\n");
        printf("1. Yes\n");
        printf("2. No\n");
        scanf("%d", &choose);

        if (choose == 2) {
            again = false;
            menuExit();
        }
    }

    return 0;
}

// Function definitions
void mainMenu() {
    printf("----------> Welcome to ATM Banking <----------\n\n");
    printf("-----> Please choose one of the options below <-----\n\n");
    printf("1. Check Balance\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. Exit\n\n");
}

bool checkPin() {
    int pin;
    printf("Enter Your 4 digit Pin\n");
    scanf("%d", &pin);
    if (pin == 1234) {
        return true;
    }
    printf("Your Pin Is Incorrect!!\n");
    return false;
}

void checkBalance(float balance) {
    printf("\n\nYour Available Balance is: $%.2f\n\n", balance);
}

float moneyDeposit(float balance) {
    float deposit;
    printf("Your Balance is: $%.2f\n\n", balance);
    printf("Enter your amount to Deposit: ");
    scanf("%f", &deposit);
    balance += deposit;
    printf("\nYour New Balance is: $%.2f\n\n", balance);
    return balance;
}

float moneyWithdraw(float balance) {
    float withdraw;
    printf("You choose to Withdraw money\n");
    printf("Your Balance is: $%.2f\n\n", balance);
    printf("Enter your amount to withdraw: ");
    scanf("%f", &withdraw);
    if (withdraw > balance) {
        printf("Insufficient balance\n");
    } else {
        balance -= withdraw;
        printf("\nYour withdrawing money is: $%.2f\n", withdraw);
        printf("Your New Balance is: $%.2f\n\n", balance);
    }
    return balance;
}

void menuExit() {
    printf("--------------Take your receipt!!!------------------\n");
    printf("-----Thank you for using ATM Banking Machine!!!-----\n");
}

void errorMessage() {
    printf("!!!You selected an invalid number!!!\n");
}
