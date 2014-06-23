//
//  healer.cpp
//  Week8Lab
//
//  Created by Eddie Power on 24/04/12.
//  Copyright (c) 2012 Monash University Student. All rights reserved.
//

#include "healer.h"

healer::healer()
{
    m_divinePower = 0;
    m_charType = "Healer";
}

healer::healer(string name) : character(name)
{
    m_divinePower = rand() % 11 + 10;
    m_charType = "Healer";
}

void healer::setCharType(string charType)
{
    m_charType = charType;
}

string healer::getCharType()
{
    return m_charType;
}

int healer::attack()
{
    double modifier = 0.5 * (rand() / double(RAND_MAX)) + 0.5;
    return (m_baseAttack + (m_divinePower * modifier)) * -1;
}

string healer::display()
{
    stringstream ss;
    
    ss << "Name: " << m_name << "\nClass: Healer\nHealth: " << m_currentHealth 
    << "/" << m_maxHealth << "\nBase Attack: " << m_baseAttack 
    << "\nDivine Power: " << m_divinePower << endl;
    
    return ss.str();
}