//
//  Alien.h
//  Week9Lab2
//
//  Created by Eddie Power on 1/05/12.
//  Copyright (c) 2012 Monash University Student. All rights reserved.
//

#ifndef Week9Lab2_Alien_h
#define Week9Lab2_Alien_h

#include <iostream>
#include <string>

using namespace std;

class Alien
{
  private:
    string m_name;
    int* m_attack;
  public:
    Alien();
    Alien(string name);
    ~Alien();
    
    int* getAttack();
        
    friend bool compare(Alien& a1, Alien& a2);
    friend bool operator==(Alien& a1, Alien& a2);
    friend ostream& operator<<(ostream& os, const Alien& a);

};


#endif
