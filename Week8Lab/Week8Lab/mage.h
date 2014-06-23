//
//  mage.h
//  Week8Lab
//
//  Created by Eddie Power on 24/04/12.
//  Copyright (c) 2012 Monash University Student.
//  All rights reserved.
//

#ifndef Week8Lab_mage_h
#define Week8Lab_mage_h

#include "character.h"

class mage : public character
{
  private:
      int m_arcanPower;
  public:
      mage();
      mage(string name);
      void setCharType(string charType);
      string getCharType();
      int attack();
      string display();
};

#endif
