//
//  Monster.cpp
//  Week10Lab
//
//  Created by Eddie Power on 8/05/12.
//  Copyright (c) 2012 Monash University Student.
//  All rights reserved.
//

#include "Monster.h"

Monster* Monster::instance = NULL;

Monster::Monster()
{
    cout << "Creating new monster!" << endl;
}

void Monster::speak()
{
    cout << "Roar Im a monster!!!" << endl;
}

Monster* Monster::getInstance()
{
    if (instance == NULL) 
    {
        instance = new Monster();
    }
    
    return instance;
}

Monster::~Monster()
{
}
