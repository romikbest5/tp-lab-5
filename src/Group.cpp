#include "Header.h"
Group::Group(string title)
{
	this->title = title;
	this->num = 0;
}

void Group::addStudent(Student * student) 
{
	students.push_back(student);
	this->num++;
}

Student * Group::electionHead() 
{
	if (num > 1) 
	{
		srand(time(0));
		int n = rand() % (num - 1) + 0;
		this->head = students[n];
		return this->head;
	}
	else 
	{
		this->head = students[0];
		return students[0];
	}
}

Student * Group::searchFio(string fio) 
{
	for (int i = 0; i < this->num; i++)
	{
		if (this->students[i]->fio == fio)
		{
			return this->students[i];
		}
		else
		{
			cout << "Not found" << endl;
			return 0;
		}
	}
}

Student * Group::searchId(int id) {
	for (int i = 0; i < this->num; i++) {
		if (this->students[i]->id == id)
		{
			return this->students[i];
		}
		else
		{
			cout << "Not found" << endl;
			return 0;
		}
	}
}

float Group::averageGroup()
{					
	float sum = 0;
	for (int i = 0; i < this->num; i++)
	{
		sum += this->students[i]->midMark();
	}
	if (this->num == 0)
		return sum;
	else
		return sum / this->num;
}

void Group::deductFio(string fio) {			
	for (int i = 0; i < this->num; i++) {
		if (this->students[i]->fio == fio) {
			if (this->students[i] == this->head) {
				students.erase(students.begin() + i);
				this->num--;
				electionHead();
			}
			else {
				students.erase(students.begin() + i);
				this->num--;
			}
		}
	}
}

void Group::deductId(int id)
{				
	for (int i = 0; i < this->num; i++)
	{
		if (this->students[i]->id == id)
		{
			if (this->students[i] == this->head)
			{
				students.erase(students.begin() + i);
				this->num--;
				electionHead();
			}
			else
			{
				students.erase(students.begin() + i);
				this->num--;
			}
		}
	}
}