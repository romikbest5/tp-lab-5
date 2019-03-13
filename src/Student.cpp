#include "Header.h"
Student::Student(int _id, string _fio)
{
	id = _id;
	fio = _fio;
	num = 0;
	group = nullptr;

}

void Student::addMark(int mark)
{
	marks.push_back(mark);
	num++;
}
double Student::average()
{
	averageMark = 0;
	for (int i : marks) averageMark += i;
	averageMark = averageMark /num;
	return averageMark;
};
void Student::enrollment(Group& _group)
{
	_group.addStudent(this);
}
