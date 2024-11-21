# include "PersonalBudget.hpp"
# include "Budget.hpp"
# include <iostream>

PersonalBudget::PersonalBudget(double income,double goal): Budget(income){
    std::cout << "In constructorul clasei PersonalBudget!" << std::endl;
    this->goal = goal;
}

double PersonalBudget::getGoal(){
    return goal;
}

void PersonalBudget::setGoal(double value){
    goal = value;
}

bool PersonalBudget::checkGoal(){
    return getBalance() == getGoal();
}

void PersonalBudget::printPersonalBudgetDetails(){
    Budget::printBudgetDetails();
    std::cout << "Budget goal: " << goal << std::endl;
}

PersonalBudget::~PersonalBudget(){
    std::cout << "In destructorul clasei PersonalBudget!" << std::endl;
}