//
//  Room.h
//  DungeonCrawlv1
//
//  Created by Eddie Power on 10/05/12.
//  Copyright (c) 2012 Monash University Student.
//  All rights reserved.
//

#ifndef DungeonCrawlv1_Room_h
#define DungeonCrawlv1_Room_h

#include <iostream>
#include <vector>
#include <time.h>
#include <sstream>

using namespace std;

class Room
{
   private:
      vector<vector<string> > m_vXyVector; 
   public:
      Room();
      ~Room();
      string printRoom();
      void setLocation(string cItemType, int x, int y);
      string getItem(int x, int y);
};

#endif
