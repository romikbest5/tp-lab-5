#include "lab5_lib.h"

/////////////////////////////////////////////////class Student methods
Student::Student(int _id, string _fio){
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
  for (int i=0; i < marks.size(); i++){
    p_average+=marks[i];
  }
  p_average=p_average/marks.size();
  return int(p_average*100+0.5)/100.00;
}
/////////////////////////////////////////////////

/////////////////////////////////////////////////class Group methods
Group::Group(string _title){
  title=_title;
}

void Group::add_student(Student *student){
  students.push_back(student);
}

Student * Group::elect_head(){
  if (students.size()>0) {
    if (students.size() > 1) {
      int _head=rand()%students.size();
      head=students[_head];
      return head;
    }
    else head=students[0];
    return head;
  }
  else return NULL;
}

Student * Group::search_student(int _id){
  for (int i =0; i < students.size(); i++) {
    if (students[i]->id==_id) return students[i];
  }
}

double Group::group_average(){
  double g_average = 0;
  for (int i = 0; i < students.size(); i++) {
    g_average+=students[i].personal_average();
  }
  g_average=g_average/students.size();
  return int(g_average/100+0.5)/100.00;
}

void Group::expell(Student *expelled){

}
