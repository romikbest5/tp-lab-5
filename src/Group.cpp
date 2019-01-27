//
// Created by iamilyasedunov on 26.01.19.
//
#include "../include/Group.h"
#include "../src/Student.cpp"
#include "../include/Student.h"


const int NUM_ST = 30;

class Group {
private:
    std::string title;
    Student &students[NUM_ST];
    int num = NUM_ST;
    Student &head;

public:
    Group(Student &head) : head(head){
    }


};