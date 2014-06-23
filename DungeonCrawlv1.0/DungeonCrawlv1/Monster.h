//
//  Monster.h
//  DungeonCrawlv1
//
//  Created by Eddie Power on 15/05/12.
//  Copyright 2012 Monash University Student.
//  All rights reserved.
//

#ifndef DungeonCrawlv1_Monster_h
#define DungeonCrawlv1_Monster_h

#include "Player.h"

class Monster : public Player
{
    protected:
        static int m_nNumMonsters;
    public:
        Monster();
        Monster(string name, string type); 
        ~Monster();
        int getNumMonsters();
        string display();
};

#endif
