#include <iostream>
#include "Student.hpp"

using std::string;
using std::cout;

Student::Student() //empty constructor to set all fields to default values
{
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = 0;
    for (int i = 0; i < daysInCourseArraySize; i++) this->daysInCourse[i] = 0;
    this->degreeProgram = DegreeProgram::SOFTWARE;
}

Student::Student(string studentID,
                 string firstName,
                 string lastName,
                 string emailAddress,
                 int age,
                 double daysInCourse[],
                 DegreeProgram degreeProgram)
{
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    for (int i = 0; i < daysInCourseArraySize; i++) this->daysInCourse[i] = daysInCourse[i];
    this->degreeProgram = degreeProgram;
}
Student::~Student() {} //destructor


//getters
string Student::getID()
{return this->studentID;}

string Student::getfirstName()
{return this->firstName;}

string Student::getlastName()
{return this->lastName;}

string Student::getemailAddress()
{return this->emailAddress;}

int Student::getage()
{return this->age;}

const double* Student::getdaysInCourse()
{return this->daysInCourse;}

DegreeProgram Student::getdegreeProgram()
{return this->degreeProgram;}


//setters
void Student::setstudentID(string ID) {this->studentID = ID;}
void Student::setfirstName(string firstName) {this->firstName = firstName;}
void Student::setlastName(string lastName) {this->lastName = lastName;}
void Student::setemailAddress(string emailAddress) {this->emailAddress = emailAddress;}
void Student::setage(int age) {this->age = age;}
//uses a loop to set the days per course individually
void Student::setdaysInCourse(const double daysPerCourse[])
{
    for (int i = 0; i < daysInCourseArraySize; i++) this->daysInCourse[i] = daysPerCourse[i];
}

//sets degreeProgram to DegreeProgram, not a string
void Student::setdegreeProgram(DegreeProgram degreeProgram) {this->degreeProgram = degreeProgram;}


void Student::printHeader()
{
    cout << "ID\t";
    cout << "First Name\t";
    cout << "Last Name\t";
    cout << "Email\t";
    cout << "Age\t";
    cout << "Days In Course1\t";
    cout << "Days In Course2\t";
    cout << "Days In Course3\t";
    cout << "Degree\t";
    cout << std::endl;
}


void Student::print()
{
    cout << this->studentID << '\t';
    cout << this-> firstName<< '\t';
    cout << this-> lastName << '\t';
    cout << this->emailAddress << '\t';
    cout << this->age << '\t';
    cout << this->daysInCourse[0] << '\t';
    cout << this->daysInCourse[1] << '\t';
    cout << this->daysInCourse[2] << '\t';
    cout << degreeProgramStrings[(int)this->degreeProgram];
    cout << std::endl;
}
