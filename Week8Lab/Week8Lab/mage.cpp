//
//  mage.cpp
//  Week8Lab
//
//  Created by Eddie Power on 24/04/12.
//  Copyright (c) 2012 Monash University Student. All rights reserved.
//

#include "mage.h"

mage::mage()
{
    m_arcanPower = 0;
    m_charType = "Mage";
}

//to avoid the default constructor error we can add this to a class.
mage::mage(string name) : character(name)
{
    m_arcanPower = rand() % 11 + 10;
    m_charType = "Mage";
}

void mage::setCharType(string charType)
{
    m_charType = charType;
}

string mage::getCharType()
{
    return m_charType;
}

int mage::attack()
{
    double modifier = (0.5) * rand() / double(RAND_MAX) + 0.5;
    
    return m_baseAttack + (m_arcanPower * modifier);
}

string mage::display()
{
    stringstream ss;
    
    ss << "Name: " << m_name << "\nClass: Mage\nHealth: " << m_currentHealth 
    << "/" << m_maxHealth << "\nBase Attack: " << m_baseAttack 
    << "\nArchane Power: " << m_arcanPower;
    
    return ss.str();
}