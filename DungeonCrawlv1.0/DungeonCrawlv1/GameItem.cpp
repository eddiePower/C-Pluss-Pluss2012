//
//  GameItem.cpp
//  DungeonCrawlv1
//
//  Created by Eddie Power on 10/05/12.
//  Copyright (c) 2012 Monash University Student.
//  All rights reserved.
//

#include "GameItem.h"


GameItem::GameItem()
{
    m_sName = "NoOne";
    m_sType = "Nothing";
    m_nXloc = rand() % 9;
    m_nYloc = rand() % 9;
}

GameItem::GameItem(string name, string type)
{
    m_sName = name;
    m_sType = type;
    m_nXloc = rand() % 9;
    m_nYloc = rand() % 9;
}

GameItem::~GameItem()
{
}

string GameItem::getName()
{
    return m_sName;
}

string GameItem::getType()
{
    return m_sType;
}

void GameItem::setName(string name)
{
    m_sName = name;
}

void GameItem::setType(string type)
{
    m_sType = type;
}

int GameItem::getXlocation()
{
    return m_nXloc;
}

int GameItem::getYlocation()
{
    return m_nYloc;
}

void GameItem::setXlocation(int xLoc)
{
    m_nXloc = xLoc;
}

void GameItem::setYlocation(int yLoc)
{
    m_nYloc = yLoc;
}


