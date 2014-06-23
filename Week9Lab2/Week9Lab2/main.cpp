//
//  main.cpp
//  Week9Lab2
//
//  Created by Eddie Power on 1/05/12.
//  Copyright (c) 2012 Monash University Student. 
//  All rights reserved.
//

#include "Alien.h"

//Normal method to compare one alien's
// attack to the other alien attack value;
bool compare(Alien& a1, Alien& a2)
{
    if(*(a1.m_attack) == *(a2.m_attack))
    {
        return true;
    }
    return false;
}

//operator == over ride 
bool operator==(Alien& a1, Alien& a2)
{
    if(*(a1.m_attack) == *(a2.m_attack))
    {
        return true;
    }
    return false;
}

//operator << over ride used for ostream's
ostream& operator<<(ostream& os, const Alien& a)
{
    os << "Name: " << a.m_name << endl;
    os << "Attack: " << *(a.m_attack);
    
    return os;
}

int main()
{
    srand(unsigned(time(0)));
    Alien* a1 = new Alien("anAlien");
    Alien* a2 = new Alien("anotherAlien");
    
    //cout << a1->getAttack() << endl;
    cout << *(a1->getAttack()) << endl;
    
    //cout << a2->getAttack() << endl;
    cout << *(a2->getAttack()) << endl;
    
    //run operator over ride on == compare the attacks of both aliens
    if(*a1 == *a2) 
    {
        cout << "Aliens have the same attack value\n" << endl;
    }
    else
    {
        cout << "Aliens dont have the same attack value\n" << endl;
    }
    
    //call operator override on <<
    cout << *a1 << endl;
    
    delete a1;
    delete a2;
    
    return 0;
}

