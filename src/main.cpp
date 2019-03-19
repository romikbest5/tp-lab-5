//
// Created by Александр Славутин on 2019-03-18.
//

#include "student.h"
#include "group.h"


int main()
{
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
    first.add_student(&Saavutin,&first);
    first.add_student(&Spavutin,&first);
    first.add_student(&Sdavutin,&first);
    first.add_student(&Slavutin,&first);
    first.student_elimination(1);
    cout<<first.student_search(3);

}