//
//  Potion.h
//  DungeonCrawlv1
//
//  Created by Eddie Power on 16/05/12.
//  Copyright (c) 2012 Monash University Student.
//  All rights reserved.
//

#ifndef DungeonCrawlv1_Potion_h
#define DungeonCrawlv1_Potion_h

#include "Treasure.h"

class Potion : public Treasure
{    
   public:
    Potion();
    ~Potion();
    string display();
};

#endif
