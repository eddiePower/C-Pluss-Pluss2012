//
//  boss.h
//  Week8Lab
//
//  Created by Eddie Power on 24/04/12.
//  Copyright (c) 2012 Monash University Student. All rights reserved.
//

#ifndef Week8Lab_boss_h
#define Week8Lab_boss_h

#include "character.h"

class boss : public character
{
private:
    int m_strength;
public:
    boss();
    boss(string name);
    void setCharType(string charType);
    string getCharType();
    int attack();
    string display();
    int getHealth();
};

#endif
