#pragma once
class Deanery {
public:
	vector<Student *>students;
	vector<Group *>groups;
	int num=0;//number of students
	Deanery();//create groups from data from file
	void addMark(int number); 
	void statistics();
	string replace(Student& st, Group& gr_to);
	void elimination();
	void save();
	void choiseHead();
	void consoleOutput();
};