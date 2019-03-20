//
// Created by Александр Славутин on 2019-03-19.
//
#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "student.h"

using namespace std;

class Group{
private:
    string title;
    vector <Student *> students_list;
    int num;
    Student *head;
public:
    Group(string title);
    void add_student(Student*);
    Student* choose_head();
    Student* student_search(int id);
    float get_average_group_mark();
    void student_elimination(int id);
    void make_new_group(string title);
    friend Student;
    friend Deanery;

};
