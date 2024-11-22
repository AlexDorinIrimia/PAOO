# include "Budget.hpp"
# include "PersonalBudget.hpp"

int main() {
   
    std::cout << "Budget1: "<< std::endl;
    Budget budget(1000.0);

    
    Transaction transaction1(100.0, "Expenses", "12.02.2024", "Utilities");
    Transaction transaction2(50.0, "Expenses", "13.02.2024", "Food");
    Transaction transaction3(200.0, "Income", "14.02.2024", "Salary");

    budget.addTransaction(transaction1);
    budget.addTransaction(transaction2);
    budget.addTransaction(transaction3);

    budget.calculateExpenses();
    budget.calculateBalance();

    budget.printBudgetDetails();

    std::cout << "Budget2: "<< std::endl;
    Budget budget2(2000.0);
    budget2 = budget;

    budget2.printBudgetDetails();

    std::cout << "Budget3: "<< std::endl;
    Transaction transaction4(100.0, "Expenses", "12.02.2024", "Utilities");
    Transaction transaction5(500.0, "Expenses", "13.02.2024", "Food");
    Transaction transaction6(2000.0, "Income", "14.02.2024", "Salary");

    PersonalBudget budget3(2000.0,5000.0);
    budget3.addTransaction(transaction4);
    budget3.addTransaction(transaction5);
    budget3.addTransaction(transaction6);

    budget3.calculateExpenses();
    budget3.calculateBalance();

    std::cout << "The goal is reached? " << budget3.checkGoal() << std::endl;
    budget3.printPersonalBudgetDetails(); 

    std::cout << "Budget4: "<< std::endl;
    Budget budget4 = budget2;
    budget4.printBudgetDetails();

    std::cout << "Budget5: "<< std::endl;
    Budget budget5 = std::move(budget);
    budget5.printBudgetDetails();

    return 0;
}
