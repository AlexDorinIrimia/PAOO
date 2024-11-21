#ifndef
#define

# include "PersonalBudget.hpp"

class PersonalBudget: public Budget{
    
    private:
        double goal;

    public:
        PersonalBudget(double goal);
        double getGoal();
        void setGoal(double value);

        bool checkGoal();
        void printPersonalBudgetDetails();
        ~PersonalBudget();
}