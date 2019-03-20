#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>

#include "../include/dean.h"

/* =============== [Метод: создать студента, считав из файла] =============== */
bool Deanery::createStudentsFromFile()
{
	// создаем переменную для взаимодействия с файлами и откроем .txt файл:
	ifstream FileStudents("D:/Visual Studio PJCTS/MarinaSolution/ShtanukTasks/src/students.txt");
	
	if (!FileStudents.is_open()) // если открыть не удалось
	{
		cout << "[OPENING FileStudents ERROR] FAILED to open" << endl;
		return false; // считать с файла не удалось...
	}
	else
	{
		const short int MAX_SIZE = 80; // максимальное количество символов для чтения/записи
		char buffer[MAX_SIZE]; // буфер с данными
		for (int i = 0; !FileStudents.eof(); i++)
		{
			if (FileStudents.eof()) // если мы дошли до конца файла
			{
				delete[] buffer; // удаляем буфер
				FileStudents.close(); // закрываем наш файл
				return true; // функция отработала успешно.
			}
			
			FileStudents.getline(buffer, MAX_SIZE, ' '); // прочитать строку до первого попавшегося на пути пробела
			
			if (buffer[0] == '\0') // если, в буфер вообще ничего не попало
			{
				FileStudents.close(); // то закрываем наш файл
				return false; // считать с файла не удалось...
			}

			int student_ID = atoi(buffer); // преобразовать в число и записать в переменную student_ID

			FileStudents.getline(buffer, MAX_SIZE); // прочитать оставшуюся часть строки
			string student_NAME = buffer; // записать оставшуюся часть в переменную student_NAME

			// если ID студента == 0, то скорее всего считать ID студента из файла не удалось (не указан в файле)
			if (student_ID == 0) cout << "[WARNING] Perhaps " << student_NAME << " does not have an ID number!" << endl;
			if (student_NAME == "") cout << "[WARNING] Perhaps student with ID №" << student_ID << " does not have a name!" << endl;

			cout << student_ID << " ";

			students.push_back(new Student(student_ID, student_NAME)); // добавим в конец массива со студентами объект нового студента
			students_amount++; // увеличим количество студентов
		}
	}
	return false; //если мы каким-то образом дошли до сюда - значит что-то пошло не так
}

/* =============== [Метод: создать группу, считав из файла] =============== */
bool Deanery::createGroupsFromFile()
{
	// создаем переменную для взаимодействия с файлами и откроем .txt файл:
	ifstream FileGroups("D:/Visual Studio PJCTS/MarinaSolution/ShtanukTasks/src/groups.txt");
	
	if (!FileGroups.is_open()) // если открыть не удалось
	{
		cout << "[OPENING FileGroups ERROR] FAILED to open" << endl;
		return false; // считать с файла не удалось...
	}
	else
	{
		const short int MAX_SIZE = 80; // максимальное количество символов для чтения/записи
		char buffer[MAX_SIZE]; // буфер с данными
		for (int i = 0; !FileGroups.eof(); i++)
		{
			if (FileGroups.eof()) // если мы дошли до конца файла
			{
				delete[] buffer; // удаляем буфер
				FileGroups.close(); // закрываем наш файл
				return true; // функция отработала успешно.
			}

			FileGroups.getline(buffer, MAX_SIZE); // прочитать строку до первого попавшегося на пути пробела

			if (buffer[0] == '\0') // если, в буфер вообще ничего не попало
			{
				FileGroups.close(); // то закрываем наш файл
				return false; // считать с файла не удалось...
			}

			string group_NAME = buffer; // записать считанную строку в переменную group_NAME

			groups.push_back(new Group(group_NAME)); // добавим в конец массива с группами объект новой группы
			
			// зачислить студентов в группы по 10 человек в каждую
			for (int i = groups_amount * 10; i < groups_amount * 10 + 10; i++)
			{
				groups[groups_amount]->addStudent(students[i], groups[groups_amount]);
			}

			groups_amount++; // увеличим количество групп
		}
	}
	return false; //если мы каким-то образом дошли до сюда - значит что-то пошло не так
}

/* =============== [Метод: получение статистики по успеваемости] =============== */
void Deanery::addMarks()
{
	srand(time(0));
	for (int i = 0; i < groups_amount; i++) // пройдем по всем группам
	{
		for (int j = 0; j < groups[i]->num; j++) // и в каждой группе по всем студентам
		{
			groups[i]->students[j]->addMark(rand() % 10 + 1); // в каждой группе каждому студенту добавим случайную оценку
		}
	}
}

/* =============== [Методы: получение статистики по успеваемости] =============== */
void Deanery::showStatistic(int student_ID) // по студенту
{
	for (int i = 0; i < students_amount; i++)
	{
		if (student_ID == students[i]->id)
		{
			cout << "========== STATISTIC OF STUDENT ==========" << endl;
			cout << "\t" << students[i]->fio << endl << "------------------------------------------" << endl;
			cout << "ID number: "<<students[i]->id << endl;
			cout << "Amount of marks: " << students[i]->num << endl;
			cout << "Marks: ";
			for (int j = 0; j < students[i]->num; j++)
			{
				cout << students[i]->marks[j]<<" ";
			}
			cout << endl;
			cout << "Average Mark: " << students[i]->calcAverageMark() << endl;
			cout << "Group: " << students[i]->group->title << endl;
			cout << "==========================================" << endl;
			
			break;
		}
	}
}

void Deanery::showStatistic(string group_NAME) // по группе
{
	for (int i = 0; i < groups_amount; i++)
	{
		if (group_NAME == groups[i]->title)
		{
			cout << "============ STATISTIC OF GROUP: " << groups[i]->title << " =============" << endl;
			cout << "Head of the group: [ID: " << groups[i]->head->id << "]: " << groups[i]->head->fio << endl;
			cout << "Average mark in group: " << groups[i]->calcGroupAvMark() << endl;
			cout << endl;
			cout << "================= Students list =================" << endl << endl;
			for (int j = 0; j < groups[i]->num; j++)
			{
				cout << "\t[ID: " << groups[i]->students[j]->id << "]: " << groups[i]->students[j]->fio << endl;
				cout << "\tNumber of marks: " << groups[i]->students[j]->num << endl;
				cout << "\tAverage Mark: " << groups[i]->students[j]->calcAverageMark() << endl;
				cout << "--------------------------------------------------" << endl;
			}
		}
	}
}

/* =============== [Метод: перевод студентов из группы в группу] =============== */
bool Deanery::changeStudentGroup(int student_ID, string group)
{
	//cout << students[student_ID]->fio << endl;
	int g_id = 0; //искомый id группы, в которой числится студент
	int s_id = 0; //искомый id студента, в группе которой (g_id) числится студент

	for (int g = 0; g < groups_amount; g++) // пройдемся по всем группам
	{
		for (int s = 0; s < groups[g]->num; s++) // пройдемся по всем студентам
		{
			if (groups[g]->students[s]->id == student_ID) // если айди студента совпадает с искомым
			{
				g_id = g; // запомним id группы студента
				s_id = s; // запомним id студента в группе g_id
				break;
			}
		}
	}

	for (int g_new = 0; g_new < groups_amount; g_new++) // снова пройдемся по всем группам
	{
		if (groups[g_new]->title != group) continue; // если название группы не совпадает с искомой - пропускаем итерацию
		else // иначе, мы нашли ту группу, в которую хотим переместить студента
		{
			bool HEADER = false; //флаг, обозначающий является ли наш найденный студент старостой
			if (groups[g_id]->head == students[s_id]) HEADER = true; //при таком условии - да, наш студент - староста

			students[s_id]->group->title = group; // изменить у студента наименование его группы, в которой он теперь числится
			groups[g_new]->addStudent(groups[g_id]->students[s_id], groups[g_new]); //добавляем студента в новую группу

			groups[g_id]->excludeStudent(groups[g_id]->students[s_id]->id); //исключаем студента из старой его группы
			
			if (HEADER) reChooseHeaders(); //если таки наш студент был старостой, делаем переизбрание
			return true; // операция удалась
		}
	}
	return false; // операция не удалась
}

