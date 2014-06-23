//
//  MagicMonster.cpp
//  testVectorMonster
//
//  Created by Eddie Power on 28/04/12.
//  Copyright (c) 2012 Monash University Student.
//  All rights reserved.
//

#include "MagicMonster.h"

int MagicMonster::m_nNumMagicMonsters = 0;

MagicMonster::MagicMonster()
{
    if (m_nNumMagicMonsters == 1) 
    {
        m_cMagicType = 'h';
    }
    else
    {
        m_cMagicType = 's';
    }
    m_nMagicAmount = 0;
    m_nMagicPower = 0;
    m_bMagicMonster = true;
    m_nNumMagicMonsters++;
}

MagicMonster::MagicMonster(string sName, int nSkill, int nHealth) : Monster(sName, nSkill, nHealth)
{    
    if (m_nNumMagicMonsters == 1) 
    {
        m_cMagicType = 'h';
    }
    else
    {
        m_cMagicType = 's';
    }
    m_nMagicPower = (rand() % 3) + 5;
    m_nMagicAmount = 3;
    m_bMagicMonster = true;
    m_nNumMagicMonsters++;
}

char MagicMonster::getMagicType()
{
    return m_cMagicType;
}

int MagicMonster::getMagicAmount()
{
    return m_nMagicAmount;
}

int MagicMonster::getMagicPower()
{
    return m_nMagicPower;
}

void MagicMonster::setMagicType(char cMagicType)
{
    m_cMagicType = cMagicType;
}

void MagicMonster::setMagicAmount(int nMagicAmount)
{
    m_nMagicAmount = nMagicAmount;
}

void MagicMonster::setMagicPower(int nMagicPower)
{
    m_nMagicPower = nMagicPower;
}

int MagicMonster::didUseMagic(int nMagicPower)
{
    //rand from 1 - 12
    int nRandMagicUsed = (rand() % 12) + 1;
    int nReturnMagic = 0;
    
    if(nRandMagicUsed <= nMagicPower) 
    {
        //cout << "MagicUsed rand num was " << nRandMagicUsed << endl;
        nReturnMagic = -1;
    }
    else if(nRandMagicUsed > nMagicPower)
    {
        nReturnMagic = nRandMagicUsed - nMagicPower;
        //cout << "MagicUsed rand num was " << nRandMagicUsed << endl;
        //cout << "returning magic amount is " << nReturnMagic << endl;
    }
    
    return nReturnMagic;
}

// return a string with the Monster details
string MagicMonster::displayMonster()
{
	stringstream sMonsterDetails;
    
	sMonsterDetails << "Stats for Monster: " << m_sMonster_name << "\n";
	sMonsterDetails << "Health: " << m_nMonster_health << "\n";
	sMonsterDetails << "Skill: " << m_nMonster_skill << "\n";
	sMonsterDetails << "Magic Type: " << m_cMagicType << "\n";
	sMonsterDetails << "Magic Amount: " << m_nMagicAmount << "\n";
	sMonsterDetails << "Magic Power: " << m_nMagicPower << "\n";
    
	return sMonsterDetails.str();
}



