#include "Header.h"
bool operator==(Student& st1, Student& st2)
{
	if ((st1.id == st2.id) && (st1.fio == st2.fio))return true;
	else return false;
}
Deanery::Deanery(){
	string groupName;
	string fio;
	ifstream in("../groups.txt"); 
	if (in.is_open()) 
	{	
		//title for groups
		for (int j = 0; j < 3; j++) 
		{
			getline(in, groupName);
			groups.push_back(new Group(groupName));
		}
		//fio of students
		for (int i = 0; i < 3; i++) 
		{
			for (int j= 0; j < 30; j++)
			{
				getline(in, fio);
				students.push_back(new Student(num + 1, fio));
				(students[num])->enrollment(*groups[i]);
				num++;
			}
		}
	}
	
	cout << "Deanery is created\n";
	in.close();
}
void Deanery::addMark(int number) 
{
	unsigned rand_value = 10;
	srand(rand_value);
	for (int i = 0; i < num; i++) 
	{
		for (int j = 0; j < number; j++)
			students[i]->addMark(1 + rand() % 10);
	}
}
void Deanery::statistics()
{
	for (Group* i : groups) 
	{
		cout << "Average mark of group " << i->title << " " << i->groupAverage() << endl;
		for (Student* j : (i->students))
		{
			cout << j->id << ' ' << j->fio << " average mark: " << j->average()<<endl;
		}
	}
}
void Deanery::replace(Student& st, Group& gr_to)
{
	st.group->elimination(&st);
	st.enrollment(gr_to);
}
void Deanery::elimination()
{
	for (int i = 0; i < num;i++) 
	{
		if ((students[i]->average()) <(double) 4)
		{
			students[i]->group->elimination(students[i]);
			cout << students[i]->id<<' '<<students[i]->fio <<" average Mark: "<< students[i]->average()<< " is expelled" << endl;
			students.erase(students.begin() + i);
			num--;
		}
	}
	return;
}
void Deanery::save()
{
	ofstream out;
	out.open("../data.txt"); 
	if (out.is_open())
	{
		out << "Information about students:" << endl;
		for (Student* i : students) 
		{
			i->average();
			out << i->group->title << ' ' << i->id <<' '<< i->fio << " average mark: " << i->average()<<endl;
		}
		out << "Information about groups:" << endl;
		for (Group* i : groups) out << i->title << " Head: " << i->head->fio << " average mark " << i->groupAverage() << endl;
	}

}
void Deanery::consoleOutput() 
{
	cout << "Information about students:" << endl;
	for (Student* i : students)
		cout << i->group->title << ' ' << i->id <<' '<< i->fio << " average mark: " << i->average() << endl;
	cout << "Information about groups:" << endl;
	for (Group* i : groups) cout << i->title << " Head: " <<i->head->fio<<" average mark: "<< i->groupAverage() << endl;
}
void Deanery::choiseHead() 
{
	unsigned rand_value = 30;
	srand(rand_value);
	for (int i = 0; i<3; i++)
		groups[i]->choiseHead(groups[i]->students[rand() % (groups[i]->num)]);

}