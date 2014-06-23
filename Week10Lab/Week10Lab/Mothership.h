//
//  Mothership.h
//  Week10Lab
//
//  Created by Eddie Power on 8/05/12.
//  Copyright (c) 2012 Monash University Student. All rights reserved.
//

#ifndef Week10Lab_Mothership_h
#define Week10Lab_Mothership_h

#include "Enemy.h"

class Mothership : public Enemy
{
    public:
    Mothership(string name);
    string display();
    
};

#endif
