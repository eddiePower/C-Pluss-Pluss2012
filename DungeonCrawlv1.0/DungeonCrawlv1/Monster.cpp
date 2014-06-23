//
//  Monster.cpp
//  DungeonCrawlv1
//
//  Created by Eddie Power on 15/05/12.
//  Copyright 2012 Monash University Student.
//  All rights reserved.
//

#include <string>
#include "Monster.h"

int Monster::m_nNumMonsters = 0;

Monster::Monster()
{
    m_sName = "NoOne";
    m_sType = "monster";
    m_nHealth = 0;
    m_nSkill = 0;
    m_nScore = 25;
}

Monster::Monster(string name, string type) : Player(name, type)
{
    m_sName = name;
    m_sType = type;
    if (m_nNumMonsters > 24) 
    {
        m_nHealth = rand() % 7 + 5;
        m_nSkill = rand() % 4 + 5;
    }
    else
    {
        m_nHealth = rand() % 5 + 5;
        m_nSkill = rand() % 2 + 5;
    }
    m_nScore = 25;
}

Monster::~Monster()
{
    m_nNumMonsters++;
}

int Monster::getNumMonsters()
{
    return m_nNumMonsters;
}

string Monster::display()
{
    stringstream output;
    
    output << "Monster stats:\nHealth: " << m_nHealth << "\nSkill: " << m_nSkill;
    output << "\nLocation: (" << m_nXloc << "," << m_nYloc << ")\nTreasure value: " << m_nScore;
    
    return output.str();
}

