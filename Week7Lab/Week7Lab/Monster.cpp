//
//  Monster.cpp
//  Week7Lab
//
//  Created by Eddie Power on 17/04/12.
//  Copyright (c) 2012 Monash University Student.
//  All rights reserved.
//

#include "Week07_Monster.h"

Monster::Monster()
{
    m_name = "NoOne";
}
Monster::Monster(string name)
{
    m_name = name;
}
Monster::~Monster()
{    
}
string Monster::getName()
{
    return m_name;
}