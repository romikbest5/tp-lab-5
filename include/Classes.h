#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <fstream> 
using namespace std;

class Group;

class Student {
	friend class Group;
	friend class Deanery;

private:
	int id;
	string fio;
	Group * group;
	int num;
	vector<int> marks;

public:
	Student(int, string);
	void addMark(int);
	float averageMark();
	string getFio();
	int getId();
	vector<int> getMarks();

	void enterGroup(Group * groupNum) {
		group = groupNum;
	};

	Group * getGroup() {
		return group;
	}	
};


class Group {
	friend class Deanery;

private:
	string title;
	vector<Student *> students;
	Student * head;
	int num;

public:
	Group(string);
	void addStudent(Student *);
	Student * electHead();			
	Student * searchFio(string);	
	Student * searchId(int);		
	float averageGroup();		
	void deductFio(string);		
	void deductId(int);			
};



class Deanery {
private:
	string fileSt, fileGr;
	vector<Student *> students;
	vector<Group *> groups;
	int numSt, numGr;

public:
	Deanery(string, string);
	void addGr();
	void addSt();
	void addRMarks();
	vector<pair<float, string>> getStatSt();
	vector<pair<float, string>> getStatGr();
	Student * searchFio(string);
	Group * searchGroup(string);
	void changeGroup(string, string);
	void deductSt();
	void electGrHead();
	void print();
	void printFile(string);
};
