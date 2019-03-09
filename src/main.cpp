#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <string>
#include <algorithm>
#include <fstream>  
#include "../include/Classes.h"

using namespace std;


int main() {
	setlocale(LC_ALL, "Russian");

	Student stud1(10001, "Êèñëèöûíà Àíàñòàñèÿ Àíäðååâíà");
	Student stud2(10002, "Êòî-òî Òàì Åùå");

	stud1.addMark(5);
	stud1.addMark(4);
	stud1.addMark(5);
	stud2.addMark(3);
	stud2.addMark(4);
	stud2.addMark(5);

	float a1 = stud1.averageMark();
	float a2 = stud2.averageMark();
	cout << "Ñðåäíÿÿ îöåíêà Êèñëèöûíîé = " << a1 << endl;
	cout << "Ñðåäíÿÿ îöåíêà Êîãî-òî Òàì = " << a2 << endl;

	cout << "Id Êèñëèöûíîé: " << stud1.getId() << endl;

	
	Group gr1("17ÏÌÈ-1");
	gr1.addStudent(&stud1);
	gr1.addStudent(&stud2);
	
	Student * headd = gr1.electHead();
	cout << "Ñòàðîñòà ãðóïïû1 - " << headd->getFio() << endl;

	cout << "Ñðåäíÿÿ îöåíêà â ãðóïïå1 = " << gr1.averageGroup() << endl;
	gr1.deductFio("Êèñëèöûíà Àíàñòàñèÿ Àíäðååâíà");
	cout << "Ñðåäíÿÿ îöåíêà â ãðóïïå1 ïîñëå èñêëþ÷åíèÿ Êèñëèöûíîé= " << gr1.averageGroup() << endl;


	cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n" << endl;


	Deanery dean("students.txt", "groups.txt");
	dean.addGr();
	dean.addSt();
	dean.addRMarks();
	dean.electGrHead();
	cout << "Âûâîä äàííûõ\n" << endl;
	dean.print();
	dean.deductSt();
	cout << "\n\nÂûâîä äàííûõ ïîñëå èñêëþ÷åíèÿ íåóñïåâàþùèõ\n" << endl;
	dean.print();
	dean.printFile("outf.txt");
	
	system("pause");
}
