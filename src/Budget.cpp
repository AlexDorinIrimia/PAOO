#include "Budget.hpp"


Budget::Budget(double income) {
    std::cout << "In constructorul clasei Budget." << std::endl;
    this->income = income;
    this->transactionList.reserve(10); 
    this->expenses = 0;
    this->balance = 0;
}


double Budget::getIncome() const { return this->income; }
double Budget::getExpenses() const { return this->expenses; }
double Budget::getBalance() const { return this->balance; }
std::vector<Transaction>& Budget::getTransactionList() { return this->transactionList; }


void Budget::setIncome(double value) { this->income = value; }
void Budget::setExpenses(double value) { this->expenses = value; }
void Budget::setBalance(double value) { this->balance = value; }

void Budget::calculateExpenses() {
    double sum = 0;
    for (auto& i : transactionList) {
        if (i.getType() == "Expenses") {
            sum += i.getAmount();
        }
    }
    this->setExpenses(sum);
    std::cout << "Total Expenses: " << sum << std::endl;
}


void Budget::calculateBalance() {
    double balance = this->getIncome() - this->getExpenses();
    this->setBalance(balance);
}

void Budget::addTransaction(const Transaction& transaction) {
    this->transactionList.push_back(transaction);
}


Budget& Budget::operator=(const Budget& other) {
    if (this == &other) return *this;  

    this->income = other.income;
    this->expenses = other.expenses;
    this->balance = other.balance;
    this->transactionList = other.transactionList;  

    return *this;
}

void Budget::printBudgetDetails() {
    std::cout << "Budget Details:" << std::endl;
    std::cout << "Income: " << this->income << std::endl;
    std::cout << "Expenses: " << this->expenses << std::endl;
    std::cout << "Balance: " << this->balance << std::endl;
    for (const auto& transaction : this->transactionList) {
        transaction.printTransactionDetails();
    }
}

Budget::~Budget() {
    std::cout << "In destructorul clasei Budget." << std::endl;
}
