/*******************************************************************************
Program name: Project 2 (Zoo Tycoon)
Author: Jessica Duell
Date: Oct 27, 2019
Description: Tiger class that contains the age, cost, number of babies
    food cost and payoff for tigers in the zoo.
*******************************************************************************/

#include "Tiger.hpp"

/*******************************************************************************
                Tiger::Tiger()
Constructor class that sets each variable to their specific animal level.
*******************************************************************************/
Tiger::Tiger() : Animal(){
    setCost(10000);
    setBabies(1);
    setFoodCost(5);
    payOff = cost * 0.2;
    type = "tiger";
    age = 0;
};

/*******************************************************************************
                Tiger::Tiger(int)
Constructor class that sets each variable to their specific animal level.
Sets the age to the provided int.
*******************************************************************************/
Tiger::Tiger(int a) : Animal(){
    setCost(10000);
    setBabies(1);
    setFoodCost(5);
    payOff = cost * 0.2;
    type = "tiger";
    age = a;
};

