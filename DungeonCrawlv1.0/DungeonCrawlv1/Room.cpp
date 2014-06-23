//
//  Room.cpp
//  DungeonCrawlv1
//
//  Created by Eddie Power on 7/05/12.
//  Copyright (c) 2012 Monash University Student.
//  All rights reserved.
//

#include "Room.h"

Room::Room()
{
    vector<vector<string> > vXyVector(10, vector<string>(10));
    
    for (int i = 0; i < 10; i++) 
    {
        for (int j = 0; j < 10; j++) 
        {
            vXyVector[i][j] = "+  ";
        }
    }
    
    m_vXyVector = vXyVector;
}

Room::~Room()
{
}

string Room::printRoom()
{
    stringstream output;
    
    for (int i = 0; i < 10; i++) 
    {
        for (int j = 0; j < 10; j++) 
        {
            output << m_vXyVector[i][j];
        }
        output << endl;
    } 
    return output.str();
}

void Room::setLocation(string cItemType, int x, int y)
{
    m_vXyVector[x][y] = cItemType;    
}

string Room::getItem(int x, int y)
{
    string cItemType;
    
    cItemType = m_vXyVector[x][y];
    
    return cItemType;
}



