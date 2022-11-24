#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
#include "Roster.hpp"

using namespace std;

Roster::Roster() {};
//parsing method
void Roster::parse(string row)
{
    vector<string> result;
    stringstream input(row);
    while (input.good())
    {
        string token;
        getline(input, token, ',');
        result.push_back(token);
    }
    
    DegreeProgram dp = DegreeProgram::SOFTWARE;
        if (row.back() == 'Y') dp = DegreeProgram::SECURITY;
        if (row.back() == 'K') dp = DegreeProgram::NETWORK;
        add(result.at(0),
            result.at(1),
            result.at(2),
            result.at(3),
            stoi(result.at(4)),
            stoi(result.at(5)),
            stoi(result.at(6)),
            stoi(result.at(7)), dp);
}


void Roster::add(
                    string studentID,
                    string firstName,
                    string lastName,
                    string emailAddress,
                    int age,
                    double daysInCourse1,
                    double daysInCourse2,
                    double daysInCourse3,
                    DegreeProgram dp)
{
        double daysInCourseArray[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
        classRosterArray[++lastIndex] = new Student(studentID,
                                            firstName,
                                            lastName,
                                            emailAddress,
                                            age,
                                            daysInCourseArray,
                                            dp);
        cout << "Student added to class roster at row" << lastIndex+1 << endl;
}
    
//prints all students
void Roster::printAll()
{
    Student::printHeader();
    for (int i = 0; i <= Roster::lastIndex; i++) Roster::classRosterArray[i]->print();
}

//prints students by degree
void Roster::printByDegreeProgram(DegreeProgram dp)
{
    Student::printHeader();
    for (int i = 0; i <= Roster::lastIndex; i++)
        if (Roster::classRosterArray[i]->getdegreeProgram() == dp) classRosterArray[i]->print();
}

//print invalid emails
void Roster::printInvalidEmails()
{
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        string semailAddress = Roster::classRosterArray[i]->getemailAddress();
        if (semailAddress.find(' ') != string::npos || semailAddress.find('.') == string::npos)
            cout << semailAddress << " is invalid!" << endl;
    }
}

//finds the student ID and prints the average days per course
void Roster::printAverageDaysInCourse(string ID)
{
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        if (classRosterArray[i]->getID() == ID)
        {
            cout << ID << ":";
            cout << (classRosterArray[i]->getdaysInCourse()[0] +
                     classRosterArray[i]->getdaysInCourse()[1] +
                     classRosterArray[i]->getdaysInCourse()[2]) / 3.0 << endl;
        }
    }
}

//remove students by student ID
void Roster::removeStudentByID(string studentID)
{
    bool success = false;
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        if (classRosterArray[i]->getID() == studentID)
        {
            success = true;
            Student* temp = classRosterArray[i];
            classRosterArray[i] = classRosterArray[numStudents - 1];
            classRosterArray[numStudents - 1] = temp;
            Roster::lastIndex--;
        }
    }
    if (success)
    {
        cout << "Student " << studentID << " removed." << endl;
        printAll();
    }
    else cout << "Student " << studentID << " not found." << endl;
}

//destructor with announcement that it has been called
Roster::~Roster()
{
    for (int i = 0; i < numStudents; i++)
    {
        cout << "Destructor called for " << classRosterArray[i]->getID() << endl;
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}
