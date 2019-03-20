#pragma once
#include <vector>
#include <string>

#include "Student.h"
#include "Group.h"

using namespace std;

class Deanery
{
private:
	/* ==================== [Переменные] ==================== */
	int groups_amount;			// количество групп
	int students_amount;		// количество студентов
	vector<Student*> students;	// массив студентов
	vector<Group*> groups;		// массив групп

public:
	/* ==================== [Методы] ==================== */
	Deanery() // конструктор по умолчанию
	{
		students_amount = 0;
		groups_amount = 0;
	}
	bool createStudentsFromFile();					// создание студентов на основе данных из файла
	bool createGroupsFromFile();					// создание групп на основе данных из файла
	void addMarks();								// добавление случайных оценок студентам
	void showStatistic(int);						// получение статистики по успеваемости студентов
	void showStatistic(string);						// получение статистики по успеваемости групп
	bool changeStudentGroup(int id,string group);	// перевод студентов из группы в группу
	void deductStudents();							// отчисление студентов за неуспеваемость
	void saveData();								// сохранение обновленных данных в файлах
	void reChooseHeaders();							// инициация выборов старост в группах
	void consoleOut();								// вывод данных на консоль
};