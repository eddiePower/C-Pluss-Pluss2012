//
//  fighter.cpp
//  Week8Lab
//
//  Created by Eddie Power on 24/04/12.
//  Copyright (c) 2012 Monash University Student. All rights reserved.
//

#include <sstream>
#include "fighter.h"

fighter::fighter()
{
    m_strength = 0;
    m_charType = "Fighter";
}

fighter::fighter(string name) : character(name)
{
    m_strength = rand() % 6 + 15;
    m_charType = "Fighter";
}

void fighter::setCharType(string charType)
{
    m_charType = charType;
}

string fighter::getCharType()
{
    return m_charType;
}

int fighter::attack()
{
    return m_baseAttack + (m_strength - rand() % 3 + 1);
}

string fighter::display()
{
    stringstream ss;
    
    ss << "Name: " << m_name << "\nClass: Fighter\nHealth: " << m_currentHealth 
    << "/" << m_maxHealth << "\nBase Attack: " << m_baseAttack 
    << "\nStrength: " << m_strength << endl;
    
    return ss.str();
}