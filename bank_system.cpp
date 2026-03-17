#include <iostream>
#include "inter_accounts.h"
#include "exc_classes.h"
#include <vector>
#include <memory>
#include <string>

// Creating an advanced banky system

int main(){

    bool end_program = false; // A variable for the main program
    std::string name; // Account name
    std::vector<std::shared_ptr<Account>> database; // A vector that contains all the accounts FUTURE_TODO: substitute it by
    // a real database with memory
    

    while(!end_program){

        std::shared_ptr<Account> account;

        // The user enters their name
        std::cout << "Welcome! enter your name: ";
        std::getline(std::cin, name);

        while(name.empty()){
            std::cout << "The name cannot be empty, try again: ";
            std::getline(std::cin, name);
        }
        account = set(name, database);

        

        // change exceptions by while loop 

        //this is a loop within an account 
        bool end_session = false;
        double amount_to_withdraw;
        

        while(!end_session){
            int selection;

            // asking the user what do they want to do
            std::cout << "Enter an option: \n";
            std::cout << "1. Deposit money (enter 1)\n"; 
            std::cout << "2. Withdraw money (enter 2)\n";
            std::cout << "3. Transfer money (enter 3)\n"; // transfer money between the accounts
            std::cout << "4. See account details (enter 4)\n"; // look the information about their account
            std::cout << "5. Exit (enter 5)\n"; // either go back to the initial menu or go out completely
            // from the application 
            
            std::cin >> selection;

            switch(selection){
                case 2:
                    std::cout << "Enter the amount you want to withdraw: ";
                    std::cin >> amount_to_withdraw;
                    try{
                        account->deposit = account->withdraw_money(amount_to_withdraw);
                    } catch (const Insufficient_funds& e){
                        std::cerr << "You don't have enough money" << std::endl;
                        continue;
                    }
                    break;
                case 3: 

                {
                    std::string where;
                    double a;

                    try{
                        std::cout << "Enter the name of an account to transfer money: ";
                        std::cin.ignore();
                        std::getline(std::cin, where);
                        std::cout << "How much money do you want to send? ";
                        std::cin >> a;

                        transfer(name, where, a, database);
                    } catch(const std::invalid_argument& e){
                        std::cout << e.what() << std::endl;
                        continue;
                    } catch(const std::out_of_range& e){
                        std::cout << e.what() << std::endl;
                    }
                    break;

                }
                    
                case 5:
                {
                    std::string what_to_do;
                    std::cout << "Would you like to close the app or change between accounts? ";
                    std::cin.ignore();
                    std::getline(std::cin, what_to_do);

                    try{

                    if(what_to_do == "close"){
                        end_program = true;
                        end_session = true;
                    } else if (what_to_do == "change") {
                        end_session = true;
                    } else {
                        throw std::invalid_argument("You have to write \"close\" or \"change\", lowercase");// TODO: fix an infinite loop
                    }

                } catch(const std::invalid_argument& e){
                    std::cout << e.what() << std::endl;
                }

                    break;
                
                }

            }


        }
    
}


    return 0;
}