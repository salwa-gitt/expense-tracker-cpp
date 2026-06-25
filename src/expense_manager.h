#pragma once
#include "expense.h"
#include <vector>
#include <string>

class ExpenseManager
{
    private:

        // making a database which will store all the expenses
        std::vector<Expense> expenses;

    public:

        // add new expenses to the database
        void addExpense(const Expense& e);

        // display all expenses from the database
        void displayAllExpenses();

        // give expenses of a specific category
        void searchCategory(const std::string& cat);

        // show the total sum of all the expenses
        float totalExpenses();

        // it deletes the category given to it
        void deleteExpense(const std::string& cat);

        // update the category given to it 
        //void updateExpense(const std::string& cat);

};