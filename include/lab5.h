#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>



using namespace std;
class Group;
class Deanery;
class Student
{
	friend Group;
	friend Deanery;
private:

	int id;
	std::string fio;
	std::vector <int> marks;
	Group *group;

public:
	Student(int _id, std::string _fio, int n_marks);

	void enroll_to(Group *_group);

	void add_mark(int  _mark);

	double calc_progress();
	
};

class Group
{
	friend Deanery;
private:
	std::string title;
	std::vector<Student*> students;
	Student *head;
public:
	Group(std::string _title);
	
	void enroll(Student &_student);
	
	Student * search(string _fio);
	
	Student * election();
	
	bool removal(Student *_student);
	
	double calc_avrg();
	
};

class Deanery
{
private:
	vector<Student*> students;
	vector<Group*> groups;
public:
	
	Deanery(string _file);
	
	Group * searchGroup(string title);

	bool transfer(string fio, Group *group);
	
	void checkProgress(double limit);

	void reelection();
	
	void updateData(string _file);
	
	void printStatics();
	
};

 



