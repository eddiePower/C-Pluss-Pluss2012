//
//  Potion.cpp
//  DungeonCrawlv1
//
//  Created by Eddie Power on 16/05/12.
//  Copyright (c) 2012 Monash University Student.
//  All rights reserved.
//

#include "Potion.h"

Potion::Potion() : Treasure()
{
    int nPotionType = rand() % 2 + 1;
    
    m_sName = "Potion";
    //if random potion type is 1 then make health potion
    if (nPotionType == 1) 
    {
        m_sType = "health_potion";
        m_nValue = rand() % 10 + -5;
        while (m_nValue == 0) 
        {
           m_nValue = rand() % 10 + -5;
        }
    }
    //else make a skill potion.
    else
    {
        m_sType = "skill_potion";
        m_nValue = rand() % 3 + -1;
        while (m_nValue == 0) 
        {
            m_nValue = rand() % 3 + -1;
        }
    }
}

Potion::~Potion()
{
}

string Potion::display()
{
    stringstream output;
    
    output << "Potion stats:\nName: " << m_sName << "\nValue: " << m_nValue;
    output << "\nType: " << m_sType << "\nLocation: (" << m_nXloc << "," << m_nYloc << ").";
    
    return output.str();
}


