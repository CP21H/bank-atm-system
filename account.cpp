#include <iostream>
#include <string>
#include "account.h"
using namespace std;

//=- Default Constructor
account::account() {
    username = "";
    password = "";
    checking_account = 0;
    savings_account = 0;
}


//=- Member Functions - Setters
void account::setUsername(string name) {
    username = name;
}

void account::setPassword(string pin) {
    password = pin;
}

void account::depositMoney(int amount, string account) {
    if (account == "Checkings" || account == "checkings" || account == "Checking" || account == "checking") {
        checking_account += amount;
    }

    if (account == "Savings" || account == "savings" || account == "Saving" || account == "saving") {
        savings_account += amount;
    }
}

void account::withdrawMoney(int amount) {
    checking_account -= amount;
}


//=- Member Functions - Getters
string account::getUsername() const {
    return username;
}

string account::getPassword() const {
    return password;
}

int account::getChecking() const {
    return checking_account;
}

int account::getSavings() const {
    return savings_account;
}