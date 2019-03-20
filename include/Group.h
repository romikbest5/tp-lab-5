#pragma once

#include <vector>
#include <string>
#include <ctime>

#include "Student.h"

using namespace std;

class Group 
{
private:
	/* ==================== [Переменные] ==================== */
	string title;				// название группы
	vector<Student*> students;	// массив из ссылок на студентов
	int num;					// количество студентов в группе
	Student *head;				// ссылка на старосту (из членов группы)

public:
	/* ==================== [Методы] ==================== */
	Group(string title) // конструктор с параметрами
	{
		num = 0;
		this->title = title;
	}
	void create(string title);			// создание группы с указанием названия
	void addStudent(Student *,Group *);	// добавление студента в группу
	Student* assignHead();				// выбор старосты группы
	Student* findStudentByID(int id);	// поиск студента по АЙДИ
	float calcGroupAvMark();			// вычисление среднего балла в группе
	void excludeStudent(int id);		// исключение студента из группы

	friend Deanery;
};