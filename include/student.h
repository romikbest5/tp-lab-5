//
// Created by Александр Славутин on 2019-03-18.
//

#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Group;
class Deanery;

class Student{
private:
    int id;
    string fio;
    vector <unsigned int> marks;
    int num;
    Group* group;

public:
    Student(int id,string fio);
    void make_new_student(int ud, string fio);
    void student_enrollment(Group* group);
    float get_average_mark();
    void add_mark(unsigned int  mark);
    friend Group;
    friend Deanery;

};