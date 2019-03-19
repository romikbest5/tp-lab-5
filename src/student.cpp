#include "Deanery.h"
#include <iostream>
#include <fstream> 
#include <string>
#include <algorithm>
#include <ctime>



Student::Student(int nid, string name) {
	id = nid;
	fio = name;
}

void Student::enterGroup(Group * group) {
	this->group = group;

}

void Student::addMark(int mark) {
	marks.push_back(mark);
	num = marks.size();
}

float Student::averageMark() {
	int sum = 0;
	for (int i = 0; i < num; i++) {
		sum += marks[i];
	}
	return sum / num;
}