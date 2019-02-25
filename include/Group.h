#ifndef TASK1_GROUP_H
#define TASK1_GROUP_H
#include <vector>
#include<string>
#include <iostream>
#include <random>
#include "Student.h"
class Group
{
private:
    string title;
    vector<Student*> students;
    unsigned int num;
    Student* head;
public:
    Group(string&, unsigned int);
    bool AddStudentToGroup(Student&);
    Student* ChooseHead();
    Student* FindStudent(string);
    float AverageInGroup();
    bool ExcludeStudent(Student&);
};
#endif //TASK1_GROUP_H
