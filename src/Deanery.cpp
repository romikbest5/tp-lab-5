#include "Deanery.h"

Deanery::Deanery(){
    std::cout<<"Deanery"<<std::endl;
}

void Deanery::createStudents(int number_of_students){
    for(int i = 1; i <= number_of_students; i++)
        this->students.push_back(Student(i));
}

void Deanery::createGroups(int number_of_groups){
    for(size_t i = 0; i < size_t(number_of_groups); i++){
        std::string name_group = "PMI" + std::to_string(i + 1);
        this->groups.push_back(Group(name_group));
        for(size_t j = i*NUM_ST; j < (i + 1)*NUM_ST; j++){
            groups[i].addStudent(&(this->students[j]));
        }
        this->groups[i].election();
    }
}

void Deanery::election(){
    for(auto group: this->groups){
        group.election();
    }
}

void Deanery::getInfo(){
    std::cout<<"number of students: "<<students.size()<<"| number of groups: "<<groups.size()<<std::endl;
    std::cout<<"groups: "<<std::endl;
    for(auto x: groups)
        x.getInfo();
}

bool Deanery::transfer(int id, std::string oldGroupName, std::string newGroupName){
    Group* groupOld = nullptr;
    Group* groupNew = nullptr;
    for (size_t i = 0; i < this->groups.size(); i++){
        if(groups[i].title == oldGroupName)
            groupOld = &groups[i];
        if(groups[i].title == newGroupName)
            groupNew = &groups[i];
    }
    if ((groupNew == nullptr)||(groupOld == nullptr)){
        return false;
    }
    Student* searchStudent = groupOld->search(id);
    if ((searchStudent != nullptr)&&(groupOld->expell(id))){
        groupNew->addStudent(searchStudent);
        return true;
    }
    return false;
}

Group* Deanery::searchGroup(std::string groupName){
    for(size_t i = 0; i < this->groups.size(); i++){
        if (this->groups[i].title == groupName)
            return &(this->groups[i]);
    }
    return nullptr;
}

bool Deanery::expell(std::string groupName){
    Group* group = this->searchGroup(groupName);
    if (group == nullptr)
        return false;
    int is_twoness = group->searchTwoness();
    while(is_twoness != -1){
        group->expell(is_twoness);
        is_twoness = group->searchTwoness();
    }
    return true;
}

bool Deanery::writeToFile(){
    std::ofstream fout(("D:/qt-proj/lab/out.txt"));
    if (!fout.is_open()){
        return false;
    }
    for(auto i: this->groups){
        fout<<i.title<<std::endl;
        fout<<"average mark in group: ";
        fout<<i.average()<<std::endl;
        for(auto j: i.students){
            fout<<"id: ";
            fout<<j->id;
            fout<<" fio: ";
            fout<<j->fio;
            fout<<" average mark: ";
            fout<<j->average()<<std::endl;
        }
        fout<<std::endl;
    }
    fout.close();
    return true;
}
