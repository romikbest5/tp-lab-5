//
// Created by Александр Славутин on 2019-03-18.
//

#include "student.h"
#include "group.h"
#include "deanery.h"

int main()
{
    Deanery deanery;
    deanery.make_students_list_from_file(R"(C:\Education\Shtanuk\tp-lab-5\src\students.txt)");
    deanery.make_group_fromfile(R"(C:\Education\Shtanuk\tp-lab-5\src\groups.txt)");
    deanery.add_random_mark();
    deanery.get_statistic("1");
    /*
    Student Slavutin(1,"Slavutin Alexander");
    Student Spavutin(2,"Spavutin Alexander");
    Student Saavutin(3,"Saavutin Alexander");
    Student Sdavutin(4,"Sdavutin Alexander");
    Slavutin.add_mark(7);
    Spavutin.add_mark(6);
    Sdavutin.add_mark(10);
    Slavutin.add_mark(9);
    Saavutin.add_mark(7);
    Group first("17PMI");
    first.add_student(&Saavutin);
    first.add_student(&Spavutin);
    first.add_student(&Sdavutin);
    first.add_student(&Slavutin);
    first.student_elimination(1);
    cout<<first.student_search(3);
     */


}