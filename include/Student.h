#pragma once

#include <string>
#include <vector>

using namespace std;

// для области видимости и объявления их дружественными
class Group;
class Deanery;

class Student 
{
private:
	/* ==================== [Переменные] ==================== */
	int id;						// идентификационный номер студента
	string fio;					// фамилия и инициалы студента
	Group *group;				// к какой группе студент относится ( ссылка на группу (объект Group) )
	vector<unsigned int> marks;	// массив оценок студента
	int num;					// количество оценок студента

public:
	/* ==================== [Методы] ==================== */
	Student() // конструктор по умолчанию
	{
		this->id = -1;
		this->fio = "NoName";
		num = 0;
	}

	Student(int id, string fio) // конструктор с параметрами
	{
		this->create(id, fio);
	}
	void create(int id, string fio);	// создание студента с указанием ИД и ФИО
	void setGroup(Group *);				// зачисление в группу
	void addMark(unsigned int mark);	// добавление оценки
	float calcAverageMark();			// вычисление средней оценки

	// дружественные классы
	friend Group;
	friend Deanery;
};