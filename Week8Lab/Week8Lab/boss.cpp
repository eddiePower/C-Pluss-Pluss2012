//
//  boss.cpp
//  Week8Lab
//
//  Created by Eddie Power on 24/04/12.
//  Copyright (c) 2012 Monash University Student. All rights reserved.
//

#include <iostream>
#include "boss.h"

boss::boss()
{
    m_strength = 0;
    m_charType = "Boss";
}

boss::boss(string name) : character(name)
{
    m_maxHealth *= 2;
    m_currentHealth = m_maxHealth;
    m_strength = rand() % 6 + 20;
    m_charType = "Boss";
}

void boss::setCharType(string charType)
{
    m_charType = charType;
}

string boss::getCharType()
{
    return m_charType;
}

int boss::attack()
{
    return m_baseAttack + (m_strength * 1.5);
}

int boss::getHealth()
{
    return m_currentHealth;
}

string boss::display()
{
    stringstream ss;
    
    ss << "Name: " << m_name << "\nClass: Boss\nHealth: " << m_currentHealth 
    << "/" << m_maxHealth << "\nBase Attack: " << m_baseAttack 
    << "\nStrength: " << m_strength << endl;
    
    return ss.str();
}