#include "Student.cpp"
#include <iostream>
#include "../include/Group.h"

Group::Group (std::string &title){

    this -> title = title;
    num = 0;
    head = nullptr;

}

void Group::addStudent (Student * student){

    students.insert (student);
    positionById[student->id] = student;
    positionByFullName[student->fullName.getString()].insert(student);
    num++;

}

Student * Group::choiceHead (){

    return head = *students.begin();

}

std::set<Student *> Group::getStudent (FULLNAME fullName){

    std::set<Student *> req;

    for (auto student : positionByFullName[fullName.getString()])
        req.insert(student);

    return req;

}

Student * Group::getStudent (int id){

    return positionById[id];

}

double Group::getGPA (){

    double GPA = 0;

    for (auto student : students)
        GPA += student -> getGPA();

    return GPA/students.size();

}

void Group::excludeStudent (Student * student){

    students.erase(student);
    num--;
    if (head == student)
        choiceHead ();

    positionById.erase(student->id);
    positionByFullName[student->fullName.getString()].erase(student);

}
