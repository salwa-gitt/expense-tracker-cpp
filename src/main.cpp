#include <iostream>
#include "expense.h"
#include "expense_manager.h"

int main(void)
{
    Expense ex1("water", 300);
    Expense ex2("food", 200);
    Expense ex3("food", 30);
    Expense ex4("French Fries", 150);
    Expense ex5("Banana", 500);


    ExpenseManager manager;

    manager.addExpense(ex1);
    manager.addExpense(ex2);
    manager.addExpense(ex3);
    manager.addExpense(ex4);
    manager.addExpense(ex5);
    
    manager.searchCategory("food");
    return 0;
}