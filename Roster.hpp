#pragma once
#ifndef Roster_hpp
#define Roster_hpp
#include <iostream>
#include <vector>
#include <sstream>
#include "Student.hpp"


class Roster
{
public:
    int lastIndex = -1;
    const static int numStudents = 5;
    Student* classRosterArray[numStudents] = {nullptr, nullptr, nullptr, nullptr, nullptr};

    
    Roster();
    Student** getclassRosterArray();
    
    //parse method
    void parse(string row);
    
    //adds a student to the roster
    void add(string sID,
             string sfirstName,
             string slastName,
             string semailAddress,
             int sAge,
             double daysInCourse1,
             double daysInCourse2,
             double daysInCourse3,
             DegreeProgram dp);
    
    void printAll(); //prints all students in the roster
    void printByDegreeProgram(DegreeProgram dp); //prints students with specified degree
    void printInvalidEmails(); //prints invalid emails
    //computes and prints a student's average days to complete a course
    void printAverageDaysInCourse(string ID);
    void removeStudentByID(string studentID); //removes a student by the studentID
    
    ~Roster();
};
#endif /* Roster_hpp */
