#ifndef BANKMANAGEMENT_ACCOUNT_H
#define BANKMANAGEMENT_ACCOUNT_H

class account {
public:
    account();

    void setUsername(std::string);
    void setPassword(std::string);
    void depositMoney(int, std::string);
    void withdrawMoney(int);

    std::string getUsername() const;
    std::string getPassword() const;
    int getChecking() const;
    int getSavings() const;

private:
    std::string username;
    std::string password;
    int checking_account;
    int savings_account;
};


#endif //BANKMANAGEMENT_ACCOUNT_H
