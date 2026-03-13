#include "inter_accounts.h"
#include <iostream>
#include "exc_classes.h"


void transfer(std::string from, std::string to, double quantity, std::vector<std::shared_ptr<Account>>& d){

    std::shared_ptr<Account> from_object = nullptr;
    std::shared_ptr<Account> to_object = nullptr;
    
    for (auto acc : d){
        if(acc->name == from){
            from_object = acc;
        }
        if(acc->name == to){
            to_object = acc;
        }
    }

    if(from == to){
        throw std::invalid_argument("You cannot transfer money to yourself!");
    }
    if(to_object == nullptr){
        throw std::out_of_range("There is no account with this name");
    }

    from_object->deposit -= quantity;
    to_object->deposit += quantity;

    
}

std::shared_ptr<Account> set(std::string name, std::vector<std::shared_ptr<Account>>& d){
    double init_deposit = 0.0;

    for(auto acc : d){
        if(acc->name == name){
            std::cout << "Welcome, " << name << std::endl;
            return acc;
        }
    }

    std::cout << "What is your initial deposit? \n";
    std::cin >> init_deposit;

    if(init_deposit <= 0){
        throw Bad_amount{init_deposit};
        }

    std::shared_ptr<Account> new_account = std::make_shared<Account>();
    new_account->name = name;
    new_account->deposit = init_deposit;
    d.push_back(new_account);
    for (auto v : d ){
        std::cout << v << std::endl;
    }
    std::cout << "Account created!" << std::endl;
    return new_account;
}

