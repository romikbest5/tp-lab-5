#include "Student.h"






Student::Student(int id, string fio)
{
	this->id = id;
	this->fio = fio;
}

void Student::AddMarks(int mark)
{
	marks.push_back(mark);
	num = marks.size();
}

void Student::MoveToGroup(Group * group)
{
	this->group = group;
}

float Student::avg()
{
	int MarkSum = 0;
	for (int i = 0; i < this->num; i++)
		MarkSum += this->marks[i];
	return MarkSum / this->num;
}

Group::Group(string title)
{
	this->title = title;
}

void Group::addStudent(Student * student)
{
	students.push_back(student);
	num = students.size();
}

void Group::ChoiceHead()
{
	head = this->students[rand() % (num - 1)];
}

float Group::avgMark()
{
	int sum=0;
	for (int i = 0; i < this->num; i++)
	{
		sum += this->students[i]->avg();
	}
	return sum / this->num;
}

Student * Group::searchById(int id)
{
	for (int i = 0; i < num; i++) 
		if (students[i]->id == id) 
			return students[i];
	return NULL;
		
}

Student * Group::searchByFio(string fio)
{
	for (int i = 0; i < num; i++)
		if (students[i]->fio == fio)
			return students[i];
	return NULL;
}

void Group::kick(int id)
{
	for (int i = 0; i < num; i++) {
		if (students[i]->id == id)
		{
			if (this->students[i] == head)
			{
				this->students.erase(students.begin() + i);
				num--;
				ChoiceHead();
			}
			else
			{
				this->students.erase(students.begin() + i);
				num--;
			}
		}
	}
}



void Deanery::ReadStudents(string filename)
{
	ifstream file(filename);
	string fio;
	int id = 1;
	while (getline(file, fio)) 
	{
		this->students.push_back(new Student(id, fio));
		id++;
	}
	file.close();
	this->StudentsNumber = this->students.size();
}

void Deanery::ReadGroups(string filename)
{
	ifstream file(filename);
	string name;
	while (getline(file, name)) {
		this->groups.push_back(new Group(name));
	}
	file.close();
	this->GroupNumber = this->groups.size();
	for (int i = 0; i < this->StudentsNumber; i++)
	{
		this->students[i]->MoveToGroup(this->groups[i % this->GroupNumber]);
		this->groups[i % this->GroupNumber]->addStudent(this->students[i]);
	}
}

void Deanery::SetMarks(int NumberOfMarks)
{
	for (int i = 0; i < NumberOfMarks; i++)
	{
		for (int j = 0; j < this->StudentsNumber; j++)
		{
			this->students[j]->AddMarks(rand() % 11);
		}
	}
}

void Deanery::SetGroup(string fio, string group)
{
	for (int i = 0; i < this->StudentsNumber; i++)
	{
		if (this->students[i]->fio == fio)
		{
			for (int j = 0; j < GroupNumber; j++)
			{
				if (this->groups[j]->title == group)
				{
					Group * LastGroup = students[i]->group;
					students[i]->MoveToGroup(groups[j]);
					groups[j]->addStudent(students[i]);
					LastGroup->kick(students[i]->id);
				}
			}
		}
	}
}

void Deanery::kick()
{
	for (int i = 0; i < this->StudentsNumber; i++)
	{
		if (this->students[i]->avg() < 4)
		{
			this->students[i]->group->kick(students[i]->id);
			this->students.erase(students.begin() + i);
			this->StudentsNumber--;
			i--;
		}
	}
}

void Deanery::ChoiceHead()
{
	for (int i = 0; i < GroupNumber; i++)
	{
		this->groups[i]->ChoiceHead();
	}
}

void Deanery::Statistic(string filename)
{
	ofstream file(filename);

	if (file.is_open()) 
	{
		for (int i = 0; i < this->StudentsNumber; i++)
		{
			file << this->students[i]->fio << "   avg mark: " << this->students[i]->avg() << endl;
		}
		for (int i = 0; i < this -> GroupNumber; i++)
		{
			file << "Group  " << this->groups[i]->title << "   avg mark: " << this->groups[i]->avgMark() << endl;
		}
	}
	file.close();
}

void Deanery::SaveData(string filename)
{
	ofstream file(filename);
	if (file.is_open())
	{
		for (int i = 0; i < this->GroupNumber; i++)
		{
			file << "GROUP " << this->groups[i]->title << endl;
			for (int j = 0; j < this->groups[i]->num; j++)
			{
				file << this->groups[i]->students[j]->fio << "  ";
				for (int h = 0; h < this->groups[i]->students[j]->num; h++)
				{
					file << this->groups[i]->students[j]->marks[h] << " ";
				}
				file << "  avg" << this->groups[i]->students[j]->avg()<<endl;
			}
			file << "Elder of group is " << this->groups[i]->head->fio<<endl<<"AVG marks is "<<this->groups[i]->avgMark()<<endl<<endl;
		}
	}
}

void Deanery::PrintData()
{

			for (int i = 0; i < this->GroupNumber; i++)
			{
				cout << "GROUP " << this->groups[i]->title << endl;
				for (int j = 0; j < this->groups[i]->num; j++)
				{
					cout << this->groups[i]->students[j]->fio << "  ";
					for (int h = 0; h < this->groups[i]->students[j]->num; h++)
					{
						cout << this->groups[i]->students[j]->marks[h] << " ";
					}
					cout << "  avg" << this->groups[i]->students[j]->avg() << endl;
				}
				cout << "Elder of group is " << this->groups[i]->head->fio << endl << "AVG marks is " << this->groups[i]->avgMark() << endl << endl;
			}
}
