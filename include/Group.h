#pragma once
class Group {
private:
	string title;//group's title
	vector<Student*> students;
	int num;// -number of students in group
	Student* head;
public:
	Group(string _title);
	void addStudent(Student* student);
	void choiseHead(Student* student);
	Student* search(int _id, string _fio);
	double groupAverage();
	void elimination(Student* student);
	friend Deanery;
};