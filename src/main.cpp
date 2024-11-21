#include "Budget.hpp"

int main() {
   
    Budget budget(1000.0);

    
    Transaction transaction1(100.0, "Expenses", "12.02.2024", "Utilities");
    Transaction transaction2(50.0, "Expenses", "13.02.2024", "Food");
    Transaction transaction3(200.0, "Income", "14.02.2024", "Salary");

    Budget budget2(2000.0);
    budget2 = budget;

    budget.addTransaction(transaction1);
    budget.addTransaction(transaction2);
    budget.addTransaction(transaction3);  

    
    budget.calculateExpenses();

    
    budget.calculateBalance();
    budget.printBudgetDetails();

    return 0;
}
