/*******************************************************************************
Program name: Project 2 (Zoo Tycoon)
Author: Jessica Duell
Date: Oct 27, 2019
Description: Program that simulates a zoo tycoon game using
    classes and inheritance.
*******************************************************************************/
#include <iostream>
#include "Zoo.hpp"
using std::cout;
using std::endl;

int main(){
    cout << "Welcome to Zoo Tycoon" << endl;
    Zoo zoo;
    zoo.start();
    cout << "Goodbye" << endl;
    return 0;
}
