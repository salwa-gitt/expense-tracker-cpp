#include <iostream>
#include "expense.h"
#include <iomanip>
#include <string>
// for making sure input is correct and the program won't break if it's incorrect
#include "input_utils.h"
#include "expense_manager.h"

int main(void)
{
    ExpenseManager manager;

    while (true)
    {
        std::cout << "\n===== EXPENSE SYSTEM =====\n" << std::endl;

        std::cout << "1. Add Expense" << std::endl;
        std::cout << "2. Delete Expense" << std::endl;
        std::cout << "3. Search Expense By Category" << std::endl;
        std::cout << "4. Update Expense" << std::endl;
        std::cout << "5. Display All Expenses" << std::endl;
        std::cout << "6. Sort All Expense" << std::endl;
        std::cout << "7. Highest Expense" << std::endl;
        std::cout << "8. Lowest Expense" << std::endl;
        std::cout << "9. Total sum of Expenses" << std::endl;
        std::cout << "0. Exit\n" << std::endl;

        int userChoice = getValidInput<int>("\nEnter Choice: ");

        std::cout << "\n";

        switch (userChoice)
        {
           
            case 1:
            {
                std::string expCat;
                float expAmount;

                std::cout << "Enter Category: ";
                std::getline(std::cin, expCat);
                std::cout << "\n";

                expAmount = getValidInput<float>("Enter Amount: ");
                std::cout << "\n";

                Expense exp(expCat, expAmount);
                manager.addExpense(exp);

                break;
            }

            case 2:
            {
                std::string cat;
                std::cout << "Enter the category: ";
                std::getline(std::cin, cat);
                std::cout << "\n";
                manager.deleteExpense(cat);
                break;
            }

            case 3:
            {
                std::string cat;
                std::cout << "Enter the category: ";
                std::getline(std::cin, cat);
                std::cout << "\n";

                // for making the header
                std::cout << std::left << std::setw(20) << "Expense" << " | "
                << std::right << std::setw(10) << "Amount" << "\n";
                std::cout << std::string(35, '-') << '\n';


                manager.searchCategory(cat);
                std::cout << std::string(35, '-') << '\n';

                break;
            }

            case 4:
            {
                std::string cat;
                std::cout << "Enter the Category: ";
                std::getline(std::cin, cat);
                std::cout << "\n";
                manager.updateExpense(cat);
                break;
            }

            case 5:
            {
                // for making the header
                std::cout << std::left << std::setw(20) << "Expense" << " | "
                << std::right << std::setw(10) << "Amount" << "\n";

                std::cout << std::string(35, '-') << '\n';

                manager.displayAllExpenses();
                std::cout << std::string(35, '-') << '\n';

                break;
            }

            case 6:
            {
                manager.sortExpenses();
                break;
            }

            case 7:
            {
                manager.highestExpense();
                break;
            }

            case 8:
            {
                manager.lowestExpense();
                break;
            }

            case 9:
            {
                manager.totalSumOfExpenses();
                break;
            }

            case 0:
            {
                std::cout << "\nExiting Program...\n" << std::endl;
                return 0;
            }
            
    
            default:
            {
                std::cout << "\nInvalid Input!" << std::endl;
                break;
            }
            
        }
    }
    

    return 0;
}