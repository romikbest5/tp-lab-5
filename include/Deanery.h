#ifndef TASK1_DEANERY_H
#define TASK1_DEANERY_H
#include <vector>
#include<string>
#include "Student.h"
#include "Group.h"
using namespace std;

class Deanery
{
private:
    vector<Student*> students;
    vector<Group*> groups;
public:
    Deanery()
    {
        vector<Student*> students;
        vector<Group*> groups;
    }
    void ReadStudentsFromFile();
    void ReadGroupsFromFile();
    void AddRandomMarks();
    void GetStatistic();
    void TransferStudentToGroup(int, string);
    void ExcludeStudent();
    void SaveData();
    void ChooseHeads();
    void COutData();

};
#endif //TASK1_DEANERY_H
