#ifndef TP_LAB_5_STUDENT_H
#define TP_LAB_5_STUDENT_H
#include <vector>
#include <string>

class Group;

using namespace std;

class Student
{
private:
    unsigned int id;
    string fio;
    Group* group;
    vector <unsigned int> marks;
public:
    Student(unsigned int, string);
    void EnrollToGroup(Group*);
    void AddMark(unsigned int);
    float AverageMark();
    string getFio();
    Group* getGroup();
    unsigned getId();
};
#endif //TP_LAB_5_STUDENT_H
