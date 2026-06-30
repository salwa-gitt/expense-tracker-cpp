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

    // making sure if file is not there or it's empty so it return NULL instead of crashing
    if (!file)
    {
        return expenses;
    }

    std::string line;
    
    // read the header and ignores it
    std::getline(file, line);

    // read the dash line after the header and ignores it
    std::getline(file, line);

    while (std::getline(file, line))
    {
        // Skip entirely empty lines
        if (line.empty() || line.find_first_not_of(" \t\n\v\f\r") == std::string::npos)
            continue;
        
        std::stringstream ss(line);

        std::string catStr, amountStr;

        std::getline(ss, catStr, '|');
        std::getline(ss, amountStr, '|');

        trim(catStr);
        trim(amountStr);

        // checking if amount is empty if yes then ignore it
        if (amountStr.empty())
            continue;

        float amount = 0;

        try
        {
            amount = std::stof(amountStr);

        }
        catch(...)
        {
            // if any errors skip it
            continue;
        }

        Expense ex(catStr, amount);
        
        expenses.push_back(ex);
    }
    
    return expenses;
}

// Trim whitespace from strings
void FileManager::trim(std::string& str)
{
    const std::string whitespace = " \t\n\r\f\v";

    const auto start = str.find_first_not_of(whitespace);
    if (start == std::string::npos) {
        str.clear();
        return;
    }

    const auto end = str.find_last_not_of(whitespace);
    str = str.substr(start, end - start + 1);
}


// to make sure file exists if not so it will make the file 
void FileManager::ensureFileExists()
{
    // ensure directory exists
    std::filesystem::path p = std::filesystem::path(filePath).parent_path();
    if (!p.empty())
    {
        std::filesystem::create_directories(p);
    }

    // if file doesn't exist, create and write header
    if (!std::filesystem::exists(filePath))
    {
        std::ofstream createFile(filePath);
        if (createFile)
        {
            createFile << std::left << std::setw(20) << "Expense" << " | "
            << std::right << std::setw(10) << "Amount" << "\n";

            file << std::string(30, '-') << '\n';
        }
    }
}