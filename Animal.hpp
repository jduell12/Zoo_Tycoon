/*******************************************************************************
Program name: Project 2 (Zoo Tycoon)
Author: Jessica Duell
Date: Oct 27, 2019
Description: File Specification for Animal Class
*******************************************************************************/

#ifndef ANIMAL_HPP_
#define ANIMAL_HPP_

#include <iostream>
using std::string;

class Animal{
protected:
    int age, cost, numBabies, payOff, baseFoodCost, foodCost;
    string type;
public:
    Animal();
    void setAge(int);
    int getAge();
    void setCost(int);
    int getCost();
    void setBabies(int);
    int getBabies();
    int getBaseFoodCost();
    void setFoodCost(float);
    int getFoodCost();
    int getPayOff();
    string getType();
    virtual ~Animal(){};
    
};

#endif /* ANIMAL_HPP_ */
