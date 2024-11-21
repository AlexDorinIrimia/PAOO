#ifndef BUDGET_HPP
#define BUDGET_HPP

#include "Transaction.hpp"
#include <vector>
#include <iostream>

class Budget {
private:
    double income;
    double expenses;
    double balance;
    Transaction* transactionList;
    int transactionCount;

public:

    Budget(double income);
    Budget(const Budget& other);
    Budget(Budget&& other) noexcept;

    double getIncome() const;
    double getExpenses() const;
    double getBalance() const;
    Transaction* getTransactionList();

    void setIncome(double value);
    void setExpenses(double value);
    void setBalance(double value);

    void calculateExpenses();
    void calculateBalance();
    void addTransaction(const Transaction& transaction); 
    void printBudgetDetails();

    Budget& operator=(const Budget& other);

    ~Budget();
};

#endif
