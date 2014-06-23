//
//  Student.cpp
//  week5Lab
//
//  Created by Eddie Power on 27/03/12.
//  Copyright (c) 2012 Monash University Student.
//  All rights reserved.
//

#include "student.h"

//Constructor's
Student::Student()
{
    m_name = "Undefined";
    m_assign1 = 0;
    m_assign2 = 0;
    m_exam = 0;
}

Student::Student(string name)
{
    m_name = name;
    m_assign1 = 0;
    m_assign2 = 0;
    m_exam = 0;
}

Student::Student(string name, int assignment1, int assignment2, int exam)
{
    m_name = name;
    m_assign1 = assignment1;
    m_assign2 = assignment2;
    m_exam = exam;
}

//Deconstructor not used yet.
Student::~Student()
{
}

//Getter's
string Student::getName()
{
    return m_name;
}

int Student::getAssignment1()
{
    return m_assign1;
}

int Student::getAssignment2()
{
    return m_assign2;
}

int Student::getExam()
{
    return m_exam;
}

//Setter's
void Student::setName(string name)
{
    m_name = name;
}

void Student::setAssignment1(int mark)
{
    if (mark > 100) 
    {
        m_assign1 = 100;
    }
    else if(mark < 0)
    {
        m_assign1 = 0;
    }
    else
    {
        m_assign1 = mark;
    }
}

void Student::setAssignment2(int mark)
{
    if (mark > 100) 
    {
        m_assign2 = 100;
    }
    else if(mark < 0)
    {
        m_assign2 = 0;
    }
    else
    {
        m_assign2 = mark;
    }
}

void Student::setExam(int mark)
{
    if (mark > 100) 
    {
        m_exam = 100;
    }
    else if(mark < 0)
    {
        m_exam = 0;
    }
    else
    {
        m_exam = mark;
    }
}
//Class functions
int Student::finalMark()
{    
    return (m_assign1 + m_assign2 + m_exam) / 3;
}


