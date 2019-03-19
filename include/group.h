#ifndef TASK1_GROUP_H
#define TASK1_GROUP_H
#include <iostream>
#include <random>
#include "student.h"
class Group
{
private:
    string title;
    vector<Student*> students;
    Student* head;
public:
    Group(string);
    bool AddStudentToGroup(Student*);
    Student* ChooseHead();
    Student* FindStudent(string);
    Student* FindStudent(int);
    float AverageInGroup();
    bool ExcludeStudent(Student*);
    vector<Student*>* getStudents();
    string getTitle();
    Student* getHead();
};
#endif //TASK1_GROUP_H
