//
//  Treasure.h
//  DungeonCrawlv1
//
//  Created by Eddie Power on 15/05/12.
//  Copyright 2012 Monash University Student.
//  All rights reserved.
//

#ifndef DungeonCrawlv1_Treasure_h
#define DungeonCrawlv1_Treasure_h

#include "GameItem.h"

class Treasure : public GameItem
{
   protected:
       int m_nValue;
   public:
       Treasure();
       Treasure(string name, string type);
       ~Treasure();
       int getValue();
       string display();

};


#endif
