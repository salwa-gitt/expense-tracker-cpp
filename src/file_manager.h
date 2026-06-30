#pragma once

#include <string>
#include <vector>
#include "expense.h"

class FileManager
{
    private:
        // making var for the path way so incase of updating i will be updating just in one place
        std::string filepath;

    public:

        // it will auto calls the ensureFileExists fun so if the dir is not found it will make one
        FileManager(const std::string& path = "data/expenses.txt");
        
        // Save the full expense list to file
        void saveToFile(const std::vector<Expense>& expenses);

        // Load all the expenses from the file
        std::vector<Expense> loadFromFile();

        // Trim whitespace from strings
        void trim(std::string& str);

        // Ensure the data file and its directory exist
        void ensureFileExists();
};