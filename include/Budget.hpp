#ifndef BUDGET_HPP
#define BUDGET_HPP

# include "Transaction.hpp"
# include <vector>
# include <iostream>
# include <mutex>
# include <memory>
class Budget {
private:
    double income;
    double expenses;
    double balance;
    std::shared_ptr<Transaction>* transactionList;
    int transactionCount;
    mutable std::mutex mutex;

public:

    Budget(const double& income);
    Budget(const Budget& other);
    Budget(Budget&& other) noexcept;

    double getIncome();
    double getExpenses();
    double getBalance();
    std::shared_ptr<Transaction>* getTransactionList();

    void setIncome(double value);
    void setExpenses(double value);
    void setBalance(double value);

    void calculateExpenses();
    void calculateBalance();
    void addTransaction(const std::shared_ptr<Transaction>& transaction); 
    void printBudgetDetails();

    Budget& operator=(const Budget& other);

    ~Budget();
};

#endif
