#include "Deanery.h"

#include <iostream>

using namespace std;

int main()
{
    Deanery deanery;

    // Считываем студентов из файла
    deanery.ReadStudentsFromFile("../data/students.txt");
    // Считываем группы из файла и распределяем студентов по группам
    deanery.ReadGroupsFromFile("../data/groups.txt");
    // Добавим немножко оценок
    deanery.AddRandomMarks();
    // Выберем старост
    deanery.ChooseHeads();
    // Узнаем успеваемость
    deanery.GetStatistic(&cout);
    // Исключим неуспевающих
    deanery.ExcludeStudent();
    // Узнаем сколько осталось
    deanery.GetStatistic(&cout);
    // Попробуем перевести студента, но ошибемся в названии группы
    try
    {
        deanery.TransferStudentToGroup(1, "17ПМИ-5"); // 1 id студента
    }
    catch (int)
    {
        cout << "Mistake in title was made" << endl << endl;
    }
    // Корректный перевод
    deanery.TransferStudentToGroup(1, "17ПМИ-3"); // 1 id студента
    // Узнаем что произошло
    deanery.GetStatistic(&cout);
    // Сохраним данные
    deanery.SaveData();
    return 0;
}

