#include "Category.h"
#include <iostream>
#include <iomanip>

Category::Category(std::string name, double limit)
    : categoryName(name), allocatedLimit(limit), currentSpent(0.0) {}

std::string Category::getName() const {
    return categoryName;
}

double Category::getAllocatedLimit() const {
    return allocatedLimit;
}

double Category::getCurrentSpent() const {
    return currentSpent;
}

double Category::getRemainingBudget() const {
    return allocatedLimit - currentSpent;
}

void Category::addExpense(double amount) {
    if (amount > 0) {
        currentSpent += amount;
    }
}

void Category::setAllocatedLimit(double limit) {
    allocatedLimit = limit;
}


void Category::displaySummary() const {
    double remaining = getRemainingBudget();
    std::cout << std::left << std::setw(15) << categoryName 
              << " | Limit: $" << std::fixed << std::setprecision(2) << std::setw(8) << allocatedLimit 
              << " | Spent: $" << std::setw(8) << currentSpent 
              << " | Remaining: $" << std::setw(8) << remaining << "\n";
}
