//////////////////////////////////////////////////////////
//  main.cpp                                           //
//  Week2Lab                                          //
//                                                   //
//  Created by Eddie Power on 4/03/12.              //
//  Copyright (c) 2012 Monash University Student.  //
//  All rights reserved.                          //
///////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <fstream>
#include "Week2Lab.h"

using namespace std;

int main ()
{
    int nChoice = -1;
    
    
    while (nChoice != 0) 
    {
        cout << "Eddie Power week 2 Lab work." << endl;
        cout << "\nMenu:" << endl;
        cout << "Enter 1 for Number divisor." << endl;    
        cout << "Enter 2 for Number Modifer." << endl;
        cout << "Enter 3 for string analyser." << endl;
        cout << "Enter 4 for troubleshoot exercise." << endl;
        cout << "Enter 5 for Currency Converter." << endl;
        cout << "Enter 0 to exit." << endl;
        
       cin >> nChoice;
        
        switch (nChoice) 
        {
            case 0:
                cout << "Bye!" << endl;
                break;
            case 1:
                numDivider();
                break;
            case 2:
                numModifer();
                break;
            case 3:
                analyseString();
                break;
            case 4:
                troubleshoot();
                break;
            case 5:
                currency();
                break;
            default:
                cout << "Sorry please enter a valid menu choice!";
                break;
        }
    }
    
    return 0;
}

void numDivider()
{
    int nNumber = 0;
    int nDivisor = 0;
    
    cout << "NumberBot 4000" << endl;
    cout << "This program will accept a number and a divisor and tell you the result." << endl;
    
    cout << "\nWhat number would you like me to divide? ";    
    cin >> nNumber;
    cout << "\nWhat shall I divide by? ";
    cin >> nDivisor;
    
    while(nDivisor == 0)
    {
        cout << "Cannot divide by 0." << endl;
        cout << "\nWhat shall I divide by? ";
        cin >> nDivisor;
    }
    
      cout << "\n" << nNumber << " divided by " << nDivisor << " is ";
      cout << (nNumber/nDivisor) << " with ";
      cout << (nNumber % nDivisor) << " remainder." << endl;
}

void numModifer()
{
    int nNum1 = 0;
    int nNum2 = 0;
    char cOperator;
    string sUserName;
    
    cout << "Number Modifer Program!" << endl;
    cout << "This program will accept 2 integers and a mathamatical modifier," << endl;
    cout << "and preform the requested calculation." << endl;
    cout << "\nSo who am I speaking to? ";
    cin >> sUserName;
    
    cout << "\nHey " << sUserName <<"! Enter your first number? ";
    cin >> nNum1;
    cout << "Now enter the second number? ";
    cin >> nNum2;
    cout << "\nLastly " << sUserName <<" what is the modifier (+, -, /, *)? ";
    cin >> cOperator;
    
    //Can be done by a switch statement!
    
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
    else
    {
        cout << "sorry " << sUserName << " I dont recognise your operator!" << endl;
    }

}

void analyseString()
{
    string sUserString;
    char cUserChar;
    
    cout << "\nWelcome to the string analyser" << endl;
    cout << "What is your word? ";
    cin >> sUserString;
    cout << "What character are you looking for? ";
    cin >> cUserChar;
    
    cout << "The string entered was " << sUserString << endl;
    cout << "It has " << sUserString.size() << " characters" << endl;
    cout << "It has been allocated " << sUserString.capacity() << " bytes in memory" << endl;
    cout << "The first character is " << sUserString.at(0) << endl;
    cout << "The last character is " << sUserString[sUserString.size() - 1] << endl;
    cout << "The search character is found at index " << sUserString.find(cUserChar) << endl;
    
}

void troubleshoot()
{    
    string myName; 
    int nDay;
    int nMonth; 
    int nYear;
    int const nThisYear = 2012;
    fstream myfile;
    
    cout << "What is your first name? ";
    cin >> myName;
    cout << "What day of the month were you born? "; 
    cin >> nDay;
    cout << "And in what month? ";
    cin >> nMonth;
    cout << "And in what year? ";
    cin >> nYear;
    cout << "\nHello " << myName << "!! You will be " << nThisYear - nYear << " years old this year." << endl;
    
    myfile.open("mydetails.txt");
    myfile << myName << endl << nDay << endl << nMonth << endl << nYear << endl;
    myfile.close();
    
    
    myfile.open("mydetails.txt");
    myfile >> myName;
    myfile >> nDay;
    myfile >> nYear;
    cout << "\nWelcome back " << myName << "!! Your birthday is " << nDay << "/" << nMonth << "/" << nYear << endl;
    cout << "You will be " << (nThisYear - nYear) << " years old this year on "<< nDay << "/" << nMonth << "/" << nThisYear << ".\n" << endl;
    myfile.close();

}

void currency()
{
    //Declare variables for both dollars, cents and also the file stream.
    float fAmount;
    float fUSD, fGBP, fEURO, fYEN;
    int nRoundedAUD, nRoundedUSD, nRoundedGBP, nRoundedEURO, nRoundedYEN;
    fstream exchangeRate;
    
    //User information on program use.
    cout << "Welcome to my Currency Converter." << endl;
    cout << "\nThe current exchange rates for 1 AUD are:\n" << endl;
    
    //Open a input stream or file and read values into the variables. 
    exchangeRate.open("currency.txt");
    exchangeRate >> fUSD;
    exchangeRate >> fGBP;
    exchangeRate >> fEURO;
    exchangeRate >> fYEN;
    exchangeRate.close();
    
    cout << fUSD << " USD,\n";
    cout << fGBP << " GBP,\n";
    cout << fEURO << " EURO,\n";
    cout << fYEN << " YEN.\n";
    
    //Ask the user for the amount of AUD they want to convert.
    cout << "\nHow many Australian Dollars would you like to convert? ";
    cin >> fAmount;
   
    //Convert from dollars to cents or pounds to pence etc for easier conversion.
    //i.e: $1 = 100c or 2* 100 = 200 cents.
    nRoundedAUD = fAmount * 100;
    nRoundedUSD = fAmount * 100 * fUSD;
    nRoundedGBP = fAmount * 100 * fGBP;
    nRoundedEURO = fAmount * 100 * fEURO;
    nRoundedYEN = fAmount * 100 * fYEN;
    
    //Output the results to the screen for the user.
    cout << "\nResults:\n";
    cout << "$" << fAmount << " is " << (nRoundedUSD/100) << "." << (nRoundedUSD % 100) << " USD,\n";
    cout << "$" << fAmount << " is " << (nRoundedGBP/100) << "." << (nRoundedGBP % 100) << " GBP,\n";
    cout << "$" << fAmount << " is " << (nRoundedEURO/100) << "." << (nRoundedEURO % 100) << " EURO,\n";
    cout << "$" << fAmount << " is " << (nRoundedYEN/100) << "." << (nRoundedYEN % 100) << " YEN.\n";

}
