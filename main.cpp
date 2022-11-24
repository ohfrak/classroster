#include <iostream>
#include <iomanip>
#include "Roster.hpp"


int main()
{
    cout << "Course: C867 - Scripting And Programming - Applications" << std::endl;
    cout << "Programming Language: C++" << std::endl;
    cout << "Name: Tyler Cossairt" << std::endl;
    cout << "Student ID: 001290054" << std::endl;
    
    const int numStudents = 5;

    const string studentData[] =
    {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Tyler,Cossairt,tcossai@wgu.edu,32,20,25,30,SOFTWARE"
    };

    Roster classRoster;

    for (int i = 0; i < numStudents; i++) {
        classRoster.parse(studentData[i]);
    }
    
    cout << "Displaying all students." << std::endl;
    classRoster.printAll();
    
    for (int i = 0; i < 3; i++)
    {
        cout << "Displaying degree type:" << degreeProgramStrings[i] << std::endl;
        classRoster.printByDegreeProgram((DegreeProgram)i);
    }
    
    cout << "Displaying invalid emails:" << std::endl;
    classRoster.printInvalidEmails();
    
    cout << "Displaying the average days per course:" << std::endl;
    for (int i = 0; i < numStudents; i++) {
            classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getID());
        }
    
    cout << "Removing student A3" << std::endl;
    classRoster.removeStudentByID("A3");
    
    cout << "Removing student A3" << std::endl;
    classRoster.removeStudentByID("A3");
    
    cout << "Program finished. Destructors will be called upon exit." << std::endl;
    
    return 0;
}
