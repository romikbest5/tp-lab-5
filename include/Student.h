#pragma once
class Group;
class Deanery;
class Student {

private:

	int num;// -number of marks
	vector<int> marks;// -vector of marks
	double averageMark; 
public:
	string fio;
	Group* group;
	int id; 
	Student(int _id, string _fio);
	string enrollment(Group& _group); 
	void addMark(int mark);
	double average();
	friend Group;
	friend Deanery;
}; 
