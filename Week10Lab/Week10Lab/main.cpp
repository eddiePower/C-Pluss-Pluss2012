//
//  main.cpp
//  Week10Lab
//
//  Created by Eddie Power on 8/05/12.
//  Copyright (c) 2012 Monash University Student.
//  All rights reserved.
//

#include "Monster.h"
#include "SpawnManager.h"
#include "Enemy.h"
#include "Invader.h"

void printStars(int lower, int upper);
void reverseNumber(int number);
int firstName(string name);
int finalNameNumber(int number);
void wait(int seconds);

int main()
{
    cout << "*** Recursion Print Stars ***" << endl;
    printStars(1, 5);
    cout << "\n*** Recursion Reverse int Number. ***" << endl;
    cout << "The reverse of 12345 is ";
    reverseNumber(12345);
    cout << endl;
    cout << "\n*** Recursion Crude Wait function Running. ***" << endl;
    wait(2);
    cout << "\n*** Recursion My Name Number. ***" << endl;
    cout << finalNameNumber(firstName("eddie")) << endl;
    
    cout << "\n*** Private Class Constructor (Singleton). ***" << endl;
    Monster* m1 = Monster::getInstance();
    
    m1->speak();
    m1->speak();
    
    Enemy* e1 = SpawnManager::createEnemy("Bob", INVADER);
    Enemy* e2 = SpawnManager::createEnemy("Bobs Mum", MOTHERSHIP);
    Enemy* e3 = SpawnManager::createEnemy("Bobs brother", INVADER);

    cout << "\n*** (Factory style) Constructors ***" << endl;
    cout << e1->display() << endl;
    cout << e2->display() << endl;
    cout << e3->display() << endl;

    delete m1;
    m1 = NULL;
    
    delete e1;
    e1 = NULL;
    delete e2;
    e2 = NULL;
    delete e3;
    e3 = NULL;
    
    return 0;
}

void printStars(int lower, int upper)
{
    for (int i = 0; i < lower; i++)
    {
        cout << "*";
    }
    cout << endl;
    
    //Base case for recursion
    if (lower < upper) 
    {
        printStars(lower + 1, upper);
        
        for (int i = 0; i < lower; i++)
        {
            cout << "*";
        }
        cout << endl;
    }
    
}

void reverseNumber(int number)
{
    if (number >= 10) 
    {
        //recursion by using modulous and division.
        //i.e)123 in reverse.
        // 123 % 10 = 3
        // 123 / 10 = 12
        // 12 % 10  = 2
        // 12 / 10 = 1
        // 1 % 10 = 1
        // 1 / 10 = 0.
        cout << number % 10;
        reverseNumber(number / 10);        
    }
    else
    {
        cout << number << endl;
    }
}


int firstName(string name)
{
    int num = 0;
    
    for(int i = 0; i < name.length(); i++)
    {
        num += name[i] - 96;
    }
    return num;
}

int finalNameNumber(int number)
{
    if (number < 10) 
    {
        return number;
    }
    else
    {
       return finalNameNumber(number / 10 + number % 10);
    }
}


//Crude Wait Timer, crude because it uses cpu 
// cycles to count down.
void wait(int seconds)
{
    int currentTime = unsigned(time(0));
    int targetTime = currentTime + seconds;
    
    while (currentTime < targetTime) 
    {
        currentTime = unsigned(time(0));
        //cout << "+ ";
    }
}
