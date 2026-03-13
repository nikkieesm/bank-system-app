// Header file for managing operations between the accounts
#include "class_account.h"
#include <vector>
#include <memory>

/// @brief A function to transfer money from one account to another
/// @param from The name of an account to transfer the money from
/// @param to The name of an account to transfer the money to
/// @param quantity Desirable quantity
/// @param d The database of all the accounts
void transfer(std::string from, std::string to, double quantity, std::vector<std::shared_ptr<Account>>& d);

/// @brief A function that creates new account or checks the existence of an account 
/// @param name Name of the account to send the money to
/// @param d The database of all the accounts 
/// @return New/existing account
std::shared_ptr<Account> set(std::string name, std::vector<std::shared_ptr<Account>>& d);