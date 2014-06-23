//
//  Player.cpp
//  DungeonCrawlv1
//
//  Created by Eddie Power on 10/05/12.
//  Copyright (c) 2012 Monash University Student. 
//  All rights reserved.
//

#include "Player.h"

Player::Player() : GameItem()
{
    m_sName = "NoOne";
    m_sType = "game_item";
    m_nHealth = 0;
    m_nSkill = 0;
    m_nScore = 0;
    m_nNumMonsterKills = 0;
    m_nNumTreasureFound = 0;
    m_nNumPotionsDrank = 0;
}

Player::Player(string name, string type) : GameItem(name, type)
{
    m_sName = name;
    m_sType = type;
    m_nHealth = rand() % 11 + 10;
    m_nSkill = rand() % 6 + 5;
    m_nScore = 0;
    m_nNumMonsterKills = 0;
    m_nNumTreasureFound = 0;
    m_nNumPotionsDrank = 0;
}

Player::~Player()
{
}

int Player::getMonsterKills()
{
    return m_nNumMonsterKills;
}

int Player::getTreasureFound()
{
    return m_nNumTreasureFound;
}

int Player::getPotionsFound()
{
    return m_nNumPotionsDrank;
}

void Player::addMonsterKills()
{
    m_nNumMonsterKills++;
}

void Player::addTreasureFound()
{
    m_nNumTreasureFound++;
}

void Player::addPotionsDrank()
{
    m_nNumPotionsDrank++;
}

int Player::getScore()
{
    return m_nScore;
}

void Player::setScore(int score)
{
    m_nScore += score;
}

int Player::getHealth()
{
    return m_nHealth;
}

int Player::getSkill()
{
    return m_nSkill;
}

void Player::setHealth(int health)
{
    m_nHealth += health;
}

void Player::setSkill(int skill)
{
    m_nSkill += skill;
}

int Player::movePlayer(char dir, Player *p)
{
    int x = p->getXlocation();
    int y = p->getYlocation();
    
    if (dir == 'n') 
    {
        if (y == 4 && x == 0) 
        {
            cout << "\nTheres a Northern door here" << endl;
            cout << "*************" << endl;
            cout << "*\t\t\t*"<< endl;
            cout << "*\t\t\t*"<< endl;
            cout << "*\t\t\t*"<< endl;
            cout << "* o\t\t\t*"<< endl;
            cout << "*\t\t\t*"<< endl;
            cout << "*\t\t\t*"<< endl;
            cout << "*\t\t\t*"<< endl;
            cout << "*************" << endl;
            return -1;
        }
        else if(x != 0)
        {
            p->setXlocation(x - 1);
            return 2;
        }
        else
        {
            cout << "\n\n******************************************" << endl;
            cout << "*\t\t\t\t\t\t\t\t\t\t *" << endl;
            cout << "*\t\t\t\t\t\t\t\t\t\t *" << endl;
            cout << "* Cant move that way theres a wall there *" << endl;
            cout << "******************************************\n" << endl;            
            return 1;
        }
    }
    else if(dir == 'e')
    {
        if (y == 9 && x == 4) 
        {
            cout << "\nTheres a Eastern door here" << endl;
            cout << "*************" << endl;
            cout << "*\t\t\t*"<< endl;
            cout << "*\t\t\t*"<< endl;
            cout << "*\t\t\t*"<< endl;
            cout << "* o\t\t\t*"<< endl;
            cout << "*\t\t\t*"<< endl;
            cout << "*\t\t\t*"<< endl;
            cout << "*\t\t\t*"<< endl;
            cout << "*************" << endl;
            return -1;
        }
        else if(y != 9)
        {
            p->setYlocation(y + 1);
            return 2;
        }
        else
        {
            cout << "\n\n******************************************" << endl;
            cout << "*\t\t\t\t\t\t\t\t\t\t *" << endl;
            cout << "*\t\t\t\t\t\t\t\t\t\t *" << endl;
            cout << "* Cant move that way theres a wall there *" << endl;
            cout << "******************************************\n" << endl; 
            return 1;
        }
    }
    else if(dir == 's')
    {
        if (y == 4 && x == 9) 
        {
            cout << "\nTheres a Southern door here" << endl;
            cout << "*************" << endl;
            cout << "*\t\t\t*"<< endl;
            cout << "*\t\t\t*"<< endl;
            cout << "*\t\t\t*"<< endl;
            cout << "* o\t\t\t*"<< endl;
            cout << "*\t\t\t*"<< endl;
            cout << "*\t\t\t*"<< endl;
            cout << "*\t\t\t*"<< endl;
            cout << "*************" << endl;            
            return -1;
        }
        else if(x != 9)
        {
            p->setXlocation(x + 1);
            return 2;
        }
        else
        {
            cout << "\n\n******************************************" << endl;
            cout << "*\t\t\t\t\t\t\t\t\t\t *" << endl;
            cout << "*\t\t\t\t\t\t\t\t\t\t *" << endl;
            cout << "* Cant move that way theres a wall there *" << endl;
            cout << "******************************************\n" << endl; 
            return 1;
        }
    }
    else if(dir == 'w')
    {
        if (y == 0 && x == 4) 
        {
            cout << "\nTheres a Western door here" << endl;
            cout << "*************" << endl;
            cout << "*\t\t\t*"<< endl;
            cout << "*\t\t\t*"<< endl;
            cout << "*\t\t\t*"<< endl;
            cout << "* o\t\t\t*"<< endl;
            cout << "*\t\t\t*"<< endl;
            cout << "*\t\t\t*"<< endl;
            cout << "*\t\t\t*"<< endl;
            cout << "*************" << endl;           
            return -1;
        }
        else if(y != 0)
        {
            p->setYlocation(y - 1);
            return 2;
        }
        else
        {
            cout << "\n\n******************************************" << endl;
            cout << "*\t\t\t\t\t\t\t\t\t\t *" << endl;
            cout << "*\t\t\t\t\t\t\t\t\t\t *" << endl;
            cout << "* Cant move that way theres a wall there *" << endl;
            cout << "******************************************\n" << endl; 
            return 1;
        }
    }
    else
    {
        cout << "\n\n******************************************" << endl;
        cout << "*\t\t\t\t\t\t\t\t\t\t *" << endl;
        cout << "*\t\t\t\t\t\t\t\t\t\t *" << endl;
        cout << "* Cant move that way theres a wall there *" << endl;
        cout << "******************************************\n" << endl; 
        return 1;
    }
}

void Player::beHit(int nHitAmount)
{
    m_nHealth -= nHitAmount;
}

string Player::display()
{
    stringstream output;
    
    output << "Players stats:\nHealth: " << m_nHealth << "\nSkill: " << m_nSkill;
    output << "\nLocation: (" << m_nXloc << "," << m_nYloc << ")\nNumber of Monsters Killed: ";
    output << m_nNumMonsterKills << "\nNumber of Potions consumed: " << m_nNumPotionsDrank;
    output << "\nNumber of Treasures found: " << m_nNumTreasureFound << "\n";
    output << "Total Score: " << m_nScore;
    
    return output.str();
}
