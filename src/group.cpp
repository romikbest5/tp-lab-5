//
// Created by Александр Славутин on 2019-03-18.
//

#include "group.h"


Group::Group(string title) {
    this->title = title;
}


void Group::make_new_group(string title){
    this->title = title;
}

void Group::add_student(Student* student, Group* group) {
    students_list.push_back(student);
    students_list.back()->student_enrollment(group); // back() is the reference to the last element of the vector
    num++;
}

Student* Group::choose_head() {
    int random;
    random = rand() % num;
    head =  students_list[random];
    return head;
}

float Group::get_average_group_mark() {
    float average_marks_sum = 0;
    for(auto& n : students_list)
        average_marks_sum += n->get_average_mark();
    return average_marks_sum / num;

}

