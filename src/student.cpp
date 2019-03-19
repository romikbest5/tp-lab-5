//
// Created by Александр Славутин on 2019-03-18.
//
#include "student.h"


Student::Student(int id, string fio)
{
    this->id = id;
    this->fio = fio;
    num = 0;
}

void Student::make_new_student(int id, string fio)
{
    this->fio = fio;
    this->id = id;
}
void Student::student_enrollment(Group *group)
{
    this->group = group;

}

void Student::add_mark(unsigned int mark)
{
    marks.push_back(mark);
    num++;
}

float Student::get_average_mark()
{
    float sum_of_marks = 0;
    for(auto& n : marks)
        sum_of_marks += n;
    return sum_of_marks / num;
}
