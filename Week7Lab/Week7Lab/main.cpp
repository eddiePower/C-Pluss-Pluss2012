//
//  main.cpp
//  Week7Lab
//
//  Created by Eddie Power on 17/04/12.
//  Copyright (c) 2012 Monash University Student.
//  All rights reserved.
//

#include "Week07_Monster.h"

int main ()
{
    Monster* newAlien;
    vector<Monster*> monVec;
    //String stream must be included sstream. 
    //it is used to create a string to be used.
    for (int i = 0; i <= 10; i++) 
    {
        stringstream newName;
        newName << "Alien" << i;
        newAlien = new Monster(newName.str());
        cout << newAlien->getName() << endl;
        monVec.push_back(newAlien);

    }
    
    //then we can clear the whole vector.
    monVec.clear();
    
    //remove from the heap. Quick fix but an array of aliens is better 
    // we can then delete them one by one later not leak all but last one.
    //delete newAlien;
    
    vector<Monster> myMonsterVector;
    
    Monster* mon1 = new Monster("Eddie"); 
    
    myMonsterVector.push_back(*mon1);
    
    //derefrence using the ->
    for (int i = 0; i < myMonsterVector.size(); i++) 
    {
        cout << myMonsterVector[i].getName() << endl;
    }

    //delete monster off the heap
    delete mon1;
    
    int arraySize = 0;
    
    cout << "Enter size of the array: ";
    cin >> arraySize;
    
    //to work with the heap we must use pointers
    int* intArray = new int[arraySize];
    
    for (int i=0; i < arraySize; i++) 
    {
        intArray[i] = i + 1;
    }
    
    for (int i = 0; i < arraySize; i++) 
    {
        cout << intArray[i] << endl;
    }
    
    //delete the array from the heap.
    //every new word needs a delete statement.
    delete[] intArray;
    //set the pointer to null so you can use the pointer later
    intArray = NULL;
    
    return 0;
}

