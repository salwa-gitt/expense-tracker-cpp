#include "expense_manager.h"
#include "expense.h"
// for making sure the input is correct
#include "input_utils.h"
#include "file_manager.h"
#include <iostream>
#include <string>
#include <limits>
#include <algorithm>
#include <iomanip>

// it will load the file data automatically when the program runs
ExpenseManager::ExpenseManager()
{
    expenses = fileManager.loadFromFile();
}

// add new expenses to the database
void ExpenseManager::addExpense(const Expense& e)
{
    expenses.push_back(e);
    fileManager.saveToFile(expenses);
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
            found = true;
        }
    }
    
    if(!found)
    {
        std::cout << "\nExpense Not Found!\n";
    }

}


// it deletes the category given to it
void ExpenseManager::deleteExpense(const std::string& cat)
{
    

    // for storing the indxs of the categories that matches the input
    std::vector<int> matches;

    // checking if the database is empty or not
    if (expenses.empty())
    {
        std::cout << "\nNo expenses available\n" << std::endl;
        return;
    }

    // looping through the database and storing all the categories that matches the input
    for (int i = 0; i < expenses.size(); i++)
    {
        // show all the expenses matches to the input also save it's indx num to the matches vector
        if (expenses[i].getCategory() == cat)
        {
            matches.push_back(i);
            std::cout << matches.size() << ". "
            << expenses[i].getCategory() << "- "
            << expenses[i].getAmount() << "\n";
        }
    }

    if (matches.empty())
    {
        std::cout << "\nNo expenses found\n";
        return;
    }

    // take user choice for which expense to delete
    int expenseChoice = getValidInput<int>("\nEnter Choice: ");

    // make sure they input is correct
    if (expenseChoice < 1 || expenseChoice > matches.size())
    {
        std::cout << "\nInvalid Selection!\n";
        return;
    }

    int index = matches[expenseChoice - 1];

    // it points to the start of vec then add the indx to create the correct iterator
    expenses.erase(expenses.begin() + index); 
    fileManager.saveToFile(expenses);
    std::cout << "\nExpense deleted successfully!\n";
    return;

}

// update the category given to it 
void ExpenseManager::updateExpense(const std::string& cat)
{
    std::vector<int> matches;

    if (expenses.empty())
    {
        std::cout << "\nNo expenses available\n" << std::endl;
        return;
    }


    for (int i = 0; i < expenses.size(); i++)
    {
        // show all the expenses matches to the input also save it's indx num to the matches vector
        if (expenses[i].getCategory() == cat)
        {
            matches.push_back(i);
            std::cout << matches.size() << ". "
            << expenses[i].getCategory() << "- "
            << expenses[i].getAmount() << "\n";
        }
    }

    if (matches.empty())
    {
        std::cout << "\nNo expenses found\n";
        return;
    }

    // take user choice for which expense to update
    int expenseChoice = getValidInput<int>("\nEnter Choice: ");


    // make sure they input is correct
    if (expenseChoice < 1 || expenseChoice > matches.size())
    {
        std::cout << "\nInvalid Selection!\n";
        return;
    }

    int index = matches[expenseChoice - 1];

    std::cout << "1. Update Category\n";
    std::cout << "2. Update Amount\n";
    std::cout << "3. Update Both\n";

    int updateChoice = getValidInput<int>("\nEnter Choice: ");


    switch (updateChoice)
    {
        case 1:
        {
            std::string newCat;

            std::cout << "\nEnter new Category: ";
            std::getline(std::cin, newCat);

            expenses[index].setCategory(newCat);
            break;
        }

        case 2:
        {
            float newAmount = getValidInput<float>("\nEnter new Amount: ");

            expenses[index].setAmount(newAmount);
            break;
        }

        case 3:
        {
            std::string newCat;

            std::cout << "\nEnter new Category: ";
            std::getline(std::cin, newCat);

            float newAmount = getValidInput<float>("\nEnter new Amount: ");

            expenses[index].setCategory(newCat);
            expenses[index].setAmount(newAmount);
            break;
        }

        default:
        {
            std::cout << "\nInvalid Input!\n";
            break;
        }
    }

    fileManager.saveToFile(expenses);
    std::cout << "\nExpense updated successfully!\n";
}

// sorting all expenses
void ExpenseManager::sortExpenses()
{
    if (expenses.empty())
    {
        std::cout << "\nNo Expenses Available!\n";
        return;
    }

    std::cout << "===== Sort Expenses =====\n\n";
    std::cout << "1. Sort by Category\n";
    std::cout << "2. Sort by Amount\n";

    int userChoice = getValidInput<int>("\nEnter Choice: ");
    std::cout << "\n";

    switch (userChoice)
    {
        case 1:
        {
            sortByCategory();
            std::cout << std::string(30, '-') << "\n";
            break;
        }
        
        case 2:
        {
            sortByAmount();
            std::cout << std::string(30, '-') << "\n";
            break;
        }

        default:
        {
            std::cout << "\nInvalid Choice!\n";
            break;
        }
    }
}

