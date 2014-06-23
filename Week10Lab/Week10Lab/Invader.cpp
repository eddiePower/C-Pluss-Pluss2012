//
//  Invader.cpp
//  Week10Lab
//
//  Created by Eddie Power on 8/05/12.
//  Copyright (c) 2012 Monash University Student. All rights reserved.
//

#include <iostream>
#include "Invader.h"


Invader::Invader(string name) : Enemy(name)
{    
}

string Invader::display()
{
    return "Invader " + m_name;
}