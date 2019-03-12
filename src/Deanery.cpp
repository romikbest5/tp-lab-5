#include <fstream>
#include <iostream>
#include <algorithm>
#include "Group.cpp"
#include "../include/Deanery.h"

void Deanery::loadStudentsFromFile (std::string & fileName){

    std::ifstream file;
    file.open(fileName);

    std::string s;
    while (getline(file, s))
        students.insert (new Student(FULLNAME (s), id++));

    file.close();

}

void Deanery::loadGroupFromFile (std::string & fileName, Group * group){

    std::ifstream file;
    file.open(fileName);

    std::string s;

    while (getline(file, s)){
        Student * student = new Student(FULLNAME (s), id++);
        student -> group = group;
        group -> addStudent (student);
        students.insert (student);
    }

    file.close();

}

void Deanery::setMark (Student * student, MARK mark){

    student->addMark (mark);

}

std::set<Student *, bool (*)(Student *, Student *)> * Deanery::getStatistics (Group * group){

    auto cmp = [](Student * a, Student * b) -> bool {return a->GPA > b -> GPA;};
    auto *req = new std::set<Student *, bool (*)(Student *, Student *)>(cmp);

    for (auto student : group->students)
        req -> insert(student);

    return req;

}

std::set<Student *, bool (*)(Student *, Student *)> * Deanery::getStatistics (){

    auto cmp = [](Student * a, Student * b) -> bool {return (a->GPA != b->GPA ? a->GPA > b -> GPA : a->id < b->id);};
    auto *req = new std::set<Student *, bool (*)(Student *, Student *)>(cmp);

    for (auto student : students)
        req -> insert(student);

    return req;

}

void Deanery::saveStatistics (std::string & fileName){
    saveStatistics (fileName, nullptr);
}

void Deanery::saveStatistics (std::string & fileName, Group * group){

    auto st = (group == nullptr ? getStatistics() : getStatistics(group));

    std::ofstream file;
    file.open(fileName);

    printStatistics (st, new std::ostream(file.rdbuf()));

    file.close();

}

void Deanery::printStatistics (std::set<Student *, bool (*)(Student *, Student *)> * st, std::ostream * cout){

    for (auto student : *st)
        (*cout) << student -> id << " " << student -> fullName.getString() << " "
            << student -> group -> title << " " << student -> getGPA() <<"\n";

}

void Deanery::replaceStudent (Student * student, Group * from, Group * to){

    if (from != nullptr)
        from -> excludeStudent (student);
    to -> addStudent (student);
    student -> group = to;

}

void Deanery::deductionStudent (Student * student){

    student -> group -> excludeStudent (student);
    students.erase(student);
    delete student;

}

void Deanery::deductionStudentByCriteria (bool (* criteria)(Student *)){

    for (auto student : students)
        if (criteria(student))
            deductionStudent(student);

}

Group * Deanery::createGroup (std::string title){

    groups.push_back(new Group(title));
    return groups.back();

}

void Deanery::saveData (std::string & fileName){

    std::ofstream file;
    file.open(fileName);

    printData (new std::ostream(file.rdbuf()));

    file.close();

}

void Deanery::printData (std::ostream * print){

    for (auto student : students)
        (*print) << student -> id << " " << student -> fullName.getString() << " " << student -> group -> title <<
             " " << student -> getGPA() <<"\n";

}

void Deanery::choiceHead (Group * group){

    group -> choiceHead();

}