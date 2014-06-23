//
//  main.cpp
//  Week12Lab
//
//  Created by Eddie Power on 22/05/12.
//  Copyright (c) 2012 Monash University Student.
//  All rights reserved.
//

#include <iostream>
void bubbleSort(const int LENGTHARRAY, int numbers[LENGTHARRAY]);
void selectionSort(const int LENGTHARRAY, int minIndex, int numbers[]);
int findMin(int array[], int first, int size);
void printArray(const int LENGTHARRAY, int numbers[]);

using namespace std;

int main()
{
    const int LENGTHARRAY = 10;
    int numbers[LENGTHARRAY] = {2,5,7,8,4,1,0,3,6,9};
    int minIndex = -1;
    
    printArray(LENGTHARRAY, numbers);
    bubbleSort(LENGTHARRAY, numbers);
    //selectionSort(LENGTHARRAY, minIndex, numbers);
    printArray(LENGTHARRAY, numbers);
    
    return 0;
}

void bubbleSort(const int LENGTHARRAY, int numbers[LENGTHARRAY])
{
    cout << "Bubble Sort\n" << endl;
    
    //Loop through whole array.
    for (int iteration = 0; iteration < LENGTHARRAY; iteration++) 
    {
        //check each array element against the next element.
        //Add in bool check to say was any swaped.
        for (int i = 0; i < LENGTHARRAY - iteration; i++) 
        {
            if(numbers[i] > numbers[i+1])
            {
                int nTemp = numbers[i];
                numbers[i] = numbers[i+1];
                numbers[i+1] = nTemp;
            }
        }
    }
}

void selectionSort(const int LENGTHARRAY, int minIndex, int numbers[])
{
    cout << "Selection Sort\n" << endl;

    for (int i = 0; i < LENGTHARRAY; i++) 
    {
        minIndex = findMin(numbers, i, LENGTHARRAY -1);
        
        int temp = numbers[i];
        numbers[i] = numbers[minIndex];
        numbers[minIndex] = temp;
    }
}

int findMin(int array[], int first, int size)
{
    int minIndex = first;

    for (int i = first; i <= size; i++) 
    {
        if (array[i] < array[minIndex]) 
        {
            minIndex = i;
        }
    }
    
    return minIndex;
}

void printArray(const int LENGTHARRAY, int numbers[])
{
    for (int i = 0; i < LENGTHARRAY; i++) 
    {
        cout << numbers[i] << endl;
    }
}

