#ifndef GROUP_H
#define GROUP_H

#include <vector>
#include <string>
#include <iostream>
#include <ctime>
#include <set>
#include "Student.h"

const int NUM_ST = 30;                          //size for vector students
const int PASS_GRADE = 4;                       //lowest grade

class Deanery;

class Group {
	friend Deanery;
private:
	std::string title;                          //name of Group
	std::vector <Student*> students;
	int num = 0;                                //number of students in group
	Student* head;                              //link on the headman
public:
	Group(std::string title);
	void addStudent(Student* student);          //
	void getInfo();                             //head, num, average mark for whole Group,
	// info for every student

	void election();                            //election of headman

	//functions for searching students with rather param
	Student* search(std::string fio, int id);
	Student* search(int id);
	Student* search(std::string fio);

	int searchTwoness();                        //id of twonesses
	int average();                              //average mark in group

	//functions for expell students
	bool expell(int id);
	bool expell(int id, int mark);
	bool expell(std::string fio);


};

#endif