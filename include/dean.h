//
// Created by Александр Славутин on 2019-03-19.
//


#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <fstream>
#include "student.h"
#include "group.h"
enum STATES  {COMPLETED, FAILED};

using namespace std;


class Deanery{
private:
    vector <Student *> students_list;
    vector <Group*> groups_list;
    unsigned int num_of_students;
public:
    Deanery();
    STATES  state;
    void make_students_list_from_file(const string& filename);
    void make_group_fromfile(const string& filename);
    void add_random_mark();
    void choose_head();
    void student_exclude();
    void get_statistic(ostream* stream);
    STATES student_transfer(int id, string title);
    void save_data_to_file();
    STATES getState();
};