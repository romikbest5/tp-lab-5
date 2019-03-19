#include "Deanery.h"

#include <fstream>

#define LIMIT 5.5


Deanery::Deanery()
{
    id = 0;
}

void Deanery::ReadStudentsFromFile(const std::string& filename)
{
    std::ifstream file;
    file.open(filename);

    std::string s;
    while (getline(file, s))
        students.push_back(new Student(id++, s));

    file.close();
}

void Deanery::ReadGroupsFromFile(const std::string& filename)
{
    std::ifstream file;
    file.open(filename);

    std::string s;
    while (getline(file, s))
        groups.push_back(new Group(s)); // title

    mt19937 randgroup(NULL);
    for (Student* student:students)
    {
        groups[randgroup() % groups.size()]->AddStudentToGroup(student);
    }
    file.close();

}


void Deanery::AddRandomMarks()
{
    mt19937 randmark(NULL);
    for (Student* student:students)
    {
        for (int i(0); i < 8; i++)
        student->AddMark(randmark() % 10 + 1);
    }
}

void Deanery::ChooseHeads()
{
    for (Group* group:groups)
        group->ChooseHead();
}

void Deanery::ExcludeStudent()
{
    for (size_t i(0); i < students.size(); i++)
    {
        if (students[i]->AverageMark() < LIMIT)
        {
            students[i]->getGroup()->ExcludeStudent(students[i]);
            Student *student = students[i];
            students.erase(students.begin() + i);
            delete student;
        }
    }
}

void Deanery::GetStatistic(std::ostream* stream)
{
    for (Group* group:groups)
    {
        *stream << "\nGROUP TITLE: " << group->getTitle()
                << "\nHEAD: " << group->getHead()->getFio() << "\n\n";
        for (Student* student:*group->getStudents())
            *stream << "ID: " << student->getId() << " FIO: " << student->getFio()
                    << " Average Mark: " << student->AverageMark() << " Group: "
                    << student->getGroup()->getTitle() << "\n";
        *stream << "AVERAGE IN GROUP: " << group->AverageInGroup() << "\n";
    }
    *stream << "AMOUNT OF STUDENTS: " << students.size() << "\n\n";
}

bool Deanery::TransferStudentToGroup(int id, string grouptitle)
{
    Group* oldgroup = nullptr;
    for (Student* student:students)
    {
        if (student->getId() == id)
        {
            oldgroup = student->getGroup();
            oldgroup->ExcludeStudent(student);
            student->EnrollToGroup(nullptr);
            for (Group* group:groups)
            {
                if (group->getTitle() == grouptitle)
                {
                    group->AddStudentToGroup(student);
                    return true;
                }
            }
            oldgroup->AddStudentToGroup(student); // If the mistake in grouptitle was made
            throw 1;

        }
    }

    return false;
}

void Deanery::SaveData()
{
    std::ofstream fout(("../data/out.txt"));
    GetStatistic(new ostream(fout.rdbuf()));

    fout.close();
}
