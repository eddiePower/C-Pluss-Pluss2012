//
//  Week07_Monster.h
//  Week7Lab
//
//  Created by Eddie Power on 17/04/12.
//  Copyright (c) 2012 Monash University Student.
//  All rights reserved.
//

#ifndef Week7Lab_Week07_Monster_h
#define Week7Lab_Week07_Monster_h

#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

class Monster
{
private:
    string m_name;
public:
    Monster();
    Monster(string name);
    ~Monster();
    string getName();
};



#endif
