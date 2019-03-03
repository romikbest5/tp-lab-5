#include <iostream>
#include "Group.h"
#include "Student.h"
#include "Deanery.h"
int main()
{

    Deanery d;
    d.createStudents(90);               //read data for students from file
    d.createGroups(3);                  //create 3 groups of 30 people
                                        //expell twonesses from two groups
    d.expell("PMI1");
    d.expell("PMI2");

    d.transfer(31, "PMI2", "PMI3");     //movement student

    d.election();                       //election in every group

    d.getInfo();                        //deanery stat
    d.writeToFile();                    //write new data

    return 0;
}
