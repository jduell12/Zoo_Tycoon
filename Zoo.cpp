/*******************************************************************************
Program name: Project 2 (Zoo Tycoon)
Author: Jessica Duell
Date: Oct 27, 2019
Description: Zoo class that is used to manage the game during
    each turn. 
*******************************************************************************/
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Zoo.hpp"
#include "InputValid.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::string;
using std::srand;
using std::time;

/*******************************************************************************
                        Zoo::Zoo()
Constructor for the Zoo class that sets dynamic arrays for each
animal to 10 and sets each element to null since there are no animals
in the zoo yet. Gives the player $50,000 to start with.
*******************************************************************************/
Zoo::Zoo(){
    tigers = new Animal *[10];
    penguins = new Animal *[10];
    turtles = new Animal *[10];
    tigerArraySize = 10;
    penguinArraySize = 10;
    turtleArraySize = 10;
    bankAccount = 50000;
    
    for (int i = 0; i < 10; i++){
        tigers[i] = NULL;
        penguins[i] = NULL;
        turtles[i] = NULL;
    }
    

}

/*******************************************************************************
            void Zoo::ageAnimals()
Ages each animal in the zoo by 1 day.
*******************************************************************************/
void Zoo::ageAnimals(){
    int tigerCount = 0, penguinCount = 0, turtleCount = 0;
   
    for (int i = 0; i < tigerArraySize; i++){
        if (tigers[i] != NULL){
           tigerCount++;
        }
    }
    
    for (int i = 0; i < penguinArraySize; i++){
        if (penguins[i] != NULL){
            penguinCount++;
        }
    }
    
    for (int i = 0; i < turtleArraySize; i++){
        if (turtles[i] != NULL){
            turtleCount++;
        }
    }
    
    for (int i = 0; i < tigerCount - 1; i++){
        tigers[i]->setAge(tigers[i]->getAge()+1);
    }
    
    for (int i = 0; i < penguinCount - 1; i++){
        penguins[i]->setAge(penguins[i]->getAge()+1);
    }

    for (int i = 0; i < turtleCount - 1; i++){
        turtles[i]->setAge(turtles[i]->getAge()+1);
    }    
}

/*******************************************************************************
            void Zoo::addAnimal(Animal, int)
Function checks the type of the animal and then adds that type of
animal to the zoo for the specified number given by the int.
*******************************************************************************/
void Zoo::addAnimal(Animal *a, int num){
    for (int i = 0; i < num; i++){
        if(a->getType() == "tiger"){
            addTiger(a);
        } else if (a->getType() == "penguin"){
            addPenguin(a);
        } else if (a->getType() == "turtle"){
            addTurtle(a);
        }
    }
}

/*******************************************************************************
            void Zoo::addPenguin(Animal *)
Function that checks the Penguin array to make sure there is room to
add another one. If the array is full it will resize the array to accommodate
more penguins. If the array is not full then it adds the penguin.
*******************************************************************************/
void Zoo::addPenguin(Animal *p){
    if(isArrayFull(penguins, penguinArraySize)){
        resizeArray(penguins, penguinArraySize);
    }
    
    for (int i = 0; i < penguinArraySize; i++){
        if (penguins[i] == NULL){
            penguins[i] = p;
            break;
        }
    }
}

/*******************************************************************************
            void Zoo::addTiger(Animal *)
Function that checks the Tiger array to make sure there is room to
add another one. If the array is full it will resize the array to accommodate
more tigers. If the array is not full then it adds the tiger.
*******************************************************************************/
void Zoo::addTiger(Animal *t){
    if(isArrayFull(tigers, tigerArraySize)){
        resizeArray(tigers, tigerArraySize);
    }
    
    for (int i = 0; i < tigerArraySize; i++){
        if (tigers[i] == NULL){
            tigers[i] = t;
            break;
        }
    }
}

/*******************************************************************************
            void Zoo::addTurtle(Animal *)
Function that checks the Turtle array to make sure there is room to
add another one. If the array is full it will resize the array to accommodate
more turtles. If the array is not full then it adds the turtle.
*******************************************************************************/
void Zoo::addTurtle(Animal *tur){
    if(isArrayFull(turtles, turtleArraySize)){
        resizeArray(turtles, turtleArraySize);
    }
    
    for (int i = 0; i < turtleArraySize; i++){
        if (turtles[i] == NULL){
            turtles[i] = tur;
            break;
        }
    }

}

