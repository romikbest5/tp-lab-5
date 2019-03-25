//
// Created by Александр Славутин on 2019-03-18.
//

#include "student.h"
#include "group.h"
#include "dean.h"


int main()
{


    Deanery Fimikn;

    Fimikn.make_students_list_from_file("students.txt");
    Fimikn.make_group_fromfile("groups.txt");
    Fimikn.add_random_mark();
    Fimikn.choose_head();
    Fimikn.get_statistic(&cout);
    Fimikn.student_transfer(6,"Bi");
    Fimikn.get_statistic(&cout);
    Fimikn.student_exclude();
    cout << "______________________";
    Fimikn.get_statistic(&cout);
    Fimikn.save_data_to_file();


}