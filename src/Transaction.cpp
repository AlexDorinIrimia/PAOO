#include "Transaction.hpp"
#include <cstring>
#include <iostream>

Transaction::Transaction(){}

Transaction::Transaction(double amount, const char* type, const char* date, const char* category) {
    std::cout << "In constructorul clasei Transaction." << std::endl;
    this->amount = amount;

    this->type = new char[strlen(type) + 1];
    strcpy(this->type, type);

    this->date = new char[strlen(date) + 1];
    strcpy(this->date, date);

    this->category = new char[strlen(category) + 1];
    strcpy(this->category, category);
}


Transaction::Transaction(const Transaction& other) {
    std::cout << "In copy constructorul clasei Transaction." << std::endl;
    this->amount = other.amount;

    this->type = new char[strlen(other.type) + 1];
    strcpy(this->type, other.type);

    this->date = new char[strlen(other.date) + 1];
    strcpy(this->date, other.date);

    this->category = new char[strlen(other.category) + 1];
    strcpy(this->category, other.category);
}

Transaction::Transaction(Transaction&& other) noexcept {
    std::cout << "In move constructorul clasei Transaction!" << std::endl;
    this->amount = other.amount;

    this->type = other.type;
    this->date = other.date;
    this->category = other.category;

    other.type = nullptr;
    other.date = nullptr;
    other.category = nullptr;
}

Transaction& Transaction::operator=(const Transaction& other) {
    if (this == &other) return *this;

    std::cout << "In operator assign!" << std::endl;

    delete[] this->type;
    delete[] this->date;
    delete[] this->category;

    this->amount = other.amount;

    this->type = new char[strlen(other.type) + 1];
    strcpy(this->type, other.type);

    this->date = new char[strlen(other.date) + 1];
    strcpy(this->date, other.date);

    this->category = new char[strlen(other.category) + 1];
    strcpy(this->category, other.category);

    return *this;
}


Transaction::~Transaction() {
    std::cout << "In deconstructorul clasei Transaction" << std::endl;
    delete[] type;
    delete[] date;
    delete[] category;
}

double Transaction::getAmount() const { return amount; }
const char* Transaction::getType() const { return type; }
const char* Transaction::getDate() const { return date; }
const char* Transaction::getCategory() const { return category; }

void Transaction::printTransactionDetails() const {
    std::cout << "Amount: " << amount << ", Type: " << type
              << ", Date: " << date << ", Category: " << category << std::endl;
}
