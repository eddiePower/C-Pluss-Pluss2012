//
//  GameItem.h
//  DungeonCrawlv1
//
//  Created by Eddie Power on 10/05/12.
//  Copyright (c) 2012 Monash University Student.
//  All rights reserved.
//

#ifndef DungeonCrawlv1_GameItem_h
#define DungeonCrawlv1_GameItem_h

#include <iostream>
#include <time.h>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

class GameItem
{
   protected:
    string m_sName;
    string m_sType;
    int m_nXloc;
    int m_nYloc;
   public:
    GameItem();
    GameItem(string name, string type);
    ~GameItem();
    string getName();
    string getType();
    void setName(string name);
    void setType(string type);
    int getXlocation();
    int getYlocation();
    void setXlocation(int xLoc);
    void setYlocation(int yLoc);
};

#endif
