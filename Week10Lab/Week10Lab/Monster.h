//
//  Monster.h
//  Week10Lab
//
//  Created by Eddie Power on 8/05/12.
//  Copyright (c) 2012 Monash University Student.
//  All rights reserved.
//
//  This is singleton class example.
//

#ifndef Week10Lab_Monster_h
#define Week10Lab_Monster_h

#include <iostream>
#include <string>

using namespace std;

class Monster
{
   private:
      Monster();
      static Monster* instance;
   public:
      ~Monster();
      static Monster* getInstance();
      void speak();
};

#endif
