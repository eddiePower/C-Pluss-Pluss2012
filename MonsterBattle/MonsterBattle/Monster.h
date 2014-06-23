//
//  MonsterBattle.h
//  MonsterBattle
//
//  Created by Eddie Power on 8/04/12.
//  Copyright 2012 Monash University Student.
//  All rights reserved.
//

#ifndef MONSTER_H_
  #define MONSTER_H_

  #include <iostream>
  #include <vector>
  #include <time.h>
  #include <string>
  #include <sstream>

  using namespace std;

  class Monster 
  {
     protected:
       string m_sMonster_name;
       int m_nMonster_skill;
       int m_nMonster_health;
       bool m_bMagicMonster;
     public:
      //constructors
      Monster();
      Monster(string sName, int nSkill, int nHealth);
      ~Monster();
      //getters
      string getMonsterName();
      int getMonsterSkill();
      int getMonsterHealth();
      bool getBoolMagicMonster();
      //setters
      void setMonsterName(string sName);
      void setMonsterSkill(int nSkill);
      void setMonsterHealth(int nHealth);
      void setBoolIsMagicMonster(bool bHasMagic);
      //other class methods
      bool checkMonsterHealth();
      int getMonsterAttackTotal(int nSkill);
      virtual string displayMonster();      
  };


#endif
