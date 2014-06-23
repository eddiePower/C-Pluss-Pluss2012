//
//  student.h
//  week5Lab
//
//  Created by Eddie Power on 27/03/12.
//  Copyright (c) 2012 Monash University Student.
//  All rights reserved.

#ifndef STUDENT_H_
  #define STUDENT_H_

#include <string>
using namespace std;

  class Student
  {
    private:
      string m_name;
      int m_assign1;
      int m_assign2;
      int m_exam;
    public:
      //constructors
      Student();
      Student(string name);
      Student(string name, int assignment1, int assignment2, int exam);
      //Destructor
      ~Student();
      //Getter's
      string getName();
      int getAssignment1();
      int getAssignment2();
      int getExam();
      //Setter's
      void setName(string name);
      void setAssignment1(int mark);
      void setAssignment2(int mark);
      void setExam(int mark);
      //class functions
      int finalMark();
  };
#endif



