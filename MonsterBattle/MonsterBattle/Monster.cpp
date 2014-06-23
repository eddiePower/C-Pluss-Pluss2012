//
//  Monster.cpp
//  MonsterBattle
//
//  Created by Eddie Power on 8/04/12.
//  Copyright 2012 Monash University Student.
//  All rights reserved.
//

#include "Monster.h"

//Constructors.
Monster::Monster()
{
    m_sMonster_name = "noOne";
    m_nMonster_skill = 0;
    m_nMonster_health = 0;
    m_bMagicMonster = false;
}
//non default constructor runs with random numbers for skill,
// health and name is named by the player
Monster::Monster(string sName, int nSkill, int nHealth)
{
    m_sMonster_name = sName;
    m_nMonster_skill = nSkill;
    m_nMonster_health = nHealth;
    m_bMagicMonster = false;
}
//destructor
Monster::~Monster()
{
    //cout << "A monster dies a horrible monster death!" << endl;
}

//Getter methods.
string Monster::getMonsterName()
{
    return m_sMonster_name;
}
int Monster::getMonsterSkill()
{
    return m_nMonster_skill;
}
int Monster::getMonsterHealth()
{
    return m_nMonster_health;
}
bool Monster::getBoolMagicMonster()
{
    return m_bMagicMonster;
}

//Setter methods.
void Monster::setMonsterName(string sName)
{
    m_sMonster_name = sName;
}
void Monster::setMonsterSkill(int nSkill)
{
    m_nMonster_skill = nSkill;
}
void Monster::setMonsterHealth(int nHealth)
{
    m_nMonster_health = nHealth;
}
void Monster::setBoolIsMagicMonster(bool bHasMagic)
{
    m_bMagicMonster = bHasMagic;
}

//Other class methods.
bool Monster::checkMonsterHealth()
{
   if (m_nMonster_health >= 1) 
   {
      return true;
   }
   else
   {
      //set user health to 0 in case it has fallen below 0
      // this is just to make player stats more readable to humans.
      m_nMonster_health = 0;
      return false;
   }
}

int Monster::getMonsterAttackTotal(int nSkill)
{
   //generate a random number from 1-12 as described in the directions.
   int nAttackRand = (rand() % 12) + 1;
   //add the attack number and the monster skill level to get total attack power.
   int nAttackPower = nAttackRand + nSkill;
    
   return nAttackPower;
}

// return a string with the Monster details
string Monster::displayMonster()
{
	stringstream sMonsterDetails;
    
	sMonsterDetails << "Stats for Monster: " << m_sMonster_name << "\n";
	sMonsterDetails << "Health: " << m_nMonster_health << "\n";
	sMonsterDetails << "Skill: " << m_nMonster_skill << endl;
    
	return sMonsterDetails.str();
}




