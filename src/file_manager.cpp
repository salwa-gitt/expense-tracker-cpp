#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "expense.h"
#include "file_manager.h"



// Save all the expense list to the file 
void FileManager::saveToFile(const std::vector<Expense>& expenses)
{
    // making the file
    std::ofstream file(filepath);

    // ensure file exist if not then show error
    if (!file)
    {
        std::cout << "Error: couldn't open file for writing: " << filepath << std::endl;
        return 1;
    }

    
    // 1. Write your header with fixed spacing
    file << std::left << std::setw(20) << "Expense" << " | "
    << std::right << std::setw(10) << "Amount" << "\n";

    file << std::string(30, '-') << '\n';

    // Ensure numbers look like currency (e.g., 12.50)
    file << std::fixed << std::setprecision(2);

    // 2. Write your data using the exact same spacing
    for (const auto& item : expenses)
    {
        file << std::left << std::setw(20) << item.getCategory() << " | "
            << std::right << std::setw(10) << item.getAmount() << '\n';
    }
}


// Loads all the file data to the program
std::vector<Expense> FileManager::loadFromFile()
{
    std::vector<Expense> expenses;

    // opening file for reading
    std::ifstream file(filepath);

    // making sure it handles error amazingly when file is not there
    if (!file)
}