#include <iostream>
#include <vector>

void displayMenu() {
    std::cout << "\n=== C++ Budgeting App ===\n";
    std::cout << "1. View Balance / Summary\n";
    std::cout << "2. Add Transaction\n";
    std::cout << "3. View Categories\n";
    std::cout << "4. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    int choice = 0;
    do {
        displayMenu();
        std::cin >> choice;
        
        switch (choice) {
            case 1:
                std::cout << "\n[Displaying current budget summary...]\n";
                break;
            case 2:
                std::cout << "\n[Adding a new transaction...]\n";
                break;
            case 3:
                std::cout << "\n[Displaying categories...]\n";
                break;
            case 4:
                std::cout << "\nExiting application. Goodbye!\n";
                break;
            default:
                std::cout << "\nInvalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