/*******************************************************************************
                void Zoo::babyBorn()
Random animal is picked to have a baby. Checks to see if there is
an animal of that type old enough to have a baby. If no animal of that
type is old enough to have a baby it picks another animal. If no animal
is able to give birth it prints a message to the user.
*******************************************************************************/
void Zoo::babyBorn(){
    int randAnimal = rand() % 4;
    bool oldEnough = false;
    int babies = 0, check = 0;

    switch(randAnimal){
SWITCH1:
        case 1:
            oldEnough = checkAge("tigers");
            if (oldEnough){
                babies = tigers[0]->getBabies();
                addAnimal(new Tiger(), babies);
                if (tigers[1] != NULL){
                    cout << "Your tigers had " << babies << " baby." << endl;
                } else {
                    cout << "Your tiger had " << babies << " baby." << endl;
                }
                break;
            }
            cout << "There were no tigers old enough to have babies."
                 << " Picking another animal to breed." << endl;
            check++;
            if (check >= 3){
                break;
            }
            goto SWITCH2;
            break;
SWITCH2:
        case 2:
            oldEnough = checkAge("penguins");
            if (oldEnough){
                babies = penguins[0]->getBabies();
                addAnimal(new Penguin(), babies);
                if (penguins[1] != NULL){
                   cout << "Your penguins had " << babies << " babies." << endl;
                } else {
                   cout << "Your penguin had " << babies << "babies." << endl;
                }
                break;
            }
            cout << "There were no penguins old enough to have babies."
                 << " Picking another animal to breed." << endl;
            check++;
            if (check >= 3){
                break;
            }
            goto SWITCH3;
            break;
SWITCH3:
        case 3:
            oldEnough = checkAge("turtles");
            if (oldEnough){
                babies = turtles[0]->getBabies();
                addAnimal(new Turtle(), babies);
                if (turtles[1] != NULL){
                    cout << "Your turtles had " << babies << " babies." << endl;
                } else {
                    cout << "Your turtle had " << babies << " babies." << endl;
                }
                break;
            }
            cout << "There were no turtles old enough to have babies."
                 << " Picking another animal to breed." << endl;
            check++;
            if (check >= 3){
                break;
            }
            goto SWITCH1;
            break;
    }
}

/*******************************************************************************
                        void Zoo::boom()
Adds a random bonus between $250 and $500 for each tiger in the
zoo for the day to the total profit the zoo made that day.
*******************************************************************************/
void Zoo::boom(){
    int bonus = (rand() % 251 + 250);
    int tigerCount = 0;
    
    for (int i = 0; i < tigerArraySize; i++){
        if (tigers[i] != NULL){
            tigerCount++;
        }
    }
   
    profit = profit + (bonus * tigerCount);

    if (tigerCount >= 2){
        cout << "You get an extra $" << bonus << " per tiger!" << endl;
        cout << "There was a boom in attendance! Your " << tigerCount <<
             " tigers made you an extra $" << (bonus * tigerCount) << "!" 
             << endl;
    } else if (tigerCount == 1){
        cout << "There was a boom in attendance! Your tiger made you an"
             <<  " extra $" << (bonus * tigerCount) << "!" << endl;
    } else {
        cout << "Unfortunately you have no tigers."
        << "You did not receive a bonus for attendance." << endl;
    }
    
}

/*******************************************************************************
                void Zoo::buyAdultAnimal(string)
Adds an animal of the type provided in the string that is 3 days old.
Subtracts the cost of the animal from the bank account.
*******************************************************************************/
void Zoo::buyAdultAnimal(string a){
    if (a == "TIGER"){
        bankAccount = bankAccount - 10000;
        addAnimal(new Tiger(3), 1);
    } else if (a == "PENGUIN"){
        bankAccount = bankAccount - 1000;
        addAnimal(new Penguin(3), 1);
    } else if (a == "TURTLE"){
        bankAccount = bankAccount - 100;
        addAnimal(new Turtle(3), 1);
    }
}

/*******************************************************************************
                void Zoo::buyAnimal(int)
Subtracts the price of the animal from the back account.
*******************************************************************************/
void Zoo::buyAnimal(int price){
    bankAccount = bankAccount - price;
}

