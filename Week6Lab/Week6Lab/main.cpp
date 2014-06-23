//
//  main.cpp
//  Week6Lab
//
//  Created by Eddie Power on 3/04/12.
//  Copyright (c) 2012 Monash University Student.
//  All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void loadNames(vector<string>& namesVector);
void displayNames(const vector<string>& namesVector);
void sortNames(vector<string>& namesVector);

int main()
{
    
    vector<string> vNames;
    
    //loop through an array by pointers. Must be carefull as pointers
    // may not point to anything usefull or even allowd, this is called
    // pointer arithmatic.
    int myIntArray[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int* pMyArray = &myIntArray[0];
    
    for (int i = 0; i < 10; i++) 
    {
        cout << *pMyArray << endl;
        pMyArray++;
    }
    
    
    string s1 = "Eddie";
    string s2 = "JoeBlo";
    int n1 = 13;
    int n2 = 7;
    
    string* pS1 = &s1;
    int* pN1 = &n1;
    int* pN2 = &n2;
    
    cout << pS1 << " is a memory address." << endl;
    cout << *pS1 << " is the variable stored." << endl;
    //cout << (*pS1).length() << " is not how we should do this but it works." << endl;
    //This is the correct way to run functions on a pointer, functions are
    // the same as the type pointed to so in this case string.length() etc.
    cout << pS1->length() << " is how we should do this.\n" << endl;
    
    pS1 = &s2;
    
    cout << pS1 << " is a memory address." << endl;
    cout << *pS1 << " is the variable stored." << endl;
    //cout << (*pS1).length() << " is not how we should do this." << endl;
    cout << pS1->length() << " is how we should do this.\n" << endl;
   
    loadNames(vNames);
    displayNames(vNames);
    sortNames(vNames);
    displayNames(vNames);

    //system("PAUSE");
    return 0;
}

void loadNames(vector<string>& namesVector)
{
    string sInput;
    
    do 
    {
        cout << "Enter a name: ";
        cin >> sInput;
        if (sInput != "-1") 
        {
            namesVector.push_back(sInput);
        }
    }while (sInput != "-1");
    
}

void displayNames(const vector<string>& namesVector)
{
    cout << "\nAll Names:" << endl;
    for (int i = 0; i < namesVector.size(); i++) 
    {
        cout << namesVector[i] << endl;
    }
}

void sortNames(vector<string>& namesVector)
{
    sort(namesVector.begin(), namesVector.end());
}
