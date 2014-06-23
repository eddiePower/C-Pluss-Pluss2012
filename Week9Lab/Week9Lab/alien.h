/*
 *  alien.h
 *  Week06Portfolio
 *
 *  Created by Matthew Butler on 2/03/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef ALIEN_H
#define ALIEN_H

#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>
#include <string>

using namespace std;

class alien {

public:
	alien(string n);
	~alien();
	int getAge();
	int getHealth();
	string displayAlien();
	void getOlder(int age, int health, int happiness, int hunger);
	void changeHealth(int n);
	void changeHappiness(int n);
	void changeHunger(int n);
	bool checkAlien();
    friend bool ageIsEqual(alien &a1, alien &a2);	
private:
	string* m_sName;
	int* m_nAge;
	int* m_nHealth;
	int* m_nHunger;
	int* m_nHappiness;

};

#endif