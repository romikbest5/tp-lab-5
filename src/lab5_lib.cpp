#include "lab5_lib.h"

/////////////////////////////////////////////////class Student methods
Student::Student(int _id, std::string _fio){
  id = _id;
  fio = _fio;
}

void Student::add_to_group(Group *add_here){
  group = add_here;
}

void Student::add_mark(int _mark){
  marks.push_back(_mark);
}

double Student::personal_average(){
  double p_average = 0;
  for (unsigned int i=0; i < marks.size(); i++){
    p_average+=marks[i];
  }
  p_average=p_average/marks.size();
  return int(p_average*100+0.5)/100.00;
}
/////////////////////////////////////////////////

/////////////////////////////////////////////////class Group methods
Group::Group(std::string _title){
  title=_title;
}

void Group::add_student(Student *student){
  students.push_back(student);
  student->add_to_group(this);
}

Student * Group::elect_head(){
  if (students.size()>0) {
    if (students.size() > 1) {
      int _head=rand()%students.size();
      head=students[_head];
      std::cout << "new head of " << title << " is " << head->fio << "\n";
      return head;
    }
    else head=students[0];
    return head;
  }
  else return nullptr;
}

Student * Group::search_student(int _id){
  for (unsigned int i =0; i < students.size(); i++) {
    if (students[i]->id==_id) return students[i];
  }
  return nullptr;
}

double Group::group_average(){
  double g_average = 0;
  for (unsigned int i = 0; i < students.size(); i++) {
    g_average+=students[i]->personal_average();
  }
  g_average=g_average/students.size();
  //std::cout << " (" << g_average << ") ";
  return int(g_average*100+0.5)/100.00;
}

bool Group::expell(Student *expelled){
  if (expelled->group==this){
    for (unsigned int i = 0; i < students.size(); i++){
      if (students[i]==expelled){
        expelled->group=nullptr;
        students.erase(students.begin()+i);
        if (expelled==head) elect_head();
        std::cout << expelled->fio << " was expelled from " << title << "\n";
        return true;
      }
    }
  }
  std::cout << expelled->fio << "is not a member of " << title << "\n";
  return false;
}
/////////////////////////////////////////////////

/////////////////////////////////////////////////class Deanery methods
Deanery::Deanery(Group * _group){
  groups.push_back(_group);
}

Deanery::Deanery(std::string _path){
  std::ifstream fin(_path);
  int id = 1;
  if (!fin.is_open()) {
    std::cout << "error open\n";
    return;
  }
  std::string buf;
  Group *new_group;
  Student *new_student;
  while (getline(fin, buf)){
    if (buf.find("group")!=buf.npos){
      buf.erase(0, 6);
      new_group = new Group(buf);
      groups.push_back(new_group);
    }
    else {
      new_student = new Student(id++, buf);
      students.push_back(new_student);
      new_group->add_student(new_student);
    }
  }
  fin.close();
  start_elections();
  }

void Deanery::console_output(){
  std::cout << "by groups:\n";
  for (unsigned int i = 0; i < groups.size(); i++){
    std::cout << groups[i]->title << ", head: ";
    std::cout << groups[i]->head->id << ")" << groups[i]->head->fio << "\n";
    for (unsigned int j= 0;j < groups[i]->students.size(); j++){
      std::cout << groups[i]->students[j]->id << ". ";
      std::cout << groups[i]->students[j]->fio << " ";
      std::cout << "with marks: ";
      //std::cout << groups[i]->students[j]->marks.size();
      for (unsigned int k = 0; k < groups[i]->students[j]->marks.size(); k++){
        //std::cout << i << j << k << " ";
        std::cout << groups[i]->students[j]->marks[k] << " ";
        //if (k!=groups[i]->students[j]->marks.size()-1){
        //  std::cout << ", ";
        //}
        //std::cout << "heh";
      }
      //std::cout << "average is " << groups[i]->students[j]->personal_average();
      std::cout << "\n";
      //std::cout << "in group " << groups[i]->students[j]->group->title << "\n";
    }
  }
  std::cout << "raw list of students:\n";
  for (unsigned int i = 0; i < students.size(); i++){
    std::cout << students[i]->id << ". ";
    std::cout << students[i]->fio << " ";
    std::cout << "with marks: ";
    for (unsigned int k = 0; k < students[i]->marks.size(); k++){
      std::cout << students[i]->marks[k] << " ";
    }
    std::cout << ", member of group " << students[i]->group->title;
    std::cout << "\n";
  }
  //for (unsigned int k; k < groups[0]->students[1]->marks.size(); k++){
  //  std::cout << groups[0]->students[1]->marks[k] << " ";
  //}
}

