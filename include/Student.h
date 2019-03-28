#pragma once
#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <fstream>
using namespace std;

class Student
{
	friend class Group; 
	friend class Deanery;
private:
	unsigned int id;
	string fio;
	Group * group;
	vector<int> marks;
	int num;
public:
	Student(int ,string );
	void AddMarks(int mark);
	void MoveToGroup(Group * group);
	float avg();

};





class Group
{
	friend class Deanery;
private:
	string title;
	vector<Student*> students;
	int num;
	Student *head;
public:
	Group(string);
	void addStudent(Student * student);
	void ChoiceHead();
	float avgMark();
	Student * searchById(int id);
	Student * searchByFio(string fio);
	void kick(int id);
};



class Deanery
{
private: 
	vector<Student*> students;
	vector<Group*> groups;
	int StudentsNumber;
	int GroupNumber;



public:
	void ReadStudents(string filename);
	void ReadGroups(string filename);
	void SetMarks(int NumberOfMarks);
	void SetGroup(string fio, string group);
	void kick();
	void ChoiceHead();
	void Statistic(string filename);
	void SaveData(string filename);
	void PrintData();

};