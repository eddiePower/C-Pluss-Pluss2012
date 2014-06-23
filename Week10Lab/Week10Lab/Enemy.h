//
//  Enemy.h
//  Week10Lab
//
//  Created by Eddie Power on 8/05/12.
//  Copyright (c) 2012 Monash University Student.
//  All rights reserved.
//

#ifndef Week10Lab_Enemy_h
#define Week10Lab_Enemy_h
#include <iostream>
#include <string>

using namespace std;

class Enemy
{
  protected:
     string m_name;
  public:
      Enemy(string name);
      virtual string display();
    
};

#endif
