//
//  Enemy.cpp
//  Week10Lab
//
//  Created by Eddie Power on 8/05/12.
//  Copyright (c) 2012 Monash University Student. 
//  All rights reserved.
//

#include <iostream>
#include "Enemy.h"

Enemy::Enemy(string name)
{
    m_name = name;   
}

string Enemy::display()
{
    return "Enemy " + m_name;
}
