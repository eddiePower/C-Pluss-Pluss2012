//
//  Mothership.cpp
//  Week10Lab
//
//  Created by Eddie Power on 8/05/12.
//  Copyright (c) 2012 Monash University Student. All rights reserved.
//

#include <iostream>
#include "Mothership.h"

Mothership::Mothership(string name) : Enemy(name)
{
    
}

string Mothership::display()
{
    return "Mothership " + m_name;
}