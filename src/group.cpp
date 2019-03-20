#include <iostream>

#include "../include/group.h"

/* ====== [Метод: создание группы с указанием названия] ====== */
void Group::create(string title)
{
	this->title = title;
	num = 0;
}

/* ====== [Метод: добавление студента в группу] ====== */
void Group::addStudent(Student *st, Group *group)
{
	students.push_back(st); // добавим студента в массив
	students.back()->setGroup(group); // и сразу назначим ему группу
	num++;
}

/* ====== [Метод: выбор старосты группы] ====== */
Student* Group::assignHead()
{
	srand(time(0));
	int id = rand() % num;//генерируем случайное число
	head = students[id];//находим студента с id == случайное число

	Student *stud = findStudentByID(id); //ищем студента по сгенерированному id
	if (stud) cout << "[G_HEADMAN] Student " << stud->fio << " was assigned as a headman of the group." << endl;

	return head;
}

/* ====== [Метод: поиск студента по АЙДИ] ====== */
Student* Group::findStudentByID(int id)
{
	for (int i = 0; i < num; i++) //пройдем по всем студентам
	{
		if (students[i]->id == id) return students[i]; //если нашли искомый id - возвращаем студента
	}
	return 0; //иначе, если так и не нашли - 0
}

/* ====== [Метод: вычисление среднего балла в группе] ====== */
float Group::calcGroupAvMark()
{
	float sum = 0;
	for (int i = 0; i < num; i++) //пройдем по всем студентам
	{
		sum += students[i]->calcAverageMark(); //суммируем средний балл каждого студента
	}

	if (num != 0) sum = sum / num; // если сумма не нулевая, то можно высчитывать ср.балл группы
	return sum;
}

/* ====== [Метод: исключение студента из группы] ====== */
void Group::excludeStudent(int id)
{
	for (int i = 0; i < num; i++) //пройдем по всем студентам
	{
		if (students[i]->id == id) //если нашли искомый id
		{
			students.erase(students.begin() + i); //удалим из списка студента
			num--; //уменьшим общее количество студентов
			break;
		}
	}
}