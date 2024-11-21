#include "Budget.hpp"

#define arrMAX 20

Budget::Budget(double income) {
    std::cout << "In constructorul clasei Budget." << std::endl;
    this->income = income;
    this->transactionList = new Transaction[arrMAX]; 
    this->expenses = 0;
    this->balance = 0;
    this->transactionCount = 0;
}
Budget::Budget(const Budget& other) {
    std::cout << "In copy constructorul clasei Budget!" << std::endl;

    income = other.income;
    expenses = other.expenses;
    balance = other.balance;

    if (other.transactionList != nullptr && other.transactionCount > 0) {
        transactionList = new Transaction[arrMAX];
        transactionCount = other.transactionCount;
        for (int i = 0; i < transactionCount; ++i) {
            transactionList[i] = other.transactionList[i];
        }
    } else {
        transactionList = nullptr;
        transactionCount = 0;
    }
}


Budget::Budget(Budget&& other) noexcept {
    std::cout << "In move constructorul clasei Budget!" << std::endl;

    income = other.income;
    expenses = other.expenses;
    balance = other.balance;
    transactionList = other.transactionList;
    transactionCount = other.transactionCount;

    other.transactionList = nullptr;
    other.transactionCount = 0;
    other.income = 0.0;
    other.expenses = 0.0;
    other.balance = 0.0;
}



double Budget::getIncome() const { return this->income; }
double Budget::getExpenses() const { return this->expenses; }
double Budget::getBalance() const { return this->balance; }
Transaction* Budget::getTransactionList() { return this->transactionList; }


void Budget::setIncome(double value) { this->income = value; }
void Budget::setExpenses(double value) { this->expenses = value; }
void Budget::setBalance(double value) { this->balance = value; }

void Budget::calculateExpenses() {
    double sum = 0;
    int i = 0;
   for (int i = 0; i < transactionCount; i++) {
        if (transactionList[i].getType() == "Expenses") {
            sum += transactionList[i].getAmount();
        }
    }
    
    this->setExpenses(sum);
}


void Budget::calculateBalance() {
    double balance = this->getIncome() - this->getExpenses();
    this->setBalance(balance);
}

void Budget::addTransaction(const Transaction& transaction) {
    if (transactionCount < arrMAX) {
        transactionList[transactionCount++] = transaction;
    } else {
        std::cout << "Transaction list is full!" << std::endl;
    }
}

Budget& Budget::operator=(const Budget& other) {
    std::cout << "In operator assign!" << std::endl;

    if (this == &other) return *this;

    delete[] transactionList;
    transactionList = nullptr;

    income = other.income;
    expenses = other.expenses;
    balance = other.balance;

    if (other.transactionList != nullptr && other.transactionCount > 0) {
        transactionList = new Transaction[arrMAX];
        transactionCount = other.transactionCount;
        for (int i = 0; i < transactionCount; ++i) {
            transactionList[i] = other.transactionList[i];
        }
    } else {
        transactionList = nullptr;
        transactionCount = 0;
    }

    return *this;
}


void Budget::printBudgetDetails() {
    std::cout << "Budget Details:" << std::endl;
    std::cout << "Income: " << this->income << std::endl;
    std::cout << "Expenses: " << this->expenses << std::endl;
    std::cout << "Balance: " << this->balance << std::endl;
    for(int i = 0; i < transactionCount;i++)
        transactionList[i].printTransactionDetails();
}

Budget::~Budget() {
    std::cout << "In destructorul clasei Budget." << std::endl;
    if (transactionList != nullptr) {
    delete[] transactionList;
    }
    transactionList = nullptr;
    
}
