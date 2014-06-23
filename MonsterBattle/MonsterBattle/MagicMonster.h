//
//  MagicMonster.h
//  MonsterBattle
//
//  Created by Eddie Power on 29/04/12.
//  Copyright 2012 Monash University Student.
//  All rights reserved.
//

#ifndef MonsterBattle_MagicMonster_h
#define MonsterBattle_MagicMonster_h

#include "Monster.h"

class MagicMonster : public Monster
{
private:
    char m_cMagicType;
    int m_nMagicPower;
    int m_nMagicAmount;
public:
    MagicMonster();
    MagicMonster(string sName, int nSkill, int nHealth);
    ~MagicMonster();    
    //getters
    char getMagicType();
    int getMagicAmount();
    int getMagicPower();
    //setters
    void setMagicType(char cMagicType);
    void setMagicAmount(int nMagicAmount);
    void setMagicPower(int nMagicPower);
    //class methods
    int didUseMagic(int nMagicPower);
    string displayMonster();
    static int m_nNumMagicMonsters;    
};


#endif
