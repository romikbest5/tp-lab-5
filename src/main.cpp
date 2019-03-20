#include <iostream>
#include <string>

using namespace std;

#include "../include/Student.h"
#include "../include/Deanery.h"
#include "../include/Group.h"

int main()
{
	Student STUDENTS(0, "Philippova Marina Sergeevna");
	Group PMI("PMI");

	srand(time(0));

	PMI.addStudent(&STUDENTS, &PMI);

	for (int i = 0; i < 5; i++)
	{
		STUDENTS.addMark(rand() % 10 + 1);
	}

	STUDENTS.calcAverageMark();
	PMI.calcGroupAvMark();
	PMI.assignHead();

	Deanery DEANERY;
	DEANERY.createStudentsFromFile();
	DEANERY.createGroupsFromFile();

	for (int k = 0; k < 5; k++)
	{
		DEANERY.addMarks();
		cout << endl;
	}

	DEANERY.reChooseHeaders();
	DEANERY.deductStudents();
	DEANERY.showStatistic(12);
	DEANERY.showStatistic("PMI");
	DEANERY.changeStudentGroup(8, "BI");
	DEANERY.showStatistic("PI");
	DEANERY.saveData();

	return 0;
}