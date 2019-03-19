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

using namespace std;


class Deanery{
private:
    vector <Student *> students_list;
    vector <Group*> groups_list;
public:
    void make_studentslist_from_file();
    void make_group_fromfile();



};