//
//  main.cpp
//  Week9Lab
//
//  Created by Eddie Power on 1/05/12.
//  Copyright (c) 2012 Monash University Student.
//  All rights reserved.
//
#include "alien.h"

int main ()
{
    alien* myAlien = new alien("Eddie");
    alien* myAlien2 = new alien("Bob");
    
    //cout << "Alien health is " << myAlien->getHealth() << endl;
    
    if(ageIsEqual(*myAlien, *myAlien2))
    {
       cout << "Your aliens are the same age." << endl;
    }
    else
    {
        cout << "Your aliens are different ages." << endl;    
    }
    return 0;
}

bool ageIsEqual(alien &a1, alien &a2)
{
    return (a1.getAge() == a2.getAge());
}

