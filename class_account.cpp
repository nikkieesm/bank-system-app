// Implementation of the methods from class Account
#include "class_account.h"
#include "exc_classes.h"
#include <iostream>
#include <ctime>
#include <random>




double Account::deposit_money(double amount){
    double new_balance = deposit + amount;
    std::cout << "The balance is successfully updated! Your current balance is: " << new_balance << std::endl;
    return new_balance;
};

double Account::withdraw_money(double amount){
    if(deposit<amount){
        throw Insufficient_funds();
    }
    double new_balance = deposit - amount;
    std::cout << "The balance is successfully updated! Your current balance is: " << new_balance << std::endl;

    return new_balance;
}

std::string Account::generate_id(){

    std::string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    std::string id;

    srand(time(0));

    

}