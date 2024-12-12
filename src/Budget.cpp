#include "Budget.hpp"
#include <string.h>


#define arrMAX 20

Budget::Budget(const double& income) {
    std::cout << "In constructorul clasei Budget." << std::endl;
    this->income = income;
    this->transactionList = new std::shared_ptr<Transaction>[arrMAX]; 
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
        transactionList = new std::shared_ptr<Transaction>[arrMAX];
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



double Budget::getIncome() { return this->income; }
double Budget::getExpenses() { return this->expenses; }
double Budget::getBalance() { return this->balance; }
std::shared_ptr<Transaction>* Budget::getTransactionList() { return this->transactionList; }


void Budget::setIncome(double value) { this->income = value; }
void Budget::setExpenses(double value) { 
    std::lock_guard<std::mutex> lock(mutex);
    expenses = value; 
    //std::lock_guard<std::mutex> unlock(mutex);
    }
void Budget::setBalance(double value) {
    std::lock_guard<std::mutex> lock(mutex);
    balance = value; 
    //std::lock_guard<std::mutex> unlock(mutex);
    }

void Budget::calculateExpenses() {
    double sum = 0;
    int i = 0;
   for (int i = 0; i < transactionCount; i++) {
        if (strcmp(transactionList[i]->getType(),"Expenses") == 0) {
            sum += transactionList[i]->getAmount();
        }
        else if(strcmp(transactionList[i]->getType(),"Income") == 0){
            double sum = 0;
            sum = getIncome() + transactionList[i]->getAmount();
            setIncome(sum);
        }
    }
    
    setExpenses(sum);
}


void Budget::calculateBalance() {
    double balance = this->getIncome() - this->getExpenses();
    setBalance(balance);
}

void Budget::addTransaction(const std::shared_ptr<Transaction>& transaction) {
    std::lock_guard<std::mutex> lock(mutex);
    if (transactionCount < arrMAX) {
        transactionList[transactionCount] = transaction;
    } else {
        std::cout << "Transaction list is full!" << std::endl;
    }
    this->transactionCount++;
    //std::lock_guard<std::mutex> unlock(mutex);
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
        transactionList = new std::shared_ptr<Transaction>[arrMAX];
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
        transactionList[i]->printTransactionDetails();
}

Budget::~Budget() {
    std::cout << "In destructorul clasei Budget." << std::endl;
    if (transactionList != nullptr) {
    delete[] transactionList;
    }
    transactionList = nullptr;
    
}
