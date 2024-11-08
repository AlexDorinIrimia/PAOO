#ifndef TRANSACTION_HPP
#define TRANSACTION_HPP

#include <string>
#include <iostream>

class Transaction {
private:
    double amount;
    std::string type;
    std::string date;
    std::string category;

public:
   
    Transaction(double amount, const std::string& type, const std::string& date, const std::string& category);

    
    double getAmount() const;
    const std::string& getType() const;
    const std::string& getDate() const;
    const std::string& getCategory() const;

    void printTransactionDetails() const;
};

#endif
