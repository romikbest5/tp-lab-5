#include <utility>

#include "Student.h"

Student::Student (FULLNAME fullName, int id){

    this -> id = id;
    this -> fullName = std::move(fullName);
    GPA = 0;
    group = nullptr;

}

void Student::changeGroup (Group * group){

    this -> group = group;

}

void Student::addMark (MARK &mark){

    marks.add (mark);
    GPA = getGPA();

}

double Student::getGPA (){

    GPA = marks.getGPA();
    return GPA;

}