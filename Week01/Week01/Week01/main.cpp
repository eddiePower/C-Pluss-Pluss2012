//
//  Hello world code.
//  Week01
//
//  Created by Eddie Power on 2/03/12.
//  Copyright (c) 2012 Monash University Student.
//  All rights reserved.
//

#include <iostream>
#include <time.h>

using namespace std;

int main()
{	
    //seed (create) random number based on time from system clock in milliseconds.
	srand(time(0));
	int number;
    //call the seeded random number and range it between 1 - 10.
	int hidden = (rand() % 10) + 1;
    
	//cout << "Max number:" << RAND_MAX << endl;
	cout << "Enter your guess between 1 - 10: " << endl;
	cin >> number;
    
	//logic controle statement should go here to check user input.
    while(number < 1 || number > 10)
    {
        cout << "Your guess must be between 1 to 10" << endl;
        cout << "\nRe enter your guess between 1 - 10: " << endl;
        cin >> number;
    } 
    
    while (number != hidden) 
    {
        if (number < hidden) 
        {
            cout << "You suck it is higher!" << endl;
        }
        else
        {
            cout << "You suck it is lower!" << endl;
        }
        
        //cout << "Max number:" << RAND_MAX << endl;
        cout << "Guess Again: " << endl;
        cin >> number;
        
        //logic control statement should go here to check user input.
        while(number < 1 || number > 10)
        {
            cout << "Your guess must be between 1 to 10" << endl;
            cout << "\nRe enter your guess: " << endl;
            cin >> number;
        }
    }
    cout << "\nWELL DONE!! you guessed " << number << " which is correct." << endl;
    
    
    //cin.get();
    //system("PAUSE");
	return 0;
}
