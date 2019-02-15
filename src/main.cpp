 
#include "lab5.h"

using namespace std;

int main()
{
	
	Deanery IMIKN("students.txt");
	IMIKN.printStatics();
	string name = "Perkins Steven";
	string title = "PI";
	IMIKN.transfer(name, IMIKN.searchGroup(title));
	IMIKN.checkProgress(3.0);
	IMIKN.reelection();
	IMIKN.updateData("studentsUpdate.txt");
	IMIKN.printStatics();
	system("pause");
}
