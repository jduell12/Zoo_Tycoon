/*******************************************************************************
Program name: Project 2 (Zoo Tycoon)
Author: Jessica Duell
Date: Oct 27, 2019
Description: Animal class that each animal in the zoo inherits from.
    Includes age, cost, number of babies, base food cost and
    payoff of each animal.
*******************************************************************************/
#include "Animal.hpp"

/*******************************************************************************
                Animal::Animal()
Constructor class that sets each variable to their base level.
*******************************************************************************/
Animal::Animal(){
    age = 0;
    cost = 0;
    numBabies = 1;
    baseFoodCost = 20;
    foodCost = 0;
    payOff = 0;
    type = "Generic Animal";
}

/*******************************************************************************
                void Animal::setAge(int)
Sets the animal's age.
*******************************************************************************/
void Animal::setAge(int A){
    age = A;
}

/*******************************************************************************
                int Animal::getAge()
Gets the animal's age
*******************************************************************************/
int Animal::getAge(){
    return age;
}

/*******************************************************************************
                    void Animal::setCost(int)
Sets the cost of the animal.
*******************************************************************************/
void Animal::setCost(int c){
    cost = c;
}

/*******************************************************************************
                int Animal::getCost()
Returns the animal's cost
*******************************************************************************/
int Animal::getCost(){
    return cost;
}

/*******************************************************************************
                    void Animal::setBabies(int)
Sets the number of babies the animal can have
*******************************************************************************/
void Animal::setBabies(int b){
    numBabies = b;
}

/*******************************************************************************
                int Animal::getBabies()
Returns the number of babies the animal can have
*******************************************************************************/
int Animal::getBabies(){
    return numBabies;
}

/*******************************************************************************
                int Animal::getBaseFoodCost()
Returns the base food cost.
*******************************************************************************/
int Animal::getBaseFoodCost(){
    return baseFoodCost;
}

/*******************************************************************************
                void Animal::setFoodCost(int)
Sets the food bost of the animal
*******************************************************************************/
void Animal::setFoodCost(float p){
    foodCost = 20 * p;
}

/*******************************************************************************
                int Animal::getFoodCost()
Gets the food cost of the animal
*******************************************************************************/
int Animal::getFoodCost(){
    return foodCost;
}

/*******************************************************************************
                int Animal::getPayOff()
Returns the animal's payoff (how much money it makes in a day)
*******************************************************************************/
int Animal::getPayOff(){
    return payOff;
}

/*******************************************************************************
                string Animal::getType()
Returns the animal's type
*******************************************************************************/
string Animal::getType(){
    return type;
}

