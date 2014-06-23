//
//  Treasure.cpp
//  DungeonCrawlv1
//
//  Created by Eddie Power on 15/05/12.
//  Copyright 2012 Monash University Student.
//  All rights reserved.
//

#include <iostream>
#include "Treasure.h"

Treasure::Treasure()
{
    m_sName = "Treasures";
    m_sType = "treasure";
    m_nValue = rand() % 10 + 40;
}

Treasure::Treasure(string name, string type) : GameItem(name, type)
{
    m_sName = name;
    m_sType = type;
    m_nValue = rand() % 10 + 40;
}

Treasure::~Treasure()
{
}

int Treasure::getValue()
{
    return m_nValue;
}

string Treasure::display()
{
    stringstream output;
    
    output << "Treasure stats:\nName: " << m_sName << "\nValue: " << m_nValue;
    output << "\nLocation: (" << m_nXloc << "," << m_nYloc << ").";
    
    return output.str();
}
