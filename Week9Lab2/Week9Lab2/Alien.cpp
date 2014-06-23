//
//  Alien.cpp
//  Week9Lab2
//
//  Created by Eddie Power on 1/05/12.
//  Copyright (c) 2012 Monash University Student.
//  All rights reserved.
//

#include "Alien.h"

Alien::Alien()
{
    m_name = "NoOne";
    m_attack = new int(rand() % 10 + 1);
}

Alien::Alien(string name)
{
    m_name = name;
    m_attack = new int(rand() % 10 + 1);
}

Alien::~Alien()
{
    delete m_attack;
    m_attack = NULL;
}

int* Alien::getAttack()
{
    return m_attack;
}
