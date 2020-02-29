/*******************************************************************************
Program name: Project 2 (Zoo Tycoon)
Author: Jessica Duell
Date: Oct 27, 2019
Description: Penguin class that contains the age, cost, number of babies
    food cost and payoff for penguins in the zoo.
*******************************************************************************/

#include "Penguin.hpp"

/*******************************************************************************
                Penguin::Penguin()
Constructor class that sets each variable to their specific animal level.
*******************************************************************************/
Penguin::Penguin() : Animal(){
    setCost(1000);
    setBabies(5);
    setFoodCost(1);
    payOff = cost * 0.1;
    type = "penguin";
    age = 0;
}

/*******************************************************************************
                Penguin::Penguin(int)
Constructor class that sets each variable to their specific animal level.
Sets the age to the int provided.
*******************************************************************************/
Penguin::Penguin(int a) : Animal(){
    setCost(1000);
    setBabies(5);
    setFoodCost(1);
    payOff = cost * 0.1;
    type = "penguin";
    age = a;
}

