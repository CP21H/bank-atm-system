#include <iostream>
#include <vector>
#include <string>
#include "account.h"
using namespace std;

//=- Function Declarations
void start_menu (vector<account>);
void login (vector<account>);
void create_account (vector<account>& database);
void atm_menu(account, vector<account>);

int main() {
    account adminAcc;
    adminAcc.setUsername("admin");
    adminAcc.setPassword("adminPass");

    vector<account> accountDB;
    accountDB.reserve(50);
    accountDB.push_back(adminAcc);

    start_menu(accountDB);

    return 0;
}

//=- Function Definitions
void start_menu (vector<account> database) {
    char input;

    cout << "----------------------------------" << endl;
    cout << "|            Welcome!            |" << endl;
    cout << "|                                |" << endl;
    cout << "| Press 'L' to Login             |" << endl;
    cout << "|                                |" << endl;
    cout << "| Press 'C' to create new account|" << endl;
    cout << "|                                |" << endl;
    cout << "----------------------------------" << endl;

    cin >> input;

    switch (input) {
        case 'L':
        case 'l':
            login(database);
            break;
        case 'C':
        case 'c':
            create_account(database);
            break;
    }
}

void login(vector<account> database) {
    string username;
    bool user_found = false;
    string password;

    string actual_user;
    string actual_pass;

    int counter = 0;
    int acc_index = -1;

    while (user_found == false) {
        cout << "Enter Username: ";
        cin >> username;
        for (account a : database) {
            if (a.getUsername() == username) {
                actual_user = a.getUsername();
                actual_pass = a.getPassword();
                user_found = true;
                acc_index = counter;
            }
            counter++;
        }
    }

    while (password != actual_pass) {
        cout << "Enter Password: ";
        cin >> password;
    }

    atm_menu(database.at(acc_index), database);
}

void create_account(vector<account>& database) {
    string username;
    string password;
    bool user_taken = true;
    bool pass_req = false;

    account acc;

    while (user_taken) {
        cout << "Create a Username: ";
        cin >> username;
        user_taken = false; // Assume the username is available until proven otherwise
        for (account a : database) {
            if (a.getUsername() == username) {
                cout << "Username is taken." << endl;
                user_taken = true;
                break;
            }
        }
    }

    cout << "Username is available." << endl;
    acc.setUsername(username);

    while (pass_req == false) {
        cout << "Password Requirements:\n- At least 8 characters, \n- must include one special character: !$%^&*()[]" << endl;
        cout << "Create a password: ";
        cin >> password;
        if (password.size() >= 8) {
            if (password.find("!") != string::npos ||
                password.find("$") != string::npos ||
                password.find("%") != string::npos ||
                password.find("^") != string::npos ||
                password.find("&") != string::npos ||
                password.find("*") != string::npos ||
                password.find("(") != string::npos ||
                password.find(")") != string::npos ||
                password.find("[") != string::npos ||
                password.find("]") != string::npos) {
                acc.setPassword(password);
                pass_req = true;
            }
        }
    }

    pass_req = false;
    database.push_back(acc);
    atm_menu(acc, database);
}

void atm_menu(account user_acc, vector<account> database) {
    char user_choice;
    int amount;
    string target_account;

    cout << "----------------------------------" << endl;
    cout << "| Checking Account: " << user_acc.getChecking() << endl;
    cout << "| Savings Account: " << user_acc.getSavings() << endl;
    cout << "| D: Deposit Money" << endl;
    cout << "| W: Withdraw Money" << endl;
    cout << "| Q: Logout" << endl;
    cout << "----------------------------------" << endl;

    cout << "What would you like to do? ";
    cin >> user_choice;

    switch (user_choice) {
        case 'D':
        case 'd':
            cout << "Deposit Amount: ";
            cin >> amount;
            cout << "Target Account [Checking or Savings]: ";
            cin >> target_account;
            user_acc.depositMoney(amount, target_account);
            break;
        case 'W':
        case 'w':
            cout << "Note: You can only withdraw from the 'Checkings' account with this ATM service." << endl;
            cout << "Withdraw Amount: ";
            cin >> amount;
            user_acc.withdrawMoney(amount);
            break;
        case 'Q':
        case 'q':
            start_menu(database);
            return;
    }

    atm_menu(user_acc, database);
}