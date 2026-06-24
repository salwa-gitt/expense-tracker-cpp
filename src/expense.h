#pragma once
#include <iostream>
#include <string>


//This file handles collecting an object data of their expenses.

class Expense
{
    private:
        float amount;
        std::string category;

    public:
        // a constructor who assign values to the data memeber if not given it will assign default values
        Expense(const std::string& category = "", float amount = 0);
        
        // function for assigning value to amount data member
        void setAmount(float amount);

        // function for assgning value to category data member
        void setCategory(const std::string& category);

        // function that return amount value
        float getAmount() const;

        // function that return category value
        std::string getCategory() const;

        // function that displays amount and category of an object
        void displayExpense();


};