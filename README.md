# 💰 Expense Tracker System (C++ OOP Project)

A console-based Expense Tracker built using C++ that allows users to manage personal expenses efficiently. It supports full CRUD operations along with file persistence and category-based analytics.

---

## 🚀 Overview

This project simulates a real-world expense management system where users can:
- Add and manage expenses
- Categorize spending
- Track total expenditure
- Persist data using files

It demonstrates strong Object-Oriented Programming principles and low-level memory management in C++.

---

## ✨ Features

- ➕ Add new expenses (amount + category)
- 📋 Display all stored expenses
- 💰 Calculate total spending
- 🔍 Search expenses by category
- ❌ Delete expenses by index
- ✏️ Update expense details
- 📊 Category-wise summary report
- 💾 File-based data storage (`expenses.txt`)
- 🔄 Automatic data loading on startup

---

## 🛠️ Tech Stack

- C++
- Object-Oriented Programming (OOP)
- File Handling (`fstream`)
- Dynamic Memory Allocation
- String Handling (`cstring`)
- Data Formatting (`iomanip`)

---

## 🧠 Core Concepts Used

- Classes & Objects
- Constructors & Destructors
- Deep Copy Constructor
- Operator Overloading (`=`)
- Pointers & Dynamic Memory
- File I/O (read/write)
- Arrays & string manipulation
- Basic data aggregation logic

---

## ⚙️ How It Works

1. Program loads previous data from `expenses.txt`
2. User interacts via menu-driven interface
3. Expenses are stored in memory using an array of objects
4. User can modify or delete entries
5. Data is saved automatically on exit

---

## 📌 Menu Options

```
1 -> Add Expense
2 -> Display All Expenses
3 -> Show Total Expense
4 -> Search by Category
5 -> Delete Expense
6 -> Update Expense
7 -> Summarize Categories
8 -> Exit
```

---

## 💡 Example Usage

```
Enter amount: 500
Enter category: Food

Total Expense: 1500
```

---

## 📂 Data Storage

- File: `expenses.txt`
- Format:
```
amount category
```

Example:
```
250 Food
1200 Travel
500 Bills
```

---

## 🔮 Future Improvements

- Add GUI version (Qt or web dashboard)
- Multi-user login system
- Monthly budget limits & alerts
- Export reports (PDF/Excel)
- Database integration (SQLite/MySQL)
- Charts & analytics dashboard

---

## 🎯 Learning Outcome

This project demonstrates:
- Real-world system design thinking
- Strong OOP architecture in C++
- Memory-safe programming practices
- File persistence handling
- Data aggregation & reporting logic

---

## 👨‍💻 Author

Built by Salwa
