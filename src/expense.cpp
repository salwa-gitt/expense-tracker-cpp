#include <iostream>
#include <string>
#include <iomanip>
#include "expense.h"

// a constructor who assign values to the data memeber if not given it will assign default values
Expense::Expense(const std::string& category, float amount)
{
    setCategory(category);
    setAmount(amount);
}

// function for assigning value to amount data member
void Expense::setAmount(float amount)
{
    this->amount = amount;
}

// function for assgning value to category data member
void Expense::setCategory(const std::string& category)
{
    this->category = category;
}

// function that return amount value
float Expense::getAmount() const
{
    return amount;
}

// function that return category value
std::string Expense::getCategory() const
{
    return category;
}

// function that displays amount and category of an object
void Expense::displayExpense()
{
    std::cout << std::left << std::setw(20) << getCategory() << " | "
          << std::right << std::setw(10) << getAmount() << '\n';
}