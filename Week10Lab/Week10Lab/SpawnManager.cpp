//
//  SpawnManager.cpp
//  Week10Lab
//
//  Created by Eddie Power on 8/05/12.
//  Copyright (c) 2012 Monash University Student.
//  All rights reserved.
//

#include <iostream>
#include "SpawnManager.h"
#include "Invader.h"
#include "Mothership.h"

Enemy* SpawnManager::createEnemy(string name, ENEMYTYPE type)
{
    if(type == INVADER) 
    {
        return new Invader(name);
    }
    else if(type == MOTHERSHIP)
    {
        return new Mothership(name);
    }
    else
    {
        return NULL;
    }
}
