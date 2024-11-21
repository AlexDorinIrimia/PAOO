#ifndef TRANSACTION_HPP
#define TRANSACTION_HPP

#include <string>
#include <iostream>

class Transaction {
private:
    double amount;
    char* type;
    char* date;
    char* category;

public:
   
    Transaction();
    Transaction(double amount, const char* type, const char* date, const char* category);
    Transaction(const Transaction& other);
    Transaction(Transaction&& other) noexcept;

    
    double getAmount() const;
    const char* getType() const;
    const char* getDate() const;
    const char* getCategory() const;

    Transaction& operator=(const Transaction& other);

    void printTransactionDetails() const;
    ~Transaction();
};

#endif
