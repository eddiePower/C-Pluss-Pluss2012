//
//  BossMonster.cpp
//  DungeonCrawlv1
//
//  Created by Eddie Power on 15/05/12.
//  Copyright 2012 Monash University Student.
//  All rights reserved.
//

#include <iostream>
#include "BossMonster.h"

int BossMonster::m_nNumBoss = 0;

BossMonster::BossMonster()
{
    m_sName = "NoOne";
    m_sType = "boss_monster";
    m_nHealth = 0;
    m_nSkill = 0;
    m_nScore = 0;
    m_nXloc = 8;
}

BossMonster::BossMonster(string name, string type) : Monster(name, type)
{
    m_sName = name;
    m_sType = type;
    //if num monsters from monster class is above 8 then increase monster stats.
    //this number comes when a monster is deleted from memory or killed
    if (m_nNumMonsters > 8) 
    {
        m_nHealth = rand() % 10 + 10;
        m_nSkill = rand() % 12 + 5;
    }
    else
    {
        m_nHealth = rand() % 10 + 10;
        m_nSkill = rand() % 5 + 5;
    }
    m_nScore = 100;
    m_nXloc = 8;

}

BossMonster::~BossMonster()
{
    m_nNumBoss++;
}

string BossMonster::display()
{
    stringstream output;
    
    output << "Boss Monster's stats:\nHealth: " << m_nHealth << "\nSkill: " << m_nSkill;
    output << "\nLocation: (" << m_nXloc << "," << m_nYloc << ")\nTreasure Value: " << m_nScore;
    
    return output.str();
}
