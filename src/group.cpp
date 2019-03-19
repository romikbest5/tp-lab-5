//
// Created by Александр Славутин on 2019-03-18.
//

#include "group.h"


Group::Group(string title)
{
    this->title = title;
}


void Group::make_new_group(string title)
{
    this->title = title;
}

void Group::add_student(Student* student, Group* group)
{
    students_list.push_back(student);
    students_list.back()->student_enrollment(group); // back() is the reference to the last element of the vector
    num++;
}

Student* Group::choose_head()
{
    int random;
    random = rand() % num;
    head =  students_list[random];
    return head;
}

float Group::get_average_group_mark()
{
    float average_marks_sum = 0;
    for(auto& n : students_list)
        average_marks_sum += n->get_average_mark();
    return average_marks_sum / num;

}

Student* Group::student_search(int id)
{
    Student* answer_ptr;
    for(auto& n : students_list)
    {
        if(n->id ==id)
            return answer_ptr = n;
    }
    cout << "There is no such student in the group";
    return answer_ptr = nullptr;
}

void Group::student_elimination(int id) {
    for (int i = 0; i < num; i++) {
        if (students_list[i]->id == id)
        {
            students_list.erase(students_list.begin() + i);
            num--;

        }
    }
}