/*******************************************************************************
                int Zoo::calculateProfit()
Calculates the profit the zoo made based on the number of animals
in the zoo and their payoff.
*******************************************************************************/
int Zoo::calculateProfit(){
    int cost, payOff;
    int tigerCount = 0, penguinCount = 0, turtleCount = 0;
    
    for (int i = 0; i < tigerArraySize; i++){
        if(tigers[i] != NULL){
            tigerCount++;
        }
    }
    
    for (int i = 0; i < penguinArraySize; i++){
        if (penguins[i] != NULL){
            penguinCount++;
        }
    }
    
    for (int i = 0; i < turtleArraySize; i++){
        if (turtles[i] != NULL){
            turtleCount++;
        }
    }
    
    if (tigerCount > 0){
        cost = tigers[0]->getCost();
        payOff = cost * 0.2;
        profit = profit + (payOff * tigerCount);
    }
    
    if (penguinCount > 0){
        cost = penguins[0]->getCost();
        payOff = cost * 0.1;
        profit = profit + (payOff * penguinCount);
    }
    
    if (turtleCount > 0){
        cost = turtles[0]->getCost();
        payOff = cost * 0.05;
        profit = profit + (payOff * turtleCount);
    }
    
    return profit;
}

/*******************************************************************************
                bool Zoo::checkAge(Animal **a)
Checks the age of the animals in the zoo passed as the parameter.
If no animal is greater or equal to 3 days old returns false otherwise
returns true.
*******************************************************************************/
bool Zoo::checkAge(string a){
    int age = 0;
    
    if (a == "tigers"){
        for (int i = 0; i < tigerArraySize; i++){
            if (tigers[i] != NULL){
                age = tigers[i]->getAge();
                if (age >= 3){
                    return true;
                    break;
                }
            }
        }
    } else if (a == "penguins"){
        for (int i = 0; i < penguinArraySize; i++){
            if (penguins[i] != NULL){
                age = penguins[i]->getAge();
                if (age >= 3){
                    return true;
                    break;
                }
            }
        }
    } else if (a == "turtles"){
        for (int i = 0; i < turtleArraySize; i++){
            if (turtles[i] != NULL){
                age = turtles[i]->getAge();
                if (age >= 3){
                    return true;
                    break;
                }
            }
        }
    }
    
    return false;
}

/*******************************************************************************
                void Zoo::deleteArrays()
Deletes all the arrays created during the game.
*******************************************************************************/
void Zoo::deleteArrays(){
    
    delete [] tigers;
    delete [] penguins;
    delete [] turtles;
}

/*******************************************************************************
                void Zoo::getBankAccountt()
Returns the amount in the bank for the zoo.
*******************************************************************************/
int Zoo::getBankAccount(){
    return bankAccount;
}

/*******************************************************************************
            bool Zoo::isArrayFull(Animal **, int)
Returns true if the array is full otherwise it returns false.
*******************************************************************************/
bool Zoo::isArrayFull(Animal **a,  int size){
    for(int i = 0; i < size; i++){
        if(!a[i]){
            return false;
        }
    }
    return true;
}

/*******************************************************************************
            void Zoo::payForFood()
Calulcates the cost to feed the animals in the zoo and deducts the
amount from the zoo's bank account.
*******************************************************************************/
int Zoo::payForFood(){
    int t = 0, p = 0, tur = 0,tigerCount = 0, penguinCount = 0,
        turtleCount = 0, totalCost = 0;
    
    while(tigers[t] != NULL){
        tigerCount++;
        t++;
    }
    
    while(penguins[p] != NULL){
        penguinCount++;
        p++;
    }
    
    while(turtles[tur] != NULL){
        turtleCount++;
        tur++;
    }
    
    if (tigerCount > 0){
        totalCost = tigers[0]->getFoodCost() * tigerCount;
    }

    if (penguinCount > 0){
        totalCost = totalCost + penguins[0]->getFoodCost() * penguinCount;
    }

    if (turtleCount > 0){
        totalCost = totalCost + turtles[0]->getFoodCost() * turtleCount;
    }
    
    cout << "You paid $" << totalCost << " for food." << endl;
    bankAccount = bankAccount - totalCost;
    
    return totalCost;
}

/*******************************************************************************
            void Zoo::penguinDies()
Removes the last penguin from the penguin array
*******************************************************************************/
void Zoo::penguinDies(){
    int lastPenguin = 0, i = 0;
    
    while(penguins[i] != NULL){
        lastPenguin = i;
        i++;
    }
    
    cout << "A penguin has fallen ill with an incurable diesase and has died." 
         << endl;
    delete penguins[lastPenguin];
    penguins[lastPenguin] = NULL;
}

