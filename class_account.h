// This is the header file for the class Account
#include <string>

class Account { // a class for the account and all the operations we can do within the account
    public:
        std::string name;
        double deposit;

        double deposit_money(double amount);
        double withdraw_money(double amount);
        
};
