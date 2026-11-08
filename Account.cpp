#include "Account.h"
#include <iostream>
#include <iomanip>

Account::Account(std::string name, double initialBalance) 
    : accountName(name), balance(initialBalance) {}


void Account::addTransaction(const Transaction& transaction) {
    transactions.push_back(transaction);
}


double Account::getBalance() const {
    return balance;
}

std::string Account::getName() const {
    return accountName;
}

void Account::displayTransactionHistory() const {
    std::cout << "\n========================================\n";
    std::cout << " Transaction History: " << accountName << "\n";
    std::cout << "========================================\n";
    
    if (transactions.empty()) {
        std::cout << "No transactions recorded yet.\n";
    } else {
        for (size_t i = 0; i < transactions.size(); ++i) {
            std::cout << i + 1 << ". ";
            transactions[i].displayDetails();
        }
    }
    std::cout << "Current Balance: $" << std::fixed << std::setprecision(2) << balance << "\n";
    std::cout << "========================================\n";
}
