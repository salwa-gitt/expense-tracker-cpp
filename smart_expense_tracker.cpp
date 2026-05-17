#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
using namespace std;


/*
This class represents a single expense entry.
It stores:
- amount (money spent)
- category (type of expense like food, travel)
*/
class Expense
{
    private:
        // stores expense amount in rupees
        float amount;
        // category like Food, Travel, Bills
        char* category;
        

    public:
        // default constructor initializes empty expense
        Expense()
        {
            amount = 0;
            category = NULL;
        }


        Expense(float a, const char* c)
        {
            amount = a;
            category = NULL;
            setCategory(c);
        }

        // deep copy constructor to avoid shared memory issues
        Expense(const Expense& obj) : amount(obj.amount)
        {
            if (obj.category)
            {
                category = new char[strlen(obj.category) + 1];
                strcpy(category, obj.category);
            }
            else
            {
                category = NULL;
            }
            
        }

        Expense& operator=(const Expense& obj)
        {
            // 1. Self-assignment check
            if (this == &obj)
            {
                return *this;
            }

            // 2. Delete old memory
            delete[] category;

            // 3. Copy data
            amount = obj.amount;

            if (obj.category)
            {
                category = new char[strlen(obj.category) + 1];
                strcpy(category, obj.category);
            }
            else
            {
                category = NULL;
            }

            // 4. Return current object
            return *this;
        }
        // safely assigns category using dynamic memory
        void setCategory(const char* c)
        {
            if ( category != NULL)
            {
                delete[] category;
            }

            if (c != NULL)
            {
                category = new char[strlen(c) + 1];
                strcpy(category, c);
            }
            else
            {
                category = NULL;
            }  
            
        }

        void setAmount(float a)
        {
            if (a >= 0)
            {
                amount = a;
            }
        }

        float getAmount() const
        {
            return amount;
        }

        const char* getCategory() const
        {
            return category;
        }

        void display()
        {
            cout << "Total amount: " << amount << endl;
            cout << "Category: " << (category ? category : "NULL") << endl;
        }


        // releases dynamically allocated memory
        ~Expense()
        {
            delete[] category;
        }
};

class ExpenseManager {
    private:
        // Create an array of 100 Expense objects
        Expense expenses[100];
        // how many objects are used and how many are left in the expenses array
        int size;

    public:
        ExpenseManager()
        {
            size = 0;
            loadFromFile();
        }

        void addExpense()
        {  
            float amount;
            char category[50];

            cout << "Enter amount: ";
            cin >> amount;
            // ignore up to 1000 characters but if \n apear so stop
            cin.ignore(1000, '\n');

            cout << "Enter category: ";
            cin.getline(category, 50);
            
            if(size < 100)
            {
                expenses[size] = Expense(amount, category);
                size++;
            }
            
            else
            {
                cout << "Expense limit reached..." << endl;
            }

        }

        void display()
        {
            for (int i = 0; i < size; i++)
            {
                expenses[i].display();
                cout << endl;
            }
        }

        void showTotal()
        {
            float totalAmount = 0;
            for(int i= 0; i < size; i++)
            {
                totalAmount += expenses[i].getAmount();
            }

            cout << "Total Expense: " << totalAmount << endl;
        }
        // it will show all the amount of a specific category
        void searchCategory()
        {
            char searchkey[50];
            bool found = false;

            cout << "input the category you want to search: ";
            cin.getline(searchkey, 50);

            for(int i = 0; i < size; i++)
            {
                if (strcmp(searchkey, expenses[i].getCategory()) == 0)
                {
                    expenses[i].display();
                    found = true;
                }
            }

            if (found == false)
            {
                cout << "\nNo matching category found!" << endl;
                return;
            }

        }

        void saveToFile()
        {
            ofstream file("expenses.txt");

            if (!file.is_open())
            {
                cout << "Error: could not open file for writing! " << endl;
                return;
            }

            for(int i=0; i<size; i++)
            {
                const char *cat = expenses[i].getCategory();

                if (cat == NULL)
                {
                    cat = "Unknown";
                }

                file << expenses[i].getAmount() << " " << cat << "\n";
            }

            file.close();
        }

        void loadFromFile()
        {
            ifstream file("expenses.txt");

            if (!file.is_open())
            {
                cout << "Error opening file! " << endl;
                return;
            }

            size = 0;

            float amount;
            char category[50];
            
            while (file >> amount)
            {
                file.ignore();

                file.getline(category, 50);

                expenses[size] = Expense(amount, category);
                size++;
            }

            file.close();

        }
    
