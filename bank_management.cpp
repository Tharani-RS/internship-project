#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

class Account
{
private:
    int accountNumber;
    string customerName;
    double balance;

public:
    void createAccount()
    {
        cout << "\nEnter Account Number: ";
        cin >> accountNumber;
        cin.ignore();

        cout << "Enter Customer Name: ";
        getline(cin, customerName);

        cout << "Enter Initial Deposit: ";
        cin >> balance;
    }

    int getAccountNumber() const
    {
        return accountNumber;
    }

    double getBalance() const
    {
        return balance;
    }

    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "\nDeposit Successful!\n";
        }
        else
        {
            cout << "\nInvalid Amount!\n";
        }
    }

    void withdraw(double amount)
    {
        if (amount <= 0)
        {
            cout << "\nInvalid Amount!\n";
        }
        else if (amount > balance)
        {
            cout << "\nInsufficient Balance!\n";
        }
        else
        {
            balance -= amount;
            cout << "\nWithdrawal Successful!\n";
        }
    }

    void display() const
    {
        cout << "\n---------------------------------\n";
        cout << "Account Number : " << accountNumber << endl;
        cout << "Customer Name  : " << customerName << endl;
        cout << "Balance        : Rs. " << balance << endl;
        cout << "---------------------------------\n";
    }

    void saveToFile(ofstream &file)
    {
        file << accountNumber << "|"
             << customerName << "|"
             << balance << endl;
    }

    void loadFromLine(string line)
    {
        size_t pos1 = line.find('|');
        size_t pos2 = line.find('|', pos1 + 1);

        accountNumber = stoi(line.substr(0, pos1));
        customerName = line.substr(pos1 + 1, pos2 - pos1 - 1);
        balance = stod(line.substr(pos2 + 1));
    }
};

vector<Account> accounts;

// Load accounts from file
void loadAccounts()
{
    accounts.clear();

    ifstream file("accounts.txt");
    string line;

    while (getline(file, line))
    {
        Account acc;
        acc.loadFromLine(line);
        accounts.push_back(acc);
    }

    file.close();
}

// Save accounts to file
void saveAccounts()
{
    ofstream file("accounts.txt");

    for (auto &acc : accounts)
    {
        acc.saveToFile(file);
    }

    file.close();
}

// Create Account
void createNewAccount()
{
    Account acc;
    acc.createAccount();

    accounts.push_back(acc);
    saveAccounts();

    cout << "\nAccount Created Successfully!\n";
}

// Find Account
int findAccount(int accNo)
{
    for (int i = 0; i < accounts.size(); i++)
    {
        if (accounts[i].getAccountNumber() == accNo)
            return i;
    }

    return -1;
}

// Deposit
void depositMoney()
{
    int accNo;
    double amount;

    cout << "\nEnter Account Number: ";
    cin >> accNo;

    int index = findAccount(accNo);

    if (index == -1)
    {
        cout << "\nAccount Not Found!\n";
        return;
    }

    cout << "Enter Deposit Amount: ";
    cin >> amount;

    accounts[index].deposit(amount);
    saveAccounts();
}

// Withdraw
void withdrawMoney()
{
    int accNo;
    double amount;

    cout << "\nEnter Account Number: ";
    cin >> accNo;

    int index = findAccount(accNo);

    if (index == -1)
    {
        cout << "\nAccount Not Found!\n";
        return;
    }

    cout << "Enter Withdrawal Amount: ";
    cin >> amount;

    accounts[index].withdraw(amount);
    saveAccounts();
}

// Balance Inquiry
void checkBalance()
{
    int accNo;

    cout << "\nEnter Account Number: ";
    cin >> accNo;

    int index = findAccount(accNo);

    if (index == -1)
    {
        cout << "\nAccount Not Found!\n";
        return;
    }

    cout << "\nCurrent Balance: Rs. "
         << accounts[index].getBalance() << endl;
}

// Display Account Details
void displayAccount()
{
    int accNo;

    cout << "\nEnter Account Number: ";
    cin >> accNo;

    int index = findAccount(accNo);

    if (index == -1)
    {
        cout << "\nAccount Not Found!\n";
        return;
    }

    accounts[index].display();
}

// Main Menu
int main()
{
    loadAccounts();

    int choice;

    do
    {
        cout << "\n========== BANK MANAGEMENT SYSTEM ==========\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Check Balance\n";
        cout << "5. Display Account Details\n";
        cout << "6. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            createNewAccount();
            break;

        case 2:
            depositMoney();
            break;

        case 3:
            withdrawMoney();
            break;

        case 4:
            checkBalance();
            break;

        case 5:
            displayAccount();
            break;

        case 6:
            cout << "\nThank you for using the Bank Management System.\n";
            break;

        default:
            cout << "\nInvalid Choice! Please Try Again.\n";
        }

    } while (choice != 6);

    return 0;
}