void Deanery::add_marks(int num){
  for (unsigned int i = 0; i < groups.size();i++){
    for (unsigned int j = 0; j < groups[i]->students.size(); j++){
      for (int k = 0; k < num; k++){
        groups[i]->students[j]->add_mark(rand()%4+2);
        //std::cout << "add " << groups[i]->students[j]->marks[k] << "\n";
      }
    }
  }
  /*for (unsigned int i = 0; i < groups.size();i++){
    for (unsigned int j = 0; j < groups[i]->students.size(); j++){
      for (int k = 0; k < num; k++){
        std::cout << groups[i]->students[j]->marks[k] << " ";
      }
      std::cout << "\n";
    }
  }*/
}

void Deanery::stats(){
  for (unsigned int i = 0; i < groups.size(); i++){
    std::cout << groups[i]->title;
    std::cout << " average is " << groups[i]->group_average() << "\n";
    std::cout << groups[i]->title;
    std::cout << " students' averages:\n";
    for (unsigned int j= 0;j < groups[i]->students.size(); j++){
      std::cout << groups[i]->students[j]->id << ")";
      std::cout << groups[i]->students[j]->fio << " ";
      std::cout << "average is " << groups[i]->students[j]->personal_average();
      std::cout << "\n";
    }
    std::cout << "\n";
  }
}

Group * Deanery::findGroup(std::string _title){
  for (unsigned int i = 0; i < groups.size(); i++){
    if (groups[i]->title==_title){
      return groups[i];
    }
  }
  std::cout << "no such group(find)\n";
  return nullptr;
}

bool Deanery::transfer(std::string transfered, std::string transfer_to){
  for (unsigned int i = 0; i < students.size(); i++){
    if (students[i]->fio==transfered){
      Group * _transfer_to = findGroup(transfer_to);
      if (_transfer_to==nullptr){
        //if (groups[2]->title==transfer_to) std::cout << "wtf\n";
        //std::cout << "no such group(transfer)\n";
        return false;
      }
      else {
        std::string transfered_from = students[i]->group->title;
        students[i]->group->expell(students[i]);
        _transfer_to->add_student(students[i]);
        std::cout << transfered << " was transefed from " << transfered_from << " to " << transfer_to << "\n";
        return true;
      }
    }
  }
  std::cout << "no such student\n";
  return false;
}

unsigned int Deanery::expell_unsuccesfull(double limit){
  unsigned int expelled_counter = 0;
  for (unsigned int i = 0; i < students.size(); i++){
    if (students[i]->personal_average()<limit) {
      expelled_counter++;
      students[i]->group->expell(students[i]);
      std::cout << students[i]->id << ")" << students[i]->fio << " was expelled from university\n";
      students.erase(students.begin()+i);
    }
  }
  return expelled_counter;
}

bool Deanery::update_files(std::string _path){
  std::ofstream fout(_path);
  if (!fout.is_open()) {
    std::cout << "error open\n";
    return false;
  }
  for (unsigned int i = 0; i < groups.size(); i++){
    fout << "group " << groups[i]->title << ", head: ";
    fout << groups[i]->head->id << ")" << groups[i]->head->fio << "\n";
    for (unsigned int j = 0; j < groups[i]->students.size(); j++){
      fout << groups[i]->students[j]->id << " " << groups[i]->students[j]->fio << " ";
      for (unsigned int k = 0; k < groups[i]->students[j]->marks.size(); k++){
        fout << groups[i]->students[j]->marks[k] << " ";
      }
      fout << "\n";
    }
  }
  fout.close();
  return true;
}

void Deanery::start_elections(){
  for (unsigned int i = 0; i < groups.size(); i++){
    groups[i]->elect_head();
  }
}
//for testing purposes:
void Deanery::pushgroup(Group * _group){
  groups.push_back(_group);
}

void Deanery::pushstudent(Student * _student){
  students.push_back(_student);
}