void ExpenseManager::sortByCategory()
{
    std::cout << "\n1. Alphabetical Order (A -> Z)\n";
    std::cout << "2. Reverse Alphabetical Order (Z -> A)\n";

    int userChoice = getValidInput<int>("\nEnter Choice: ");
    std::cout << "\n";

    if (userChoice != 1 && userChoice != 2)
    {
        std::cout << "\nInvalid Input!\n";
        return;
    }

    std::vector<Expense> temp = expenses;

    if (userChoice == 1)
    {
        std::cout << "===== Alphabetical Order (A-Z) =====\n\n\n\n";

        std::sort(temp.begin(), temp.end(), [](Expense& a, Expense& b) {
            return a.getCategory() < b.getCategory();
        });
    }
    else
    {
        std::cout << "===== Reverse Alphabetical Order (Z-A) =====\n\n\n\n";

        std::sort(temp.begin(), temp.end(), [](Expense& a, Expense& b) {
            return a.getCategory() > b.getCategory();
        });
    }

    // 4. Print the unified table (no need to duplicate this loop!)
    std::cout << std::left << std::setw(20) << "Category" 
    << std::left << std::setw(10) << "Amount" << "\n";
    std::cout << std::string(30, '-') << "\n";

    for (auto& expense : temp)
    {
        // Added () to the functions and included fixed/setprecision
        std::cout << std::left << std::setw(20) << expense.getCategory() 
        << std::left << std::setw(10) << std::fixed << std::setprecision(2) 
        << expense.getAmount() << "\n";
    }

}

void ExpenseManager::sortByAmount()
{
    std::cout << "\n1. Ascending Order (Low -> High)\n";
    std::cout << "2. Descending Order (High -> Low)\n";

    int userChoice = getValidInput<int>("\nEnter Choice: ");
    std::cout << "\n";

    if (userChoice != 1 && userChoice != 2)
    {
        std::cout << "\nInvalid Input!\n";
        return;
    }

    std::vector<Expense> temp = expenses;

    if (userChoice == 1)
    {
        std::cout << "===== Ascending Order =====\n\n";

        std::sort(temp.begin(), temp.end(), [](Expense& a, Expense& b) {
            return a.getAmount() < b.getAmount();
        });
    }
    else
    {
        std::cout << "===== Descending Order =====\n\n";

        std::sort(temp.begin(), temp.end(), [](Expense& a, Expense& b) {
            return a.getAmount() > b.getAmount();
        });
    }

    // 4. Print the unified table (no need to duplicate this loop!)
    std::cout << std::left << std::setw(20) << "Category" 
    << std::left << std::setw(10) << "Amount" << "\n";
    std::cout << std::string(30, '-') << "\n";

    for (auto& expense : temp)
    {
        // Added () to the functions and included fixed/setprecision
        std::cout << std::left << std::setw(20) << expense.getCategory() 
        << std::left << std::setw(10) << std::fixed << std::setprecision(2) 
        << expense.getAmount() << "\n";
    }

}

// giving the highest expense ever
void ExpenseManager::highestExpense()
{
    if (expenses.empty())
    {
        std::cout << "N/A";
        return;
    }

    float highestAmount = expenses[0].getAmount();

    // finding the highest amount in the database
    for (const auto& expense : expenses)
    {
        if (expense.getAmount() > highestAmount)
        {
            highestAmount = expense.getAmount();
        }
    }

    // 4. Print the winner!
    std::cout << "\n----- Highest Expense -----\n\n";

    std::cout << std::left << std::setw(20) << "Category" 
    << std::left << std::setw(10) << "Amount" << "\n";
    std::cout << std::string(30, '-') << "\n";

    // now looping through database to see which objexts has the highest amount
    for (const auto& expense : expenses)
    {
        if (expense.getAmount() == highestAmount)
        {
            std::cout << std::left << std::setw(20) << expense.getCategory() 
            << std::left << std::setw(10) << std::fixed << std::setprecision(2) 
            << expense.getAmount() << "\n";
        }
    }
    
    std::cout << std::string(30, '-') << "\n";

}

// giving the lowest expense ever
void ExpenseManager::lowestExpense()
{
    if (expenses.empty())
    {
        std::cout << "N/A";
        return;
    }

    float lowestAmount = expenses[0].getAmount();

    // finding the highest amount in the database
    for (const auto& expense : expenses)
    {
        if (expense.getAmount() < lowestAmount)
        {
            lowestAmount = expense.getAmount();
        }
    }

    // 4. Print the winner!
    std::cout << "\n----- Lowest Expense -----\n\n";

    std::cout << std::left << std::setw(20) << "Category" 
    << std::left << std::setw(10) << "Amount" << "\n";
    std::cout << std::string(30, '-') << "\n";

    // now looping through database to see which objexts has the highest amount
    for (const auto& expense : expenses)
    {
        if (expense.getAmount() == lowestAmount)
        {
            std::cout << std::left << std::setw(20) << expense.getCategory() 
            << std::left << std::setw(10) << std::fixed << std::setprecision(2) 
            << expense.getAmount() << "\n";
        }
    }

    std::cout << std::string(30, '-') << "\n";
}


void ExpenseManager::totalSumOfExpenses()
{
    double totalSum = 0;

    for (const auto& expense : expenses)
    {
        totalSum += expense.getAmount();
    }

    std::cout << std::string(30, '=') << "\n";
    std::cout << std::left << std::setw(15) << " Total Sum:" 
    << std::fixed << std::setprecision(2) << totalSum << "\n";
    std::cout << std::string(30, '=') << "\n";
}