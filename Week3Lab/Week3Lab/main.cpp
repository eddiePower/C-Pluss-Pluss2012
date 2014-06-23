//
//  main.cpp
//  Week3Lab
//
//  Created by Eddie Power on 13/03/12.
//  Copyright (c) 2012 Monash University Student.
//  All rights reserved.
//

#include <iostream>
#include <string>
#include "Week3Lab.h"

using namespace std;

int main ()
{
    int nChoice = -1;
    
    do 
    {
        cout << "Eddie Power week 3 Lab work." << endl;
        cout << "\nMenu:" << endl;
        cout << "Enter 1 for Number Modifier." << endl;    
        cout << "Enter 2 for rough function tests." << endl;
        cout << "Enter 3 for times Table." << endl;
        /*cout << "Enter 4 for ." << endl;
        cout << "Enter 5 for ." << endl;*/
        cout << "Enter 0 to exit." << endl;
        
        cin >> nChoice;
        
        switch (nChoice) 
        {
            case 0:
                cout << "Bye!" << endl;
                break;
            case 1:
                numModifer();
                break;
            case 2:
                testQuestions();
                break;
            case 3:
                timesTables();
                break;
            default:
                cout << "Sorry please enter a valid menu choice!";
                break;
        }
    } while (nChoice != 0);
    
    
    return 0;
}

void numModifer()
{
    short signed nNum1 = 0;
    short signed nNum2 = 0;
    double dTemp = 0;
    short signed nMax = 32767;
    short signed nMin = -32768;    
    char cOperator;
    string sUserName;
    
    cout << "Number Modifer Program!" << endl;
    cout << "This program will accept 2 integers and a mathamatical modifier," << endl;
    cout << "and preform the requested calculation." << endl;
    cout << "\nSo who am I speaking to? ";
    cin >> sUserName;
    
    do 
    {
      cout << "\nHey " << sUserName <<"! Enter your first number? ";
      cin >> dTemp;
    }while (dTemp <= nMin || dTemp >= nMax);
    
    nNum1 = dTemp;
    
    do 
    {
      cout << "Now enter the second number? ";
      cin >> dTemp;
    } while (dTemp <= nMin || dTemp >= nMax);
    
    nNum2 = dTemp;
    
    //Operator validation to make sure user enters the correct modifier char.
    do 
    {
      cout << "\nLastly " << sUserName <<" what is the modifier (+, -, /, *)? ";
      cin >> cOperator;
    } while (cOperator != '+' && cOperator != '-' && cOperator != '/' && cOperator != '*');
    
    
    if(cOperator == '+')
    {
        cout << "The result of the operation is " << endl;
        cout << nNum1 << " + " << nNum2 << " = " << (nNum1 + nNum2) << endl;
    }
    else if(cOperator == '-')
    {
        cout << "The result of the operation is " << endl;        
        cout << nNum1 << " - " << nNum2 << " = " << (nNum1 - nNum2) << endl;
    }
    else if(cOperator == '/')
    {
        while (nNum1 == 0 || nNum2 == 0) 
        {
            if (nNum1 == 0) 
            {
                cout << "Cannot divide by 0." << endl;
                cout << "\nHey " << sUserName <<"! Enter your first number? ";
                cin >> nNum1;
            }
            else if(nNum2 == 0)
            {
                cout << "Cannot divide by 0." << endl;
                cout << "Enter the second number? ";
                cin >> nNum2;
            }
        }
        cout << "The result of the operation is " << endl;        
        cout << nNum1 << " / " << nNum2 << " = " << (nNum1 / nNum2) << endl;
    }
    else if(cOperator == '*')
    {
        cout << "The result of the operation is " << endl;        
        cout << nNum1 << " * " << nNum2 << " = " << (nNum1 * nNum2) << endl;
    }
    
}

void testQuestions()
{
  cout << "Number tester on: (number =5, max = 10, min = 0) " << isInRange(5, 10, 0) << endl;
  cout << "Number tester on: (number =11, max = 10, min = 0) " << isInRange(11, 10, 0) << endl;
  cout << "Character search on: (eddie, looking for i) " << charInString("eddie", 'i') << endl;
  cout << "Character search on: (John, looking for i) " << charInString("John", 'i') << endl;
  cout << "Date test on: (13/02/2012) " << isValidDate(13, 2, 2012) << endl;
  cout << "Date test on: (29/02/2012) " << isValidDate(29, 2, 2012) << endl;
  cout << "Date test on: (65/97/2012) " << isValidDate(65, 97, 2012) << endl;
  cout << "Prime number test on: (5) " << isPrime(5) << endl; 
  cout << "Prime number test on: (10) " << isPrime(10) << endl; 

}

bool isInRange(int nInput, int nMax, int nMin)
{
    bool result = false;
    if(nInput > nMax || nInput < nMin)
    {
        result = false;
    }
    
    result = true;
    
    return result;
}

int charInString(string sWord, char cSearch)
{
    for (int i = 0; i < sWord.length(); i++) 
    {
        if (cSearch == sWord[i]) 
        {
            return i;
        }
    }
        
    return -1;
}
bool isValidDate(int nDay, int nMonth, int nYear)
{
    int nMaxDay;
    
    if(!isInRange(nMonth, 1, 12))
    {
      return false;
    }
    
    if(nMonth == 2)
    {
        //Checking on a leap year according to google.
        if ((nYear % 4 == 0 && nYear % 100 != 0) || nYear % 400 == 0)
        {
            nMaxDay = 29;
        }
        else
        {
            nMaxDay = 28;
        }
    }
    else if(nMonth == 1 || nMonth == 3 || nMonth == 5 || nMonth == 7 || nMonth == 8 || nMonth == 10 || nMonth == 12)
    {
        nMaxDay = 31;
    }
    else
    {
        nMaxDay = 30;
    }
    
    if(isInRange(nDay, nMaxDay, 1))
    {
           return true;
    }
    
    return false;
}
bool isPrime(int nNumber)
{
    //Check if the number is negative and make it a positive.
    if(nNumber < 0)
    {
        nNumber *= -1;
    }
    
    
    for (int i = 2; i < nNumber; i++) 
    {
        //check if the number is a prime number by dividing
        // by i and checking there is no remainder.
        if(nNumber % i == 0)
        {
            return false;
        }
    }
    
    return true;
}

void timesTables()
{
    int nNum = 0;
    cout << "Times Table Program\n"; 
    cout << "This program will accept an integer between 1 and 10,";
    cout << "and display the times tables up to 100." << endl;
    cout << "\nWhat number would you like? ";
    cin >> nNum;
    
    for(int i = 1; (nNum * i) <= 100; i++)
    {
      cout << nNum << " times " << i << " is " << (nNum * i) << endl; 
    }
}




