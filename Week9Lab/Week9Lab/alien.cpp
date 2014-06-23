/*
 *  alien.cpp
 *  Week06Portfolio
 *
 *  Created by Matthew Butler on 2/03/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "alien.h"


using namespace std;

// Create a new alien. Set name then other stats to random values
alien::alien(string n)
{
	srand(unsigned(time(0)));
	m_sName = new string(n);
	m_nAge = new int(0);
	m_nHealth = new int(rand()%5 + 3);
	m_nHunger = new int(rand()%5 + 3);
	m_nHappiness = new int(rand()%5 + 3);
}

alien::~alien() 
{
}

// Return the current age of the alien
int alien::getAge() 
{
	return *m_nAge;
}

int alien::getHealth()
{
	return *m_nHealth;
}

// return a string with the aliens details
string alien::displayAlien() 
{
	stringstream sAlienDetails;
    
	sAlienDetails << "Current stats for " << m_sName << "\n";
	sAlienDetails << "Age: " << m_nAge << "\n";
	sAlienDetails << "Health: " << m_nHealth << endl;
	sAlienDetails << "Happiness: " << m_nHappiness << endl;
	sAlienDetails << "Hunger: " << m_nHunger << endl;

	return sAlienDetails.str();
}

// Make the alien get older by increasing/decreasing stats
// Note it is a generic function that can change the stats by any amount
void alien::getOlder(int age, int health, int happiness, int hunger) 
{
	m_nAge += age;
	m_nHealth += health;
	m_nHappiness += happiness;
	m_nHunger += hunger;
}

// Change health by the given amount
void alien::changeHealth(int n)
{
	m_nHealth += n;
}

// Change happiness by the given amount
void alien::changeHappiness(int n) 
{
	m_nHappiness += n;	
}

// Change hunger by the given amount
void alien::changeHunger(int n) 
{
	m_nHunger += n;	
}

// Check the stats of the aline to see if it is OK
bool alien::checkAlien() 
{
	if (*m_nHealth <= 0 || *m_nHappiness <= 0 || *m_nHunger >= 10)
		return true;
	else
		return false;
}

