//
//  character.h
//  Week8Lab
//
//  Created by Eddie Power on 24/04/12.
//  Copyright (c) 2012 Monash University Student. All rights reserved.
//

#ifndef Week8Lab_character_h
#define Week8Lab_character_h
  
  #include <iostream>
  #include <time.h>
  #include <sstream>
  #include <vector>
  #include <string>
  
  using namespace std;
  
class character
{
   protected:
      string m_name;
      int m_baseAttack;
      int m_currentHealth;
      int m_maxHealth;
      string m_charType;
   public:
      character();
      character(string name);  
      //class methods
      virtual int attack();
      void beHit(int amount);
      virtual string display();  
      void setCharType(string charType);
      string getCharType();
};
  
#endif
