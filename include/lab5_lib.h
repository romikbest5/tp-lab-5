#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class Group;
class Deanery;

class Student{
  friend Group;
  friend Deanery;
private:
  int id;
  std::string fio;
  Group *group;
  std::vector<int> marks;
public:
  Student(int _id, std::string _fio);
  void add_to_group(Group *add_here);
  void add_mark(int _mark);
  double personal_average();
};

class Group{
friend Deanery;
private:
  std::string title;
  std::vector<Student*> students;
  Student *head;
public:
  Group(std::string _title);
  void add_student(Student *student);
  Student * elect_head();
  Student * search_student(int _id);
  double group_average();
  bool expell(Student *expelled);
};

class Deanery{
private:
  std::vector<Student*> students;
  std::vector<Group*> groups;
public:
  Deanery();
  Deanery(std::string _path);
  void console_output();
  void add_marks(int num);
  void stats();
  Group * findGroup(std::string _title);
  bool transfer(std:: string transfered, std::string transfer_to);
  unsigned int expell_unsuccesfull(double limit);
  bool update_files(std::string _path);
  void start_elections();
};
