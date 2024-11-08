#include "Transaction.hpp"


Transaction::Transaction(double amount, const std::string& type, const std::string& date, const std::string& category)
    : amount(amount), type(type), date(date), category(category) {}


double Transaction::getAmount() const { 
    return amount; 
}


const std::string& Transaction::getType() const { 
    return type; 
}


const std::string& Transaction::getDate() const { 
    return date; 
}


const std::string& Transaction::getCategory() const { 
    return category; 
}

void Transaction::printTransactionDetails() const {
    std::cout << "Amount: " << amount << ", Type: " << type
              << ", Date: " << date << ", Category: " << category << std::endl;
}