/* =============== [Метод: отчисление студентов за неуспеваемость] =============== */
void Deanery::deductStudents()
{
	for (int g = 0; g < groups_amount; g++) // пройдемся по всем группам
	{
		for (int s = 0; s < groups[g]->num; s++) // пройдемся по всем студентам
		{
			if (groups[g]->students[s]->calcAverageMark() < 3.5) //если в какой то группе студент имеет средний балл < 3.5
			{
				bool HEADER = false; //флаг, обозначающий является ли наш найденный студент старостой
				if (groups[g]->head == students[s]) HEADER = true;

				groups[g]->excludeStudent(groups[g]->students[s]->id); //исключаем студента
				students_amount--; // общее количество студентов теперь на одного меньше
				s--; // т.к мы исключили студента, то и цикл теперь на 1 итерацию меньше

				if (HEADER) reChooseHeaders(); // если это был староста, делаем переизбрание
			}
		}
	}
}

/* =============== [Метод: сохранение обновленных данных в файлах] =============== */
void Deanery::saveData()
{
	// укажем в какой файл мы хотим сохранять информацию:
	ofstream FileNew("D:/Visual Studio PJCTS/MarinaSolution/ShtanukTasks/src/data.txt");
	FileNew.clear(); // перед каждой новой записью в файл стираем старые данные

	for (int g = 0; g < groups_amount; g++) // пройдем по всем группам
	{
		for (int s = 0; s < groups[g]->num; s++) // по каждому студенту
		{
			FileNew << "\t" << groups[g]->students[s]->fio << endl << "------------------------------------------" << endl;
			FileNew << "ID number: " << groups[g]->students[s]->id << endl;
			FileNew << "Amount of marks: " << groups[g]->students[s]->num << endl;
			FileNew << "Marks: ";
			for (int k = 0; k < groups[g]->students[s]->num; k++)
			{
				FileNew << groups[g]->students[s]->marks[k] << " ";
			}
			FileNew << endl;
			FileNew << "Average Mark: " << groups[g]->students[s]->calcAverageMark() << endl;
			FileNew << "Group: " << groups[g]->students[s]->group->title << endl;
			FileNew << "==========================================" << endl;
		}
	}
	FileNew.close(); // закроем файл
}

/* =============== [Метод: инициация выборов старост в группах] =============== */
void Deanery::reChooseHeaders()
{
	for (int i = 0; i < groups_amount; i++) //проходимся по всем группам
	{
		groups[i]->assignHead(); //в каждой группе назначаем старосту случайным образом
	}
}

/* =============== [Метод: инициация выборов старост в группах] =============== */
void Deanery::consoleOut()
{
	for (int g = 0; g < groups_amount; g++) // пройдем по всем группам
	{
		for (int s = 0; s < groups[g]->num; s++) // по каждому студенту
		{
			cout << "\t" << groups[g]->students[s]->fio << endl << "------------------------------------------" << endl;
			cout << "ID number: " << groups[g]->students[s]->id << endl;
			cout << "Amount of marks: " << groups[g]->students[s]->num << endl;
			cout << "Marks: ";
			for (int k = 0; k < groups[g]->students[s]->num; k++)
			{
				cout << groups[g]->students[s]->marks[k] << " ";
			}
			cout << endl;
			cout << "Average Mark: " << groups[g]->students[s]->calcAverageMark() << endl;
			cout << "Group: " << groups[g]->students[s]->group->title << endl;
			cout << "==========================================" << endl;
		}
	}
}