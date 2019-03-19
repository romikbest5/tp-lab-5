#include "Student.h"

Student::Student(unsigned int id, string fio): id(id), fio(fio)
{
    group = nullptr;
}

void Student::EnrollToGroup(Group* _group)
{
    group = _group;
}

void Student::AddMark(unsigned int mark)
{
    marks.push_back(mark);
}

float Student::AverageMark()
{
    float sum(0);
    for (int i = 0; i < marks.size(); i++)
        sum += marks[i];
    return sum / marks.size();
}

string Student::getFio()
{
    return fio;
}

Group* Student::getGroup()
{
    return group;
}

unsigned Student::getId()
{
    return id;
}
