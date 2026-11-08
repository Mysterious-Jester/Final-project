#pragma once

#include <string>

class Category {
private:
    std::string categoryName;
    double allocatedLimit;
    double currentSpent;

public:
    Category(std::string name, double limit);
    std::string getName() const;
    double getAllocatedLimit() const;
    double getCurrentSpent() const;
    double getRemainingBudget() const;
    void addExpense(double amount);
    void setAllocatedLimit(double limit);
    void displaySummary() const;
};
