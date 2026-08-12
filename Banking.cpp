#include <iostream>
#include <iomanip>

void showbalance(double balance);
double deposit();
double withdraw(double balance);
    

int main() {
    
    double balance =12563.0;
    int choice = 0;
do {   

    std::cout << "***********************************" << std::endl;
    std::cout << "Welcome to the Bank Account Program!" << std::endl;
    std::cout << "***********************************" << std::endl;

    std::cout << "1. Show Balance" << std::endl;
    std::cout << "2. Deposit Money" << std::endl;
    std::cout << "3. Withdraw Money" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cin >> choice;

    if (std::cin.fail())
{
    std::cin.clear();              // Clear the error state
    std::cin.ignore(1000, '\n');   // Remove the bad input
    std::cout << "Invalid input. Please enter a number." << std::endl;
    continue;                      // Start the loop again
} 

    std::cin.clear(); // Clear the input buffer
    fflush(stdin); // Flush the input buffer 
    std::cin.ignore(1000, '\n'); // Ignore the rest of the line

    switch (choice) {
        case 1:
            showbalance(balance);
            break;
        case 2:
            balance += deposit();
            showbalance(balance);

            break;
        case 3:
            balance -= withdraw(balance);
            showbalance(balance);

            break;
        case 4:
            std::cout << "Thank you for using the Bank Account Program!" << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
    }


 } while (choice != 4); 
   

    return 0;
}
void showbalance(double balance){
    std::cout << "Your current balance is: $" << std::setprecision(2) << std::fixed << balance << std::endl; 
}
     
double deposit()
{
    double amount = 0.0;

    std::cout << "Enter the amount to deposit: $";
    std::cin >> amount;

    if (amount > 0) {
        return amount;
    }
    else {
        std::cout << "Invalid deposit amount." << std::endl;
        return 0.0;
    }
}
    
double withdraw(double balance)
{
    double amount = 0.0;
    std::cout << "Enter the amount to withdraw: $";
    std::cin >> amount;
    if (amount > balance) {
        std::cout << "Insufficient funds." << std::endl;
        return 0.0;
    }

    else if (amount < 0) {
        std::cout << "Invalid withdrawal amount." << std::endl;
        return 0.0;
    }
    else {
        return amount;
    }
    
    
}