// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include "Student.h"
using namespace std;



int main()
{
	setlocale(LC_ALL, "Russian");
	Deanery first;
	first.ReadStudents("Students list.txt");
	first.ReadGroups("Groups.txt");
	first.SetMarks(5);
	first.ChoiceHead();
	first.kick();
	first.Statistic("stat.txt");
	first.SaveData("data.txt");





	
    return 0;
}

