 #include "Header.h"
using namespace std;

int main() 
{
	setlocale(LC_ALL, "rus");
	Deanery deanery("Students.txt", "Group.txt");
	deanery.CreateGroup();
	deanery.CreateStudent();
	deanery.addRandomMarks();
	deanery.electionGroupHead();
	deanery.print();
	deanery.Studentdeduction();
	deanery.print();
	deanery.printFile();

	system("pause");
}