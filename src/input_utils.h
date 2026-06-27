#pragma once

#include <iostream>
#include <limits>
#include <string>

template <typename T>
T getValidInput(const std::string& prompt)
{
    T value;

    while (true)
    {
        std::cout << prompt;

        if (std::cin >> value)
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }

        std::cout << "Invalid input. Please try again.\n";

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}