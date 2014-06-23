//
//  character.cpp
//  Week8Lab
//
//  Created by Eddie Power on 24/04/12.
//  Copyright (c) 2012 Monash University Student. 
//  All rights reserved.
//

#include "character.h"

character::character()
{
    m_name = "NoOne";
    m_baseAttack = 0;
    m_currentHealth = 0;
    m_maxHealth = 0;
    m_charType = "Char";
}

character::character(string name)
{
    m_name = name;
    m_baseAttack = rand() % 10 + 1;
    m_maxHealth = rand() % 10 + 25;
    m_currentHealth = m_maxHealth;
    m_charType = "Character";
}

void character::setCharType(string charType)
{
    m_charType = charType;
}

string character::getCharType()
{
    return m_charType;
}

int character::attack()
{
    return m_baseAttack;
}

void character::beHit(int amount)
{
    m_currentHealth -= amount;
   
    if (m_currentHealth > m_maxHealth) 
    {
        m_currentHealth = m_maxHealth;
    }
    else if(m_currentHealth < 0)
    {
        m_currentHealth = 0;
    }
}

string character::display()
{
    stringstream ss;
    
    ss << "Name: " << m_name 
    << "\nHealth: " << m_currentHealth << "/" << m_maxHealth 
    << "\nBase Attack: " << m_baseAttack << endl;
    
    return ss.str();
}
