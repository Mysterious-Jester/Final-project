#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "Account.h"
#include "Transaction.h"
#include "Category.h"

void displayMenu() {
    std::cout << "\n========================================\n";
    std::cout << "          C++ BUDGETING APP PROTOTYPE            \n";
    std::cout << "========================================\n";
    std::cout << "1. View Account Summary & Transactions\n";
    std::cout << "2. Add Transaction\n";
    std::cout << "3. View Category Budgets\n";
    std::cout << "4. Add New Budget Category\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter your choice (1-5): ";
}

int main() {
    Account myAccount("Primary Checking", 1500.00);
    std::vector<Category> categories;
    categories.emplace_back("Groceries", 400.00);
    categories.emplace_back("Rent", 1200.00);
    categories.emplace_back("Entertainment", 150.00);
    
    int choice = 0;
    do {
        displayMenu();
        if (!(std::cin >> choice)) {
            std::cout << "\nInvalid input. Please enter a valid number.\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }
        std::cin.ignore();

        switch (choice) {
            case 1: {
                myAccount.displayTransactionHistory();
                break;
            }
            //I am so tired, been working on this and looking up c++ commands for this
            case 2: {
                std::string desc, date, catName;
                double amount;

                std::cout << "\nEnter description (e.g., K-Mart): ";
                std::getline(std::cin, desc);
                std::cout << "Enter amount (positive for income, negative for expense): ";
                std::cin >> amount;
                std::cin.ignore();

                std::cout << "Enter date (e.g., 2026-06-08): ";
                std::getline(std::cin, date);

                std::cout << "Enter category name (e.g., Groceries): ";
                std::getline(std::cin, catName);
                Transaction newTx(desc, amount, date, catName);
                myAccount.addTransaction(newTx);

                if (amount < 0) {
                    bool found = false;
                    for (auto & cat : categories) {
                        if (cat.getName() == catName) {
                            cat.addExpense(std::abs(amount));
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        std::cout << "Note: Category '" << catName << "' not found in budget limits. (Expense logged to account balance)\n";
                    }
                }

                std::cout << "\nTransaction successfully recorded!\n";
                break;
            }
            case 3: {
                std::cout << "\n========================================\n";
                std::cout << "           BUDGET CATEGORIES            \n";
                std::cout << "========================================\n";
                if (categories.empty()) {
                    std::cout << "No categories defined yet.\n";
                } else {
                    for (const auto& cat : categories) {
                        cat.displaySummary();
                    }
                }
                std::cout << "========================================\n";
                break;
            }
            case 4: {
                std::string name;
                double limit;
                
                std::cout << "\nEnter new category name: ";
                std::getline(std::cin, name);
                
                std::cout << "Enter monthly spending limit: $";
                std::cin >> limit;
                std::cin.ignore();

                categories.emplace_back(name, limit);
                std::cout << "Category '" << name << "' created with a $" << std::fixed << std::setprecision(2) << limit << " limit!\n";
                break;
            }
            case 5:
                std::cout << "\nExiting application. Thank you for budgeting!\n";
                break;
            default:
                std::cout << "\nInvalid choice. Please select an option between 1 and 5.\n";
        }
    } while (choice != 5);

    return 0;
}
