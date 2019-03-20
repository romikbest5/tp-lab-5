#ifndef TASK1_DEANERY_H
#define TASK1_DEANERY_H
#include "group.h"
using namespace std;

class Deanery
{
private:
    unsigned id;
    vector<Student*> students;
    vector<Group*> groups;
public:
    Deanery();
    void ReadStudentsFromFile(const std::string&);
    void ReadGroupsFromFile(const std::string&);
    void AddRandomMarks();
    void GetStatistic(ostream*);
    bool TransferStudentToGroup(int, string);
    void ExcludeStudent();
    void SaveData();
    void ChooseHeads();
};
#endif //TASK1_DEANERY_H
