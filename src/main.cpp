
#include <iostream>
using namespace std;
#include "Deanery.h"

int main()
{
	setlocale(LC_ALL, "Russian");

	Deanery deanery("Students.txt", "Group.txt");
	deanery.CreateStudents();
	deanery.CreateGroups();
	deanery.addMarks();
	deanery.electGhead();

	deanery.exceptionStudent();
	deanery.changeGroup("Путинова Инна Феодосьевна", "ПМИ-3");
	deanery.changeGroup("Коломников Семён Даниилович", "ПМИ-1");
	deanery.changeGroup("Яшихина Алина Макаровна", "ПМИ-2");

	deanery.getStatistics("Statistics.txt");
	deanery.update("Data.txt");
	deanery.printinfo();


}