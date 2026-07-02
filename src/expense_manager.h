#pragma once
#include "expense.h"
#include "file_manager.h"
#include <vector>
#include <string>

class ExpenseManager
{
    private:

        FileManager fileManager;
        // making a database which will store all the expenses
        std::vector<Expense> expenses;

    public:

        ExpenseManager();

        // add new expenses to the database
        void addExpense(const Expense& e);

        // display all expenses from the database
        void displayAllExpenses();

        // give expenses of a specific category
        void searchCategory(const std::string& cat);

        // it deletes the category given to it
        void deleteExpense(const std::string& cat);

        // update the category given to it 
        void updateExpense(const std::string& cat);

        // sorting all the Expenses
        void sortExpenses();

        // sorting by category
        void sortByCategory();

        // sorting by Amount
        void sortByAmount();

        // giving the highest Expense ever
        void highestExpense();

        // giving the lowest Expense ever
        void lowestExpense();

        // giving the total amount of the expenses
        void totalSumOfExpenses();
};