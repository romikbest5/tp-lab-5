#ifndef DEANERY_H
#define DEANERY_H

#include "Group.h"
#include "Student.h"
#include <fstream>

class Deanery{
private:
    std::vector <Student> students;
    std::vector <Group> groups;
public:
    Deanery();
    void createStudents(int number_of_students);
    void createGroups(int number_of_groups);
    Group* searchGroup(std::string groupName);          //search group by name
    void getInfo();
    bool transfer(int id, std::string oldGroupName,
                          std::string newGroupName);
    bool expell(std::string groupName);                 //expell all twonesses from group
    void election();                                    //election in every group
    void election(std::string nameGroup);               //election in respective group
    bool writeToFile();                                 //write data into file
};
#endif // DEANERY_H
