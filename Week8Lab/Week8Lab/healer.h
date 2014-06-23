//
//  healer.h
//  Week8Lab
//
//  Created by Eddie Power on 24/04/12.
//  Copyright (c) 2012 Monash University Student. All rights reserved.
//

#ifndef Week8Lab_healer_h
#define Week8Lab_healer_h

#include "character.h"

class healer : public character
{
   private:
      int m_divinePower;
   public:
      healer();
      healer(string name);
      void setCharType(string charType);
      string getCharType();
      int attack();
      string display();
};

#endif