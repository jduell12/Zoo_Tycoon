/*******************************************************************************
Program name: Project 2 (Zoo Tycoon)
Author: Jessica Duell
Date: Oct 27, 2019
Description: InputValid Class with functions used to make sure the
input from the user is valid when asking for information for the game.
*******************************************************************************/
#include <iostream>
#include <sstream>
#include "InputValid.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::stringstream;
using std::string;

/*******************************************************************************
                int InputValid::start(string)
Function that prompts the user until the user enters a 1 or 2. 
*******************************************************************************/
int InputValid::start(string value){
    int number = -1;
    bool flag = true;
    stringstream convert(value);
    convert >> number;
    string choice;

    if (convert.fail()){
        number = -1;
    }

    if (number == 1 || number == 2){
        flag = false;
        return number;
    } else if (cin.fail()){
        while(cin.get() != '\n'){
             cin.ignore();
             cin.clear();
        }
    }

    do {
        cout << "Please enter a 1 or 2." << endl;
        getline(cin, choice);
        stringstream convert(choice);
        convert >> number;
        if (convert.fail()){
            number = -1;
            cin.clear();
        }

        if (number == 1 || number == 2){
            flag = false;
            cin.clear();
        } else if (cin.fail()){
            while (cin.get() != '\n'){
                cin.ignore();
                cin.clear();
            }
        }
        cin.clear();
    } while(flag);

    return number;
}

/*******************************************************************************
               string InputValid::validString(string)
 Function that prompts the user to pick yes or no
*******************************************************************************/
string InputValid::validString(string input){
    string choice = input;
        bool flag = true;

        for (int i = 0; i < choice.length(); i++){
            choice[i] = toupper(choice[i]);
        }

        if (choice == "YES" || choice == "NO"){
            flag = false;
            return choice;
        } else if (cin.fail()){
            while (cin.get() != '\n'){
                cin.ignore();
                cin.clear();
            }
        }

        do {
            cout << "Please enter yes or no." << endl;
            cin >> choice;
            for (int i = 0; i < choice.length(); i++){
                choice[i] = toupper(choice[i]);
            }
            if (choice == "YES" || choice == "NO"){
                flag = false;
                cin.clear();
            } else if (cin.fail()){
                while (cin.get() != '\n'){
                    cin.ignore();
                    cin.clear();
                }
            }
            cin.clear();
        } while(flag);

        return choice;
}

/*******************************************************************************
               string InputValid::validAnimalString(string)
 Function that prompts the user to pick tiger, penguin or turtle.
*******************************************************************************/
string InputValid::validAnimalString(string input){
        string choice = input;
        bool flag = true;

        for (int i = 0; i < choice.length(); i++){
            choice[i] = toupper(choice[i]);
        }

        if (choice == "TIGER" || choice == "PENGUIN" ||
            choice == "TURTLE"){
                flag = false;
                return choice;
        } else if (cin.fail()){
            while (cin.get() != '\n'){
                cin.ignore();
                cin.clear();
            }
        }

        do {
            cout << "Please choose tiger, penguin or turtle." << endl;
            cin >> choice;
            for (int i = 0; i < choice.length(); i++){
                choice[i] = toupper(choice[i]);
            }
            if (choice == "TIGER" || choice == "PENGUIN" ||
                choice == "TURTLE"){
                    flag = false;
                    cin.clear();
            } else if (cin.fail()){
                while (cin.get() != '\n'){
                    cin.ignore();
                    cin.clear();
                }
            }
            cin.clear();
        } while(flag);

        return choice;
}
