//
//  Player.h
//  DungeonCrawlv1
//
//  Created by Eddie Power on 10/05/12.
//  Copyright (c) 2012 Monash University Student.
//  All rights reserved.
//

#ifndef DungeonCrawlv1_Player_h
#define DungeonCrawlv1_Player_h

#include "GameItem.h"

class Player : public GameItem
{
   protected:
       int m_nHealth;
       int m_nSkill;
       int m_nScore;
       int m_nNumMonsterKills;
       int m_nNumTreasureFound;
       int m_nNumPotionsDrank;
   public:
      Player();
      Player(string name, string type);
      ~Player();
      int getHealth();
      int getSkill();
      int getScore();
      void setScore(int score);
      void setHealth(int health);
      void setSkill(int skill);
      void beHit(int nHitAmount);
      void addMonsterKills();
      void addTreasureFound();
      void addPotionsDrank();
      int getMonsterKills();
      int getTreasureFound();
      int getPotionsFound();
      int movePlayer(char dir, Player* p);  
      virtual string display();
};

#endif
