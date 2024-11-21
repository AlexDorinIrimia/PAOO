#ifndef PERSONALBUDGET_HPP
#define PERSONALBUDGET_HPP

# include "PersonalBudget.hpp"
# include "Budget.hpp"

class PersonalBudget : public Budget {
    
    private:
        double goal;

    public:
        PersonalBudget(double income,double goal);
        double getGoal();
        void setGoal(double value);

        bool checkGoal();
        void printPersonalBudgetDetails();
        ~PersonalBudget();
};
#endif