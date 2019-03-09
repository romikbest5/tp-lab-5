#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <string>
#include <algorithm>
#include <fstream>  
#include "Classes.h"

using namespace std;


int main() {
	setlocale(LC_ALL, "Russian");

	Student stud1(10001, "Кислицына Анастасия Андреевна");
	Student stud2(10002, "Кто-то Там Еще");

	stud1.addMark(5);
	stud1.addMark(4);
	stud1.addMark(5);
	stud2.addMark(3);
	stud2.addMark(4);
	stud2.addMark(5);

	float a1 = stud1.averageMark();
	float a2 = stud2.averageMark();
	cout << "Средняя оценка Кислицыной = " << a1 << endl;
	cout << "Средняя оценка Кого-то Там = " << a2 << endl;

	cout << "Id Кислицыной: " << stud1.getId() << endl;

	
	Group gr1("17ПМИ-1");
	gr1.addStudent(&stud1);
	gr1.addStudent(&stud2);
	
	Student * headd = gr1.electHead();
	cout << "Староста группы1 - " << headd->getFio() << endl;

	cout << "Средняя оценка в группе1 = " << gr1.averageGroup() << endl;
	gr1.deductFio("Кислицына Анастасия Андреевна");
	cout << "Средняя оценка в группе1 после исключения Кислицыной= " << gr1.averageGroup() << endl;


	cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n" << endl;


	Deanery dean("students.txt", "groups.txt");
	dean.addGr();
	dean.addSt();
	dean.addRMarks();
	dean.electGrHead();
	cout << "Вывод данных\n" << endl;
	dean.print();
	dean.deductSt();
	cout << "\n\nВывод данных после исключения неуспевающих\n" << endl;
	dean.print();
	dean.printFile("outf.txt");
	
	system("pause");
}