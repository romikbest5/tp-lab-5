#pragma once

#include<iostream>
using namespace std;
#include<string>
#include<vector>

class Group;

class Student {
	friend class Group; //to access a group of student names/id; for search 
	friend class Deanery;
private:
	int id;
	string fio;
	Group * group;
	vector<int> marks;
	int num;

public:
	Student(int, string );
	void enterGroup(Group * ); //Group * name зачисление в группу
	void addMark(int);
	float averageMark();
};

class Group {
	friend class Deanery;
private:
	string title;
	vector<Student*> students;
	int num;
	Student *head;
public:
	Group(string);
	Student * electHead();
	void addStudent(Student*);
	Student * searchSfio(string);
	Student * searchSid(int);
	float averageGroup();
	void exceptionStudent(string);
};

class Deanery {
private:
	vector<Student*> students;
	vector<Group*> groups;

	string fileStudents; //name of file about students and groups
	string fileGroups;

	int numSt;
	int numGr; //number of students and groups

	vector<pair<float, string>> StStat; //for range students
	vector<pair<float, string>> GrStat; //for range groups

public:
	Deanery(string,string);
	void CreateStudents();
	void CreateGroups();
	void addMarks();
	void getStatistics(string);
	void changeGroup(string,string);
	void exceptionStudent();
	void update(string); //update info in file
	void electGhead();
	void printinfo();
};