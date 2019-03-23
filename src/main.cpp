#include <iostream>
#include "lab5.h"
using namespace std;


int main()
{

	Deanery deanery("Students.txt", "Groups.txt");
	deanery.create_students();
	deanery.create_groups();
	deanery.add_marks();
	deanery.elect_ghead();

	deanery.exception_student();


	deanery.get_statistics("Statistics.txt");
	deanery.update("Data.txt");
	deanery.print_info();

	system("pause");
	return 0x0000;
}