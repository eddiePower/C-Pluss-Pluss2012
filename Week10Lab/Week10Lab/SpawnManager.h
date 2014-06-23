//
//  SpawnManager.h
//  Week10Lab
//
//  Created by Eddie Power on 8/05/12.
//  Copyright (c) 2012 Monash University Student.
//  All rights reserved.
//

#ifndef Week10Lab_SpawnManager_h
#define Week10Lab_SpawnManager_h

#include "Enemy.h"

enum ENEMYTYPE
{
    INVADER,
    MOTHERSHIP
};

class SpawnManager
{
   public:
     static Enemy* createEnemy(string name, ENEMYTYPE type);
};

#endif
