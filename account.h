#include <string>
#include <vector>
#include "Transaction.h"

class Account {
private:
    std::string accountName;
    double balance;
    std::vector<Transaction> transactions;

public:
    Account(std::string name, double initialBalance);

    void addTransaction(const Transaction& transaction);
    double getBalance() const;
    std::string getName() const;
    void displayTransactionHistory() const;
};