/*******************************************************************************
            void Zoo::playGame()
For each day (aka turn) all animals' age is increased by 1 day. User
is required to pay the feeding cost for each animal so they don't die.
Once the feeding cost is paid 1 random event takes place from the
following 4 options:
    1. A sickness occurs to an animal
    2. A boom in zoo attendance occurs
    3. A baby animal is born
    4. Nothing happens
After the random event it  gets the profit for the day. Before the day ends
function asks the user if they would like to buy an adult animal. At the
end of each day it prompts the player if they wish to keep playing. If
the player runs out of money the game is over.
*******************************************************************************/
void Zoo::playGame(){
    InputValid valid;
    string choice = "YES";
    int day = 1;
    
    do{
    //resets the profit for each day
    profit = 0;
    
    cout << "Day: " << day << endl;
    cout << endl;
    
    //ages animals by 1 day
    ageAnimals();
    
    /*Calculates feeding costs and deducts the cost from the zoo bank account*/
    payForFood();
    cout << "Your current bank account is $" << getBankAccount() << "."
        << endl;
    cout << endl;
    

    //picks a random event
    randomEvent();
    
    //prints out the current zoo population
    printZoo();

    //calculates profit for the day
    profit = calculateProfit();
    bankAccount = bankAccount + profit;
    
    cout << "Your zoo made $" << profit << " today." << endl;
    cout << "Your bank account currently has $" << bankAccount << endl;
    cout << endl;
 
    cout << "Would you like to buy an adult animal?" << endl;
    cout << "Enter yes or no." << endl;
    getline(cin, choice);
    cout << endl;
    choice = valid.validString(choice);
    if (choice == "YES"){
        cout << "What kind of animal would you like to buy?" << endl;
        cout << "Tigers cost $10,000, penguins cost $1,000 and turtles " <<
            "cost $100. " << endl;
        cout << "Please enter tiger, penguin or turtle." << endl;
        getline(cin, choice);
        cout << endl;
        string type = valid.validAnimalString(choice);
        buyAdultAnimal(type);
        cout << "Your bank account currently has $" << bankAccount << endl;
        cout << endl;
        //prints out the current zoo population
        printZoo();
    }
    
    cout << "**************End of Day " << day << "*******************" << endl;
    cout << endl;
    
    if (bankAccount <= 0){
        cout << "Your zoo went bankrupt." << endl;
        choice = "NO";
    } else {
        cout << "Would you like to keep playing?" << endl;
        cout << "Enter yes or no." << endl;
        getline(cin, choice);
        cout << endl;
        choice = valid.validString(choice);
    }

    day++;
    
    
    } while (choice != "NO");

    //deletes all the arrays created during the game
    deleteArrays();
}

/*******************************************************************************
            void Zoo::printZoo()
Prints out how many animals are currently in the zoo
*******************************************************************************/
void Zoo::printZoo(){
    cout << "The animals currently in the zoo:" << endl;
    int numTigers = 0, numPenguins = 0, numTurles = 0;
    int t = 0, p = 0, tu = 0;
    
    while (tigers[t] != NULL){
        numTigers = numTigers + 1;
        t++;
    }
    
    while(penguins[p] != NULL){
        numPenguins = numPenguins + 1;
        p++;
    }
    
    while(turtles[tu] != NULL){
        numTurles = numTurles + 1;
        tu++;
    }
    
    cout << "Number of Tigers: " << numTigers << endl;
    cout << "Number of Penguins: " << numPenguins << endl;
    cout << "Number of Turtles: " << numTurles << endl;
    cout << endl;
}

/*******************************************************************************
                    void Zoo::randomEvent()
Picks a random number between 1 and 4 and then creates the event
for the zoo for that day. The random events are:
    1. A sickness occurs to an animal in the zoo
    2. A boom in zoo attendance occurs
    3. A baby animal is born
    4. Nothing happens
*******************************************************************************/
void Zoo::randomEvent(){
    int randNum = ((rand() % 4) + 1);
    switch(randNum){
        case 1:
            sickAnimal();
            break;
        case 2:
            boom();
            break;
        case 3:
            babyBorn();
            break;
        case 4:
            cout << "No event took place today." << endl;
            break;
    }
}

/*******************************************************************************
            void Zoo::resizeArray(Animal **&, int&)
Creates a new array twice the size of the previous array. Copies the old
array into the new array and deletes the old array.
*******************************************************************************/
void Zoo::resizeArray(Animal **&a, int &size){
    int newSize = size*2;
    Animal **newArray = new Animal *[newSize];
    
    //sets new array elements to null
    for (int i = 0; i < newSize; i++){
        newArray[i] = NULL;
    }
    
    //copies the old array into the new one
    for (int i = 0; i < size; i++){
        newArray[i] = a[i];
    }
    
    //deletes old array
    delete []a;
    
    /*changes the new array's name so it is the same as the old name and 
     * updates value of the size of the array  */
    a = newArray;
    size = newSize;
}