        void deleteExpense()
        {
            int indxQuery;

            cout << "Index\tCategory\n" << endl;

            for (int i=0; i<size; i++)
            {
                cout << (i+1) << "\t" << expenses[i].getCategory() << endl;
            }

            cout << "Enter the index you want to delete: ";
            cin >> indxQuery;

            indxQuery--;

            if (indxQuery < 0 || indxQuery >= size)
            {
                cout << "Invalid index! " << endl;
                return;
            }

            // shift left
            for (int i=indxQuery; i<size-1; i++)
            {
                expenses[i] = expenses[i+1];
            }

            size--;

            cout << "Expense deleted successfully!" << endl;
        }

        void updateExpense()
    {
        int index;
        int updateChoice;

        cout << "Index\tCategory\tAmount\n\n";

        for (int i = 0; i < size; i++)
        {
            cout << (i + 1) << "\t"
                 << expenses[i].getCategory() << "\t"
                 << expenses[i].getAmount() << endl;
        }

        cout << "\nEnter the index you want to update: ";
        cin >> index;

        index--; 

        if (index < 0 || index >= size)
        {
            cout << "Invalid index!" << endl;
            return;
        }

        cout << "\nWhat do you want to do?" << endl;
        cout << "1. Update Amount" << endl;
        cout << "2. Update Category" << endl;
        cout << "3. Update Both" << endl;

        cout << "\nUser Choice: ";
        cin >> updateChoice;

        int newAmount;
        char newCategory[50];

        switch (updateChoice)
        {
            case 1:
            {
                
                cout << "\nEnter new amount: ";
                cin >> newAmount;

                if (newAmount >= 0)
                {
                    expenses[index].setAmount(newAmount);
                }
                else
                {
                    cout << "Invalid amount!" << endl;
                }
                break;
            }

            case 2:
            {
                

                cin.ignore(1000, '\n');

                cout << "\nEnter new category: ";
                cin.getline(newCategory, 50);

                expenses[index].setCategory(newCategory);
                break;
            }

            case 3:
            {


                cout << "\nEnter new amount: ";
                cin >> newAmount;

                cin.ignore(1000, '\n');

                cout << "\nEnter new category: ";
                cin.getline(newCategory, 50);

                if (newAmount >= 0)
                {
                    expenses[index].setAmount(newAmount);
                    expenses[index].setCategory(newCategory);
                }
                else
                {
                    cout << "Invalid amount!" << endl;
                }

                break;
            }

            default:
                cout << "Invalid choice!" << endl;
                break;
        }
    }

        void summarizeCategories()
        {
            int uniqueCount = 0;
            char categories[100][50];
            float totals[100];

            for (int i = 0; i < 100; i++)
                totals[i] = 0;

            

            for (int i=0; i<size; i++)
            {
                const char* cat = expenses[i].getCategory();

                if (cat == NULL)
                    continue;

                float amt = expenses[i].getAmount();
                bool found = false;

                for (int j=0; j<uniqueCount; j++)
                {
                    if (strcmp(cat, categories[j]) == 0)
                    {
                        totals[j] += amt;
                        found = true;
                        break;
                    }
                }

                if (found == false)
                {
                    if (uniqueCount >= 100)
                        break;

                    strcpy(categories[uniqueCount] , cat);
                    totals[uniqueCount] = amt;
                    uniqueCount++;
                }

                
            }

            cout << left << setw(15) << "Category"
            << "Total" << endl;
            
            for (int i=0; i<uniqueCount; i++)
            {
                cout << left << setw(15) << categories[i]
                << totals[i] << endl;
            }


        }
    
};

int main()
{
    ExpenseManager manager;

    int input;

    while (true)
    {
        cout << "\n===== MENU =====" << endl;
        cout << "1 -> Add Expense" << endl;
        cout << "2 -> Display All" << endl;
        cout << "3 -> Show Total" << endl;
        cout << "4 -> Search Category" << endl;
        cout << "5 -> Delete expense" << endl;
        cout << "6-> Update expense" << endl;
        cout << "7 -> Summarize Categories" << endl;
        cout << "8 -> Exit\n" << endl;

        cout << "Enter choice: ";
        cin >> input;
        cout << endl;

        switch (input)
        {
            case 1:
                manager.addExpense();
                break;

            case 2:
                manager.display();
                break;

            case 3:
                manager.showTotal();
                break;

            case 4:

                cin.ignore(1000, '\n');
                manager.searchCategory();
                break;
            
            case 5:
                manager.deleteExpense();
                break;
            
            case 6:
                manager.updateExpense();
                break;
            
            case 7:
                manager.summarizeCategories();
                break;
            
            case 8:
                cout << "Exiting program..." << endl;
                manager.saveToFile();
                return 0;

            default:
                cout << "Invalid input!" << endl;
        }
    }

    return 0;
}