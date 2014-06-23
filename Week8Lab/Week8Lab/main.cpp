//
//  main.cpp
//  Week8Lab
//
//  Created by Eddie Power on 24/04/12.
//  Copyright (c) 2012 Monash University Student.
//  All rights reserved.
//

#include "fighter.h"
#include "mage.h"
#include "healer.h"
#include "boss.h"

int main ()
{
    srand((unsigned)time(0));
    vector<character*> charParty;
    boss* pMyBoss = new boss("DeathWing");
    int nBeHealed = rand() % 3;
    
    charParty.push_back(new fighter("Aggressive guy"));
    charParty.push_back(new healer("Healing guy"));
    charParty.push_back(new mage("Magic guy"));

    cout << "THE BOSS" << endl;
    cout << pMyBoss->display() << endl;
    
    while (pMyBoss->getHealth() > 0) 
    {
      cout << "THE PARTY!" << endl;
      for (int i = 0; i < charParty.size(); i++) 
      {
          int attackAmount = charParty[i]->attack();
          
          cout << charParty[i]->display() << endl;
          
          if (attackAmount < 0 && (charParty[nBeHealed]->getCharType() != "Healer" && charParty[nBeHealed]->getCharType() != "Boss")) 
          {
              cout << "Healed the " << charParty[nBeHealed]->getCharType() << " for: " << attackAmount << endl;
              charParty[nBeHealed]->beHit(attackAmount);
          }
          else
          {
              cout << "They attack the boss for: " << attackAmount << endl;
              pMyBoss->beHit(attackAmount);
              
              cout << "THE BOSS!" << endl;
              cout << pMyBoss->display() << endl;
          }
      }
    
      cout << "THE BOSS!" << endl;
      cout << pMyBoss->display() << endl;
    }
  
    //Used to loop through the vector and delete 
    // each heap based object
    for(int i = 0; i < charParty.size(); i++) 
    {
       delete charParty[i];
       charParty[i] = NULL;
    }   
    
    charParty.clear();
    delete pMyBoss;
    pMyBoss = NULL;
    
    return 0;
}
