#include <iostream>

#include "../include/student.h"

/* ====== [Метод: создание студента с указанием ИД и ФИО] ====== */
void Student::create(int id, string fio)
{
	this->id = id;
	this->fio = fio;
	num = 0;
	cout << "Student " << this->fio << " was created." << endl;
}

/* ====== [Метод: зачисление в группу] ====== */
void Student::setGroup(Group *group_id) //Название группы по group_id
{
	this->group = group_id;
}

/* ====== [Метод: вычисление средней оценки] ====== */
float Student::calcAverageMark()
{
	float sum = 0;
	for (int i = 0; i < num; i++) //пройдем по всем студентам
	{
		sum += marks[i]; //суммируем их оценки
	}
	return sum / num; // вычислим сред.ариф.
}

/* ====== [Метод: добавление оценки] ====== */
void Student::addMark(unsigned int mark)
{
	marks.push_back(mark); //добавим в конец массива оценку
	num++; //увеличим количество оценок
}
