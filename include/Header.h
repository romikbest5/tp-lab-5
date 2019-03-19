#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <fstream> 
using namespace std;

class Group;

class Student 
{
	friend class Group;
	friend class Deanery;

private:
	int id; //идентификационный номер
	string fio; //фамилия и инициалы
	Group * group; //ссылка на группу (объект Group)
	vector<int> marks; //массив оценок
	int num; //количество оценок

public:
	Student(int, string);//создание студента с указанием ИД и ФИО
	void addMark(unsigned int);//добавление оценки
	float midMark();//вычисление средней оценки
	string getFio();//получить ФИО
	int getid();//получить ID
	vector<int> getMarks();//получить оценки
	void GroupEnter(Group *group);//зачисление в группу
	Group * getGroup();//получить группу
};


class Group {
	friend class Deanery;

private:
	string title; //название группы
	vector<Student *> students; //массив из ссылок на студентов
	Student * head; //ссылка на старосту (из членов группы)
	int num; //количество студентов в группе

public:
	Group(string);//создание группы с указанием названия
	void addStudent(Student *);//добавление студента
	Student * electionHead();//избрание старосты
	Student * searchFio(string);//поиск студента по ФИО
	Student * searchId(int);//поиск студента по ИД
	float averageGroup();//вычисление соеднего балла в группе
	void deductFio(string);//исключение студента из группы
	void deductId(int);//исключение студента из группы
};



class Deanery {
private:
	string fileStudent, fileGroup;
	vector<Student *> students;//массив студентов
	vector<Group *> groups;//массив групп
	int numStudent, numGroup;

public:
	Deanery(string, string);
	void CreateGroup(); //создание групп на основе данных из файла
	void CreateStudent();//создание студентов на основе данных из файла
	void addRandomMarks();//добавление случайных оценок студентам
	vector<pair<float, string>> getStatisticStudents();//получение статистики по успеваемости студентов
	vector<pair<float, string>> getStatisticGroup();//получение статистики по успеваемости групп
	Student * searchFio(string);//поиск студента по имени
	Group * searchGroup(string);//поиск группы
	void changeGroup(string, string);//перевод студентов из группы в группу
	void Studentdeduction();//отчисление студентов за неуспеваемость
	void electionGroupHead();//инициация выборов старост в группах
	void print();//вывод данных на консоль
	void printFile();//сохранение обновленных данных в файлах
};