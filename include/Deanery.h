#pragma once
class Deanery {
public:
	vector<Student *>students;
	vector<Group *>groups;
	int num=0;//number of students
	Deanery(ifstream& in);//create groups from data from file
	void addMark(int number); 
	void statistics();
	string replace(Student& st, Group& gr_to);
	void elimination();
	void save(ofstream& out);
	void choiseHead();
	void consoleOutput();
};