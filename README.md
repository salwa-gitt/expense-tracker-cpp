# Expense Tracker (C++)

This is a console-based Expense Tracker application built using C++. The program allows users to manage and analyze their daily expenses by storing data in categories and performing basic operations on them.

## Features

* Add new expenses with amount and category
* Display all stored expenses
* Calculate total expenses
* Search expenses by category
* Update existing expenses
* Delete expenses
* Save expenses to a file
* Load expenses from a file automatically
* Summarize expenses by category (grouped totals)

## How it works

The program uses an object-oriented approach with a class to represent each expense. All expenses are stored in an array.

Data is saved in a text file so that it is not lost when the program closes. When the program starts, it reads the file and loads previous data automatically.

The category summary feature groups expenses with the same category and calculates the total amount for each group.

## Concepts used

* Object-Oriented Programming (classes and objects)
* Dynamic memory allocation
* File handling (reading and writing files)
* Arrays and loops
* String handling using character arrays
* Basic data grouping and aggregation logic

## How to run

Compile the program using a C++ compiler:

```bash
g++ main.cpp -o app
```
