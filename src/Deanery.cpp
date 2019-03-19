#include "Header.h"
Deanery::Deanery(string fileStudent, string fileGroup)
{
	this->fileStudent = fileStudent;
	this->fileGroup = fileGroup;
}

void Deanery::CreateGroup() 
{
	string str;
	ifstream file(this->fileGroup);
	while (getline(file, str)) 
	{
		groups.push_back(new Group(str));
	}
	file.close();

	this->numGroup = groups.size();
	

}

void Deanery::CreateStudent()
{
	string str;
	int id = 1;
	ifstream file(fileStudent);
	while (getline(file, str)) 
	{
		id++;
		students.push_back(new Student(id, str));
	}
	file.close();

	this->numStudent = students.size();

	int k = this->numStudent / this->numGroup;
	for (int i = 0; i < this->numGroup; i++)
	{
		for (int j = i * k; j < (i + 1)*k; j++) 
		{
			this->students[j]->GroupEnter(this->groups[i]);
			this->groups[i]->addStudent(this->students[j]);
		}
	}
	int m = this->numStudent % this->numGroup;
	for (int i = 0; i < m; i++) 
	{
		this->students[k*this->numGroup + i]->GroupEnter(this->groups[i]);
		this->groups[i]->addStudent(students[k*this->numGroup + i]);
	}

}

void Deanery::addRandomMarks()
{
	int mark;
	for (int i = 0; i < this->numStudent; i++)
	{
		for (int j = 0; j <= 5; j++) 
		{
			//srand(time(0));
			mark = 1 + rand() % 5;
			this->students[i]->addMark(mark);
		}
	}
}

vector<pair<float, string>> Deanery::getStatisticStudents() 
{
	vector<pair<float, string>> vectorStudents;
	string str;
	float average;
	for (int i = 0; i < this->numStudent; i++)
	{
		str = this->students[i]->fio;
		average = this->students[i]->midMark();
		vectorStudents.push_back(pair<float, string>(average, str));
	}
	sort(vectorStudents.begin(), vectorStudents.end());
	return vectorStudents;
}

vector<pair<float, string>> Deanery::getStatisticGroup() 
{
	vector<pair<float, string>> vectorGroup;
	string str;
	float average;
	for (int i = 0; i < this->numGroup; i++)
	{
		str = this->groups[i]->title;
		average = this->groups[i]->averageGroup();
		vectorGroup.push_back(pair<float, string>(average, str));
	}
	sort(vectorGroup.begin(), vectorGroup.end());
	return vectorGroup;
}

Student * Deanery::searchFio(string fioSt)
{
	for (int i = 0; i < this->numStudent; i++) 
	{
		if (this->students[i]->fio == fioSt)
			return this->students[i];
	}
}

Group * Deanery::searchGroup(string titleGr)
{
	for (int i = 0; i < this->numGroup; i++) 
	{
		if (this->groups[i]->title == titleGr)
			return this->groups[i];
	}
}

void Deanery::changeGroup(string fio, string title) 
{
	Student * student = searchFio(fio);
	Group * group = searchGroup(title);
	Group * curGr = student->group;
	student->GroupEnter(group);
	group->addStudent(student);
	curGr->deductFio(fio);
}

void Deanery::Studentdeduction() 
{
	for (int i = 0; i < this->numGroup;i++)
	{
		for (int j = 0; j < this->numStudent; j++)
		{
			if (this->students[j]->midMark() < 2.5)
			{
				if (this->groups[i]->head != students[j])
				{
					this->students[j]->group->deductFio(this->students[j]->fio);
					students.erase(students.begin() + j);
					j--;
					this->numStudent--;
				}
				else
				{
					this->students[j]->group->deductFio(this->students[j]->fio);
					students.erase(students.begin() + j);
					j--;
					this->numStudent--;
					electionGroupHead();
				}
			}
		}
	}
}

void Deanery::electionGroupHead() {
	for (int i = 0; i < this->numGroup; i++) {
		this->groups[i]->electionHead();
	}
}

void Deanery::print() {
	{
		for (int i = 0; i < this->numGroup; i++)
		{
			for (int j = 0; j < this->groups[i]->num; j++)
			{
				cout << "ID: " << this->groups[i]->students[j]->id << " -- " << this->groups[i]->students[j]->fio << endl;
				cout << "Number of marks: " << this->groups[i]->students[j]->num << endl;
				cout << "Marks: ";
				for (int k = 0; k < this->groups[i]->students[j]->num; k++)
				{
					cout << this->groups[i]->students[j]->marks[k] << " ";
				}
				cout << "\n";
				cout << "Average Mark: " << this->groups[i]->students[j]->midMark() << endl;

				cout << "Group :" << this->groups[i]->students[j]->group->title << endl;
			}
		}
	}
}

void Deanery::printFile() 
{
	//ofstream file(this->fileStudent);
	ofstream file("output.txt");
	file.clear();
	for (int i = 0; i < this->numGroup; i++)
	{
		for (int j = 0; j < this->groups[i]->num; j++)
		{
			file << "ID: " << this->groups[i]->students[j]->id << " -- " << this->groups[i]->students[j]->fio << "\n";
			file << "Number of marks: " << this->groups[i]->students[j]->num << "\n";
			file << "Marks: ";
			for (int k = 0; k < this->groups[i]->students[j]->num; k++)
			{
				file << this->groups[i]->students[j]->marks[k] << " ";
			}
			file << "\n";
			file << "Average Mark: " << this->groups[i]->students[j]->midMark() << "\n";

			file << "Group :" << this->groups[i]->students[j]->group->title << "\n";
		}
	}
	file.close();
}