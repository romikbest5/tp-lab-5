//
// Created by Александр Славутин on 2019-03-18.
//
#include "deanery.h"

ifstream students_file("students.txt");
ifstream groups_file("groups.txt");
ofstream my_file("data.txt");

void Deanery::make_studentslist_from_file() {
    if (!students_file.is_open())
    {
        students_file.open("students.txt");
        return;
    }
    else
        {
        string fio_from_file= "";
        string id_from_file = "";
        char tmp[30];
        students_file.getline(tmp,30);
        int tmp_len = strlen(tmp);
        if (tmp[0] == ' ')
        {
            students_file.close();
            return;
        }

        for(int i = 0; i < tmp_len; ++i)
        {
            if (tmp[i] >= '0' && tmp[i] <= '9' )
            {
                id_from_file += tmp[i];
            }
            else
                {
                fio_from_file += tmp[i];
                }

        }
        int id_fromfile = stoi(id_from_file);
        students_list.push_back(new Student(id_fromfile,fio_from_file));
        }
}
