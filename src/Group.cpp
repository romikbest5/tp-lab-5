#include "Group.h"

Group::Group(string& title, unsigned int num=0): title(title), num(num)
{
    head = nullptr;
}

bool Group::AddStudentToGroup(Student& _student)
{
    if (_student.group == nullptr)
    {
        _student.group = this;
        students.push_back(&_student);
        num++;
        cout << _student.fio << " was added into " << title << endl; //Just for checking
    }
    else
    {
        cout << _student.fio << " is already in " << title << endl;
    }
}

Student* Group::ChooseHead()
{
    if (num > 0)
    {
        mt19937 new_head(time(NULL));
        head = students[new_head()%num];
        cout << head->fio << " was chosen " << title << "'s head" << endl; //Just for checking
        return head;
    }
    else
        cout << "Nobody is in the group " << title << endl;
    return nullptr;

}

Student* Group::FindStudent(string _fio)
{
    for (int i = 0; i < num; i++)
    {
        if (students[i]->fio == _fio)
            return students[i];
    }
    std::cout << "There is no " << _fio << " in " << this->title << " !" << std::endl; //Just for checking
    return nullptr;
}

float Group::AverageInGroup()
{
    float average(0);
    if (num > 0)
    {
        for (int i = 0; i < num; i++)
        {
            average += students[i]->AverageMark();
        }
        return (average/num);
    }
    else
        return 0    ;

}

bool Group::ExcludeStudent(Student& _student)
{
    if (_student.group == this)
    {
        for (int i = 0; i < num; i++)
        {
            if (_student.fio == students[i]->fio)
            {
                cout << _student.fio << " was excluded" << endl;
                students.erase(students.begin() + i);
                num--;
                if (&_student == head)
                {
                    ChooseHead();
                }
                return true;
            }
        }
    }
    else
    {
        cout << _student.fio << " is not in this group" << endl;
        return false;
    }

}