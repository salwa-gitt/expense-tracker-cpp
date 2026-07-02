```markdown
# Expense Tracker System

A robust, object-oriented Command Line Interface (CLI) application built in C++ designed to manage daily expenses efficiently. The system persistently stores records in a text file, automatically manages file system configurations, and handles complex operational edge cases like duplicate categories seamlessly.

---

## 🚀 Features

* **Persistent Storage:** Data is saved securely inside a localized text file (`data/expenses.txt`).
* **Self-Repairing Directory:** Automatically creates the required folders and files if they do not exist on launch.
* **Smart Update & Delete:** If multiple expenses share the same category, the system prompts you to choose the exact entry you want to modify or remove.
* **Flexible Sorting:** Sort your entire expense history ascending/descending by amount, or alphabetically (A-Z / Z-A) by category.
* **Financial Analytics:** Instantly view statistics including highest expense, lowest expense, and the total sum of all expenditures.

---

## 📷 Screenshots

### Main Menu & Overview
![Main Menu](pics/main%20menu.png)

### Displaying All Current Expenses
![Display Expenses](pics/displayingExpenses.png)

### Intelligent Expense Updating
*Handles multiple entries under the same category safely:*
![Update Expense](pics/updateExpense.png)

### Highest Expense Filter
![Highest Expense](pics/highestExpense.png)

### Underlying Text Database Storage (`data/expenses.txt`)
![Database File](pics/txtFile.png)

---

## 🛠️ Installation & Setup

### Prerequisites
Make sure you have a C++ compiler installed (like `g++`). 

### Build and Run Instructions
Open your terminal inside the root directory of the project and execute the following commands:

1. **Compile the project modules:**
   ```bash
   g++ src/main.cpp src/expense.cpp src/expense_manager.cpp src/file_manager.cpp -o build/main

```

2. **Run the compiled executable:**
```bash
build/main

```



> 📁 **Note:** You do not need to manually create any storage directories. The system will automatically build the `data/` folder and `expenses.txt` data file upon your very first launch.

---

## 📁 Project Directory Structure

```text
expense_tracker/
├── build/
│   └── main                # Compiled executable
├── data/
│   └── expenses.txt        # Automatically generated flat-file database
├── pics/                   # Application demonstration images
└── src/
    ├── expense_manager.cpp # Core business logic implementation
    ├── expense_manager.h   # Manager class definition
    ├── expense.cpp         # Expense entity implementation
    ├── expense.h           # Expense class definition
    ├── file_manager.cpp    # File I/O operations & directory generation
    ├── file_manager.h      # File manager class definition
    ├── input_utils.h       # Validation utilities for user input
    └── main.cpp            # Application entry point and menu loop

```

```

```