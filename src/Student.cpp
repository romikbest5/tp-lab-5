//
// Created by iamilyasedunov on 26.01.19.
//

#include "../include/Student.h"
#include "Group.cpp"

class Student {
private:
    int id;
    std::string fio;
    //Group &group;
    int marks[NUM_MARKS];
    int num = NUM_MARKS;

public:
    Student(int id, std::string fio){
        this->id = id;
        this->fio = fio;
    }

};
