#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <fstream> 
#include "../include/Classes.h"
using namespace std;

//////////////// class Student //////////////

Student::Student(int idNum, string fioName) {
	id = idNum;
	fio = fioName;
	num = 0;
}

void Student::addMark(int mark) {
	marks.push_back(mark);
	num = marks.size();
}

float Student::averageMark() {
	int sum = 0;
	float aver;
	for (int i = 0; i < num; i++) {
		sum += marks[i];
	}
	aver = float(sum) / float(num);
	return round(aver * 10) / 10;
}

string Student::getFio() {
	return fio;
}

int Student::getId() {
	return id;
}

vector<int> Student::getMarks() {
	return marks;
}

////////////////// class Group ////////////////

Group::Group(string titleGroup) {
	title = titleGroup;
}

void Group::addStudent(Student * student) {
	students.push_back(student);
	num = students.size();
}

Student * Group::electHead() {
	if (num > 1) {
		srand(time(0));
		int n = rand() % (num - 1) + 0;
		head = students[n];
		return head;
	}
	else {
		head = students[0];
		return students[0];
	}
}

Student * Group::searchFio(string fioSt) {
	for (int i = 0; i < num; i++) {
		if (students[i]->fio == fioSt)
			return students[i];
	}
}

Student * Group::searchId(int idSt) {
	for (int i = 0; i < num; i++) {
		if (students[i]->id == idSt)
			return students[i];
	}
}

float Group::averageGroup() {					//ñðåäíåå ïî ãðóïïå 
	float sum = 0, aver;
	for (int i = 0; i < num; i++) {
		sum += students[i]->averageMark();
	}
	aver = sum / float(num);
	return round(aver * 10) / 10;
}

void Group::deductFio(string fioSt) {			//îò÷èñëåíèå ñòóäåíòà ïî ôèî
	for (int i = 0; i < num; i++) {
		if (students[i]->fio == fioSt) {
			if (students[i] == head) {
				students.erase(students.begin() + i);
				num--;
				electHead();
				break;
			}
			else {
				students.erase(students.begin() + i);
				num--;
				break;
			}
		}
	}
}

void Group::deductId(int idSt) {				//îò÷èñëåíèå ïî id
	for (int i = 0; i < num; i++) {
		if (students[i]->id == idSt) {
			if (students[i] == head) {
				students.erase(students.begin() + i);
				num--;
				electHead();
				break;
			}
			else {
				students.erase(students.begin() + i);
				num--;
				break;
			}
		}
	}
}

///////////////////// class Deanery /////////////////

Deanery::Deanery(string filenameSt, string filenameGr) {
	fileSt = filenameSt;
	fileGr = filenameGr;
}

void Deanery::addGr() {
	string s;
	ifstream file(fileGr);
	while (getline(file, s)) {
		groups.push_back(new Group(s));
	}
	file.close();

	numGr = groups.size();
}

void Deanery::addSt() {
	string s;
	int id = 1000;
	ifstream file(fileSt);
	while (getline(file, s)) {
		id++;
		students.push_back(new Student(id, s));
	}
	file.close();

	numSt = students.size();

	int k = numSt / numGr;
	for (int i = 0; i < numGr; i++) {
		for (int j = i * k; j < (i + 1)*k; j++) {
			students[j]->enterGroup(groups[i]);
			groups[i]->addStudent(students[j]);
		}
	}
	int m = numSt % numGr;
	for (int i = 0; i < m; i++) {
		students[k*numGr + i]->enterGroup(groups[i]);
		groups[i]->addStudent(students[k*numGr + i]);
	}

}

void Deanery::addRMarks() {
	int m;
	for (int i = 0; i < numSt; i++) {
		for (int j = 0; j < 10; j++) {
			//srand(time(0));
			m = 1 + rand() % 5;
			students[i]->addMark(m);
		}
	}
}

vector<pair<float, string>> Deanery::getStatSt() {
	vector<pair<float, string>> vecSt;
	string s;
	float av;
	for (int i = 0; i < numSt; i++) {
		s = students[i]->fio;
		av = students[i]->averageMark();
		vecSt.push_back(pair<float, string>(av, s));
	}
	sort(vecSt.begin(), vecSt.end());
	return vecSt;
}

vector<pair<float, string>> Deanery::getStatGr() {
	vector<pair<float, string>> vecGr;
	string s;
	float av;
	for (int i = 0; i < numGr; i++) {
		s = groups[i]->title;
		av = groups[i]->averageGroup();
		vecGr.push_back(pair<float, string>(av, s));
	}
	sort(vecGr.begin(), vecGr.end());
	return vecGr;
}

Student * Deanery::searchFio(string fioSt) {
	for (int i = 0; i < numSt; i++) {
		if (students[i]->fio == fioSt)
			return students[i];
	}
}

Group * Deanery::searchGroup(string titleGr) {
	for (int i = 0; i < numGr; i++) {
		if (groups[i]->title == titleGr)
			return groups[i];
	}
}

void Deanery::changeGroup(string fio, string title) {
	Student * st = searchFio(fio);
	Group * gr = searchGroup(title);
	Group * curGr = st->group;
	st->enterGroup(gr);
	gr->addStudent(st);
	curGr->deductFio(fio);
}

void Deanery::deductSt() {
	for (int i = 0; i < numSt; i++) {
		if (students[i]->averageMark() < 2.5) {
			students[i]->group->deductFio(students[i]->fio);
			students.erase(students.begin() + i);
			i--;
			numSt--;
		}
	}
}

void Deanery::electGrHead() {
	for (int i = 0; i < numGr; i++) {
		groups[i]->electHead();
	}
}

void Deanery::print() {
	vector<pair<float, string>> vecSt = getStatSt();
	vector<pair<float, string>> vecGr = getStatGr();

	for (auto it = vecSt.begin(); it != vecSt.end(); ++it) {
		cout << it->second << " : " << it->first << endl;
	}
	cout << endl;
	for (auto it = vecGr.begin(); it != vecGr.end(); ++it) {
		cout << it->second << " : " << it->first << endl;
	}
}

void Deanery::printFile(string name) {
	vector<pair<float, string>> vecSt = getStatSt();
	vector<pair<float, string>> vecGr = getStatGr();
	ofstream out;
	out.open(name);
	if (out.is_open())
	{
		for (auto it = vecSt.begin(); it != vecSt.end(); ++it) {
			out << it->second << " : " << it->first << endl;
		}
		for (auto it = vecGr.begin(); it != vecGr.end(); ++it) {
			out << it->second << " : " << it->first << endl;
		}
	}
	out.close();
}