/*******************************************************************************
            void Zoo::sickAnimal()
Picks an animal at random that will die. Removes the animal from the
zoo.
*******************************************************************************/
void Zoo::sickAnimal(){
    int randNum = (rand() % 3) + 1;
    
    if (randNum == 1){
        if(tigers[0] == NULL){
            cout << "There are no tigers left in the zoo." << endl;
        } else {
            tigerDies();
        }
    } else if (randNum == 2){
        if (penguins[0] == NULL){
            cout << "There are no penguins left in the zoo." << endl;
        } else {
            penguinDies();
        }
    } else if (randNum == 3){
        if (turtles[0] == NULL){
            cout << "There are no turtles left in the zoo." << endl;
        } else {
            turtleDies();
        }
    }
}

/*******************************************************************************
                void Zoo::start()
At the beginning of the game function gives the user the option to buy 1 or 2
of each animal type to get the zoo started.
*******************************************************************************/
void Zoo::start(){
    InputValid valid;
    //seed for to pick a random number throughout the game
    srand((unsigned int)time(0));
    
    //User purchases 1 or 2 tigers for zoo
    cout << "Would you like 1 or 2 tigers for your zoo?" << endl;
    cout << "Each tiger costs $10,000. You currently  have $" 
         << bankAccount << endl;
    getline(cin, choice);
    cout << endl;
    int numTigers = valid.start(choice);
    if (numTigers == 1){
        buyAnimal(10000);
        cout << "You bought 1 tiger for $10,000. You have $"
            << getBankAccount() << " left in your bank account." << endl;
    } else{
        buyAnimal(10000*2);
        cout << "You bought 2 tigers for $20,000. YOu have $" <<
            getBankAccount() << " left in your bank account." << endl;
    }
    cout << endl;
    addAnimal(new Tiger(1), numTigers);
    
    //User purchases 1 or 2 penguins for the zoo
    cout << "Would you like 1 or 2 penguins for your zoo?" << endl;
    cout << "Each penguin costs $1,000. You have $" <<
        getBankAccount() << " left in your bank account." << endl;
    getline(cin, choice);
    cout << endl;
    int numPenguins = valid.start(choice);
    if (numPenguins == 1){
        buyAnimal(1000);
        cout << "You bought 1 penguin for $1,000. You have $" <<
            getBankAccount() << " left in your bank account." << endl;
    } else {
        buyAnimal(1000*2);
        cout << "You bought 2 penguins for $2,000. You have $" <<
            getBankAccount() << " left in your bank account." << endl;
    }
    cout << endl;
    addAnimal(new Penguin(1), numPenguins);
    
    //User purchases 1 or 2 turtles for the zoo
    cout << "Would you like 1 or 2 turtles for your zoo?" << endl;
    cout << "Each turtle costs $100. You have $" <<
        getBankAccount() << " left in your bank account." << endl;
    getline(cin, choice);
    cout << endl;
    int numTurtles = valid.start(choice);
    if (numTurtles == 1){
        buyAnimal(100);
        cout << "You bought 1 turtle for $100. You have $" <<
        getBankAccount() << " left in your bank account." << endl;
    } else {
        buyAnimal(100*2);
        cout << "You bought 2 turtles for $200. You have $" <<
        getBankAccount() << " left in your bank account." << endl;
    }
    cout << endl;
    addAnimal(new Turtle(1), numTurtles);
    
    //outputs the number of animals in the zoo for the user
    printZoo();
    
    //function continue to play the game
    playGame();
}

/*******************************************************************************
            void Zoo::tigerDies()
Removes the last tiger in the tiger array
*******************************************************************************/
void Zoo::tigerDies(){
    int lastTiger = 0, i = 0;
    
    while(tigers[i] != NULL){
        lastTiger = i;
        i++;
    }
    
    cout << "A tiger has fallen ill with an incurable disease and has died." 
         << endl;
    delete tigers[lastTiger];
    tigers[lastTiger] = NULL;
}

/*******************************************************************************
            void Zoo::turtleDies()
Removes the last turtle from the array
*******************************************************************************/
void Zoo::turtleDies(){
    int lastTurtle = 0, i = 0;
    
    while(turtles[i] != NULL){
        lastTurtle = i;
        i++;
    }
    
    cout << "A turtle has fallen ill with an incurable diesease and has died." 
         << endl;
            
    delete turtles[lastTurtle];
    turtles[lastTurtle] = NULL;
}
