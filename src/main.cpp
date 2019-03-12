#include "Deanery.cpp"
#include <iostream>
#include <ctime>

using namespace std;

int main(){

    Deanery deanery;

    // Загрузка и создание группы 1

    Group * group1 = deanery.createGroup ("17ПМИ");
    string filenameGroup1 = "../data/group1.txt";
    deanery.loadGroupFromFile(filenameGroup1, group1);

    // Загрузка и создание группы 2

    Group * group2 = deanery.createGroup ("17ПИ");
    string filenameGroup2 = "../data/group2.txt";
    deanery.loadGroupFromFile(filenameGroup2, group2);

    // Загрузка студентов

    string filenameGroup3 = "../data/group3.txt";
    deanery.loadStudentsFromFile (filenameGroup3);

    // Создание группы и зачисление студентов в эту группу в ручную

    Group * group3 = deanery.createGroup("17БИ");
    vector<Student *> v;
    for (auto i : deanery.students) {
        if (i -> group == nullptr)
            deanery.replaceStudent (i, i -> group, group3);
        v.push_back(i);
    }

    // Выставление оценок всем студентам

    srand (time(nullptr));

    for (int i = 0; i < 10; i++)
        for (auto student : deanery.students)
            deanery.setMark(student, {to_string(i).append("Subject"), rand() % 10 + 1});

    // Отчисление студентов с неудовлетворительным средним баллом

    deanery.deductionStudentByCriteria ([](Student * a) -> bool {return a->GPA < 4;});

    // Получение и схранение статистики в файл

    string fileStatistics = ("../data/statistics.txt");
    deanery.saveStatistics (fileStatistics, group2);

    // Сохранение данных в файл

    string dataOut = "../data/output.txt";
    deanery.saveData(dataOut);

    // Вывод данных на консоль

    deanery.printData (&cout);

    cout << "====================================================\n\n";

    // Вывод статистики на консоль

    auto data = deanery.getStatistics ();
    deanery.printStatistics (deanery.getStatistics (group1), &cout);


    return 0;

}