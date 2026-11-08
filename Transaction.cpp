#include "Transaction.h"
#include <iostream>
#include <iomanip>

Transaction::Transaction(std::string desc, double amt, std::string dt, std::string cat)
    : description(desc), amount(amt), date(dt), category(cat) {}

std::string Transaction::getDescription() const {
    return description;
}

double Transaction::getAmount() const {
    return amount;
}

std::string Transaction::getDate() const {
    return date;
}

std::string Transaction::getCategory() const {
    return category;
}

void Transaction::displayDetails() const {
    std::cout << std::left << std::setw(12) << date 
              << std::setw(20) << description 
              << std::setw(15) << category 
              << (amount >= 0 ? "+$" : "-$") 
              << std::right << std::fixed << std::setprecision(2) << std::abs(amount) << "\n";
}
