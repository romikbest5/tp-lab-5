//
// Created by Александр Славутин on 2019-03-18.
//
#include "dean.h"

#define LOWEST_MARK 4

string eliminated = "";

Deanery::Deanery()
{
    num_of_students = 0;
    vector<Student* > students_list;
    vector<Group*> groups_list;
}

void Deanery::make_students_list_from_file(const string& filename)
{
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
    ifstream file(filename);
    string s;
    if(file.is_open()){
    while (getline(file, s))
        groups_list.push_back(new Group(s)); // title

    for (Student* student:students_list)
    {
        groups_list[rand() % groups_list.size()]->add_student(student);
    }
    } else {
        cout << "Not open!";
    }
    file.close();


}


void Deanery::add_random_mark()
{

    for(auto& n : students_list)
    {
       for (int i(0); i < 5; ++i)
       {
           n->add_mark(rand() % 10 + 1);
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
            eliminated += "\n"+students_list[i]->fio + " the average mark: "+to_string(students_list[i]->get_average_mark());
            students_list[i]->group->student_elimination(students_list[i]->id);
            students_list.erase(students_list.begin() + i);
        }

    }
}

void Deanery::get_statistic(ostream* stream){
    for (auto &g : groups_list)
    {
        *stream << "\nThe title of the group: " << g->title
                << "\nThe head of the group: " << g->head->fio<<".The average mark: " << g->head->get_average_mark()<< "\n\n";
        for (auto & s : g->students_list)
            *stream << "ID: " << s->id <<  " " <<s->fio
                    << " The average mark: " << s->get_average_mark() << "\n";
        *stream << "Average mark int the group: " << g->get_average_group_mark() << "\n";
        *stream << "Students amount in the group: " << g->num << "\n\n";
    }
    *stream << "Students amount in the group: " << students_list.size() << "\n\n";
    *stream << "The lowest acceptable mark is '4'. \nWere expelled: " << eliminated << "\n\n";


}

STATES Deanery::student_transfer(int id, string title)
{
    state = FAILED;
    for (auto &s : students_list)
    {
        if(s->id == id)
        {
            for(auto &g : groups_list)
            {
                if (g->title == title)
                {
                    Student* move_student = s; // make a temporary student object
                    (s->group)->student_elimination(s->id); // delete student from old group
                    g->add_student(move_student); // transfer student to new group
                    return state = COMPLETED;

                }
            }
        }
    }
    return state;
}


void Deanery::save_data_to_file()
{
    ofstream file_out("info_file.txt",ios_base::trunc);
    get_statistic(new ostream(file_out.rdbuf()));
}


STATES Deanery::getState()
{
    switch (state)
    {
        case(COMPLETED):
            return COMPLETED;
        case (FAILED):
            return FAILED;
    }



}





