#include "Header.h"
int main() {
	//tests for class Student
	Student A(1, "Polina Smolnikova");
	A.addMark(5);
	A.addMark(10);
	A.addMark(8);
	cout << A.id << ' ' << A.fio << ' ' << A.average() << endl;
	//tests for class Group
	Group P("PMI");
	A.enrollment(P);
	cout<<"Group average="<<P.groupAverage()<<endl;
	cout << "Search\n";
	cout<<P.search(1, "Polina Smolnikova")->fio<<endl;
	P.choiseHead(&A);
	P.elimination(&A);
	//tests for class Deanery
	ifstream in("../data/groups.txt");
	Deanery IM(in);
	IM.addMark(10);
	IM.elimination();
	IM.choiseHead();
	IM.replace(*IM.students[0], *IM.groups[2]);
	ofstream out("../data/data_about_groups.txt");
	IM.save(out);
	IM.consoleOutput();
	system("pause");
	return 0;
}