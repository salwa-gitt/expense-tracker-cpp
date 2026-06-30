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
        
        // Save the full expense list to file
        void saveToFile(const std::vector<Expense>& expenses);

        // Load all the expenses from the file
        std::vector<Expense> loadFromFile();
};