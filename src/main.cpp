#include<iostream>
#include<random>
#include<string>
using namespace std;
#include "Student.h"
#include "Deanery.h"
#include "Group.h"
int main()
{
	setlocale(LC_ALL, "rus");
	Student a(38, "Безухов Владимир Алексеевич");

	Group H("New");
	random_device ran;
	for (int i = 0; i < 5; i++)
	{
		a.AddMark(ran() % 10 + 1);
	}
	a.AverageMark();
	H.AddStudent(&a, &H);
	H.AverageInGroup();
	H.HeadElection();


	Deanery dean;
	for (int i = 0; i < 30; i++)
	{
		dean.CreateStudentsFromFile();
	}
	for (int j = 0; j < 3; j++)
	{
		dean.CreateGroupsFromFile();
	}
	for (int k = 0; k < 5; k++)
	{
		dean.AddMarks();
	}
	dean.ChooseHeads();
	dean.StudentDeduction();
	dean.GetStatistic("12");
	dean.StudentTransferToGroup(12, "ПМИ");
	dean.GetStatistic("12");
	dean.GetStatistic("ПМИ");
	dean.SaveDataInFiles();
	system("pause");
	return 0;
}