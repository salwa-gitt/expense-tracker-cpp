#include "expense_manager.h"
#include "expense.h"
#include <iostream>
#include <string>

// add new expenses to the database
void ExpenseManager::addExpense(const Expense& e)
{
    expenses.push_back(e);
    std::cout << "\nExpense added successfully!" << std::endl;
}

// display all expenses from the database
void ExpenseManager::displayAllExpenses()
{
    if (expenses.empty())
    {
        std::cout << "\nNo Expenses availabe!\n";
        return;
    }

    for (auto& expense: expenses)
    {
        std::cout << "\n";
        expense.displayExpense();
        std::cout << "\n-------------------------------------------------------------------------------------------------\n";
        
    }
}

// give expenses of a specific category
void ExpenseManager::searchCategory(const std::string& cat)
{
    bool found = false;

    for (auto& expense : expenses)
    {
        if (expense.getCategory() == cat)
        {
            std::cout << "\n";
            expense.displayExpense();
            std::cout << "\n-------------------------------------------------------------------------------------------------\n";
            found = true;
        }
    }
    
    if(!found)
    {
        std::cout << "\nExpense Not Found!\n";
    }

}

// show the total sum of all the expenses
float ExpenseManager::totalExpenses()
{
    float totalSum = 0;

    for (const auto& expense : expenses)
    {
        totalSum += expense.getAmount();
    }

    return totalSum;
}


// it deletes the category given to it
void ExpenseManager::deleteExpense(const std::string& cat)
{
    bool found = false;

    for (auto ex = expenses.begin(); ex != expenses.end(); ex++)
    {
        if (ex->getCategory == cat)
        {
            expenses.erase(cat);
            std::cout << "\nExpense deleted successfully!\n";
            found = true;
            return;
        }

    }
    if(!found)
    {
        std::cout << "\nExpense not found\n";
    }
    
}


// update the category given to it 
//void ExpenseManager::updateExpense(const std::string& cat);

