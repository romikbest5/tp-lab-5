//
// Created by Александр Славутин on 2019-03-18.
//
#include "deanery.h"

#define LOWEST_MARK 5


Deanery::Deanery()
{
    num_of_students = 0;
    vector<Student* > students_list;
    vector<Group*> groups_list;
}

void Deanery::make_students_list_from_file(string filename)
{
        //filename = "..\\" + filename;
        ifstream file(filename);
        if (file.is_open()) {

            string s;
            while (getline(file, s))
                students_list.push_back(new Student(num_of_students++, s));
        }
        else {
            cout<<"Not open!";
        }

            file.close();
}

void Deanery::make_group_fromfile(const string& filename)
{
    ifstream file;
    file.open(filename);

    string s;
    while (getline(file, s))
        groups_list.push_back(new Group(s)); // title

    int random;
    for (Student* student:students_list)
    {
        random = rand() % groups_list.size();
        groups_list[random]->add_student(student);
    }
    file.close();


}


void Deanery::add_random_mark()
{
    int random;

    for(auto& n : students_list)
    {
       for (int i(0); i < 5; ++i)
       {
           random = rand() % 10 + 1;
           n->add_mark(random);
       }
    }
}

void Deanery::choose_head()
{
    for(auto& n : groups_list)
    {
        n->choose_head();
    }
}

void Deanery::student_exclude()
{
    for(size_t i(0); i < students_list.size(); ++i)
    {
        if(students_list[i]->get_average_mark() < LOWEST_MARK)
        {
           students_list[i]->group->student_elimination(students_list[i]->id);
           Student* student = students_list[i];
           students_list.erase(students_list.begin() + i);
           delete student;
        }

    }
}


void Deanery::get_statistic(string something)
{
    if(something[0] >= '0' && something[0] <= '9')
    {
        int search_id = stoi(something);
        for (int i = 0; i < num_of_students ; ++i)
        {
            if (students_list[i]->id == search_id)
            {
                cout << "FIO" <<students_list[i]->fio  << "ID:" <<students_list[i]->id << endl;
                cout << "Student has: " << students_list[i]->num << "marks" << endl;
                cout << "Marks: ";
                for (int j = 0; j < students_list[i]->num; j++)
                {
                    cout << students_list[i]->marks[j]<<" ";
                }
                cout<<"________________"<< endl;
                cout<<"The average mark:" << students_list[i]->get_average_mark();
                cout<< "The group of the student:" << students_list[i]->group;
                cout<<endl;

            }

        }
    }


}





