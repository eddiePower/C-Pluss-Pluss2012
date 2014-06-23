//
//  main.cpp
//  week5Lab
//
//  Created by Eddie Power on 27/03/12.
//  Copyright (c) 2012 Monash University Student.
//  All rights reserved.
//

#include <iostream>
#include <vector>
#include "student.h"

int main ()
{
    Student stu1;
    Student stu2("John");
    Student stu3("Eddie", 85,75,89);
    
    vector<Student> students;
    
    students.push_back(stu1);
    students.push_back(stu2);
    students.push_back(stu3);
    
    cout << "Week 5 Lab work." << endl;
    
    for (int i = 0; i < students.size(); i++) 
    {
        cout << "\nStudent " << i + 1 << endl;
        cout << "Student name: " << students[i].getName() << endl;
        cout << "Assignment Mark 1: " << students[i].getAssignment1() << endl;
        cout << "Assignment Mark 2: " << students[i].getAssignment2() << endl; 
        cout << "Exam Mark: " << students[i].getExam() << endl;
        cout << "Total: " << students[i].finalMark() << endl;
    }
    
    return 0;
}

