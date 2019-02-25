#include "Student.h"

Student::Student(unsigned int id, string& fio, unsigned num=0): id(id), fio(fio), num(num)
{
    group = nullptr;
}

void Student::EnrollToGroup(Group* _group){
    group = _group;
}

void Student::AddMark(unsigned int mark)
{
    marks.push_back(mark);
    num++;
}

float Student::AverageMark()
{
    float sum(0);
    for (int i = 0; i < num; i++)
        sum += marks[i];
    return sum / num;
}