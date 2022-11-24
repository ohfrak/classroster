#pragma once
#ifndef Student_hpp
#define Student_hpp
#include <iostream>
#include <iomanip>
#include "degree.h"

using std::string;
using std::cout;

class Student
{
public:
    const static int daysInCourseArraySize = 3;
private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    double daysInCourse[daysInCourseArraySize];
    DegreeProgram degreeProgram;
    
//declaring the methods and constructors
public:
    Student(); //empty constructor to set to default values
    //full constructor
    Student(string studentID,
            string firstName,
            string lastName,
            string emailAddress,
            int age,
            double daysInCourse[],
            DegreeProgram degreeProgram);
    
    //getters
    string getID();
    string getfirstName();
    string getlastName();
    string getemailAddress();
    int getage();
    const double* getdaysInCourse();
    DegreeProgram getdegreeProgram();
    
    
    //setters
    void setstudentID(string ID);
    void setfirstName(string firstName);
    void setlastName(string lastName);
    void setemailAddress(string emailAddress);
    void setage(int age);
    void setdaysInCourse(const double daysInCourse[]);
    void setdegreeProgram(DegreeProgram dp);
    
    static void printHeader();
    void print();
    
    ~Student(); //destructor
};

#endif /* Student_hpp */
