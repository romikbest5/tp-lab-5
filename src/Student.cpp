#include "Header.h"

Student::Student(int id, string fio)
{
	this->id = id;
	this->fio = fio;
	this->num = 0;
}

void Student::addMark(unsigned int mark)
{
	marks.push_back(mark);
	this->num++;
}

float Student::midMark() 
{
	float sum = 0;
	for (int i = 0; i < this->num; i++)
	{
		sum += this->marks[i];
	}
	return sum / this->num;
}
void Student::GroupEnter(Group *group)
{
	this->group = group;
}

string Student::getFio() 
{
	return this->fio;
}

int Student::getid() 
{
	return this->id;
}

vector<int> Student::getMarks() 
{
	return this->marks;
}
Group * Student::getGroup() 
{
	return this->group;
}