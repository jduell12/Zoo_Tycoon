/*******************************************************************************
Program name: Project 2 (Zoo Tycoon)
Author: Jessica Duell
Date: Oct 27, 2019
Description: Turtle class that contains the age, cost, number of babies
    food cost and payoff for turtles in the zoo.
*******************************************************************************/

#include "Turtle.hpp"

/*******************************************************************************
                Turtle:Turtle()
Constructor class that sets each variable to their specific animal level.
*******************************************************************************/
Turtle::Turtle() : Animal(){
    setCost(100);
    setBabies(10);
    setFoodCost(0.5);
    payOff = cost * 0.05;
    type = "turtle";
    age = 0;
}

/*******************************************************************************
                Turtle:Turtle(int)
Constructor class that sets each variable to their specific animal level.
It sets the age to the int provided.
*******************************************************************************/
Turtle::Turtle(int a) : Animal(){
    setCost(100);
    setBabies(10);
    setFoodCost(0.5);
    payOff = cost * 0.05;
    type = "turtle";
    age = a;
}
