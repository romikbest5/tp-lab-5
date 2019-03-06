#ifndef STUDENT_H
#define STUDENT_H

#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <fstream>

class Group;
class Deanery;

const int NUM_MARKS = 10;           //size for vector marks

class Student {
	//friendly classes
	friend Deanery;
	friend Group;
private:
	int id;
	std::string fio;                //first & second name
	Group* group;                   //link on Group
	std::vector <int> marks;
	int num = 0;                    //number of marks

public:
	Student(int id, std::string fio);
	Student(int id);
	Student(std::string fio);
	void readMarks();               //marks from file in std::vector <int> marks;
	void readFio();                 //name & surname in std::string fio;
	void readId();
	void getInfo();                 //id, fio, average mark
	void inGroup(Group *group);     //admission to the group
	int average();                  //calculation average of marks
};

#endif