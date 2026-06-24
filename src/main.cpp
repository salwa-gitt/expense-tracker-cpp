#include <iostream>
#include "expense.h"

int main(void)
{
    Expense expense("water", 300);

    expense.displayExpense();

    return 0;
}