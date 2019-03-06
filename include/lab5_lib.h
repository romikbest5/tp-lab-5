#pragma once

#include <iostream>
#include <string>
#include <vector>

class Student{
private:
  int id;
  std::string fio;
  Group *group;
  std::vector<int> marks;
public:
  Student(int _id, string _fio);
  void add_to_group(Group *add_here);
  void add_mark(int _mark);
  double personal_average();
};

class Group{
private:
  std::string title;
  std::vector<Student*> students;
  Student *head;
public:
  Group(string _title);
  void add_student(Student *student);
  Student * elect_head();
  Student * search_student(int _id);
  double group_average();
  void expell(Student *expelled);
};

class Deanery{
private:
  std::vector<*Student> students;
  std::vector<*Group> groups;
public:
  void load_students(std::string _path);
  void load_groups(std::string _path);
  void add_marks(int num);
  void stats();
  void transfer(Student *transfered, Group *transfer_to);
  void expell_unsuccesfull(double limit);
  void update_files(string _path);
  void start_elections();
};
