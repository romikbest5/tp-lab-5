#include "group.h"

Group::Group(string title): title(title)
{
    head = nullptr;
}

bool Group::AddStudentToGroup(Student* _student)
{
    if (_student->getGroup() == nullptr)
    {
        _student->EnrollToGroup(this);
        students.push_back(_student);
        return true;
    }
    return false;
}

Student* Group::ChooseHead()
{
    if (students.size() > 0)
    {
        mt19937 new_head(time(NULL));
        head = students[new_head()%students.size()];
        return head;
    }
    return nullptr;

}

Student* Group::FindStudent(string _fio)
{
    for (Student* student:students)
    {
        if (student->getFio() == _fio)
            return student;
    }
    return nullptr;
}

Student* Group::FindStudent(int _id)
{
    for (Student* student:students)
    {
        if (student->getId() == _id)
            return student;
    }
    return nullptr;
}

float Group::AverageInGroup()
{
    float average(0);
    if (students.size() > 0)
    {
        for (Student* student:students)
        {
            average += student->AverageMark();
        }
        return (average/students.size());
    }
    else
        return 0;

}

bool Group::ExcludeStudent(Student* _student)
{
    if (students.size() > 0 && _student->getGroup() == this)
    {
        for (int i = 0; i < students.size(); i++)
        {
            if (_student->getFio() == students[i]->getFio())
            {
                students.erase(students.begin() + i);
                if (_student == head)
                {
                    ChooseHead();
                }
                return true;
            }
        }
    }
return false;
}

vector<Student*>* Group::getStudents()
{
    return &students;
}

string Group::getTitle()
{
    return title;
}

Student* Group::getHead()
{
    return head;
}