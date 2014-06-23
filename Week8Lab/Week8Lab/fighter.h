//
//  fighter.h
//  Week8Lab
//
//  Created by Eddie Power on 24/04/12.
//  Copyright (c) 2012 Monash University Student. All rights reserved.
//

#ifndef Week8Lab_fighter_h
#define Week8Lab_fighter_h

#include "character.h"

class fighter : public character
{
  private:
      int m_strength;
  public:
      fighter();
      fighter(string name);
      void setCharType(string charType);
      string getCharType();
      int attack();
      string display();
};

#endif
