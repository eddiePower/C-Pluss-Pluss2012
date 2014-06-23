//
//  Invader.h
//  Week10Lab
//
//  Created by Eddie Power on 8/05/12.
//  Copyright (c) 2012 Monash University Student.
//  All rights reserved.
//

#ifndef Week10Lab_Invader_h
#define Week10Lab_Invader_h

#include "Enemy.h"

class Invader : public Enemy
{
    public:
    Invader(string name);
    string display();
    
};

#endif
