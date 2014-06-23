//
//  BossMonster.h
//  DungeonCrawlv1
//
//  Created by Eddie Power on 15/05/12.
//  Copyright 2012 Monash University Student.
//  All rights reserved.
//

#ifndef DungeonCrawlv1_BossMonster_h
#define DungeonCrawlv1_BossMonster_h

#include "Monster.h"

class BossMonster : public Monster
{
   private:
      static int m_nNumBoss;
   public:
      BossMonster();
      BossMonster(string name, string type);
      ~BossMonster();
      string display();
};


#endif
