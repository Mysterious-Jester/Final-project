#pragma once

#include <string>

class Transaction {
private:
    std::string description;
    double amount;
    std::string date;
    std::string category;

public:
    Transaction(std::string desc, double amt, std::string dt, std::string cat);
    std::string getDescription() const;
    double getAmount() const;
    std::string getDate() const;
    std::string getCategory() const;

    void displayDetails() const;
};
