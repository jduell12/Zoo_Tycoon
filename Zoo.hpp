/*******************************************************************************
Program name: Project 2 (Zoo Tycoon)
Author: Jessica Duell
Date: Oct 27, 2019
Description: File Specification for Zoo Class
*******************************************************************************/
#ifndef ZOO_HPP_
#define ZOO_HPP_

#include <iostream>
#include "Animal.hpp"
#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"

using std::string;

class Zoo{
private:
    Animal **tigers, **penguins, **turtles;
    int bankAccount, profit, tigerArraySize, penguinArraySize,turtleArraySize;
    string choice;
public:
    Zoo();
    ~Zoo(){};
    void ageAnimals();
    void addAnimal(Animal *, int);
    void addPenguin(Animal *);
    void addTiger(Animal *);
    void addTurtle(Animal *);
    void babyBorn();
    void boom();
    void buyAdultAnimal(string);
    void buyAnimal(int);
    bool checkAge(string);
    int calculateProfit();
    void deleteArrays();
    int getBankAccount();
    bool isArrayFull(Animal **, int);
    int payForFood();
    void playGame();
    void penguinDies();
    void printZoo();
    void randomEvent();
    void resizeArray(Animal **&, int&);
    void sickAnimal();
    void start();
    void tigerDies();
    void turtleDies();
};

#endif /* ZOO_HPP_ */
