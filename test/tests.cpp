#include "gtest/gtest.h"
#include "lab5_lib.h"

TEST(lab5, test1){
  Student student(1, "Foo Bar");
  for (int i = 0; i < 5; i++){
    student.add_mark(5);
  }
  double average = 5.0;
  EXPECT_EQ(average, student.personal_average());
}

TEST(lab5, test2){
  Student * student = new Student(1, "Foo Bar");
  Group group("a_group");
  group.add_student(student);
  EXPECT_EQ(student, group.elect_head());
}

TEST(lab5, test3){
  Group group("a_group");
  EXPECT_EQ(nullptr, group.elect_head());
}

TEST(lab5, test4){
  Student * student = new Student(1, "Foo Bar");
  Group group("a_group");
  group.add_student(student);
  EXPECT_EQ(student, group.search_student(1));
}

TEST(lab5, test5){
  Student * student = new Student(1, "Foo Bar");
  Group group("a_group");
  group.add_student(student);
  EXPECT_EQ(nullptr, group.search_student(2));
}

TEST(lab5, test6){
  Student * student = new Student(1, "Foo Bar");
  for (int i = 0; i < 5; i++){
    student.add_mark(5);
  }
  Group group("a_group");
  group.add_student(student);
  double average = 5.0;
  EXPECT_EQ(average, group.group_average());
}

TEST(lab5, test7){
  Student * student = new Student(1, "Foo Bar");
  Group group("a_group");
  group.add_student(student);
  EXPECT_EQ(true, group.expell(student));
}

TEST(lab5, test8){
  Student * student = new Student(1, "Foo Bar");
  Group group("a_group");
  EXPECT_EQ(false, group.expell(student));
}

TEST(lab5, test9){
  Group * agroup = new Group("a_group");
  Deanery dean(agroup);
  EXPECT_EQ(agroup, dean.findGroup("a_group"));
}

TEST(lab5, test10){
  Group * agroup = new Group("a_group");
  Deanery dean(agroup);
  EXPECT_EQ(nullptr, dean.findGroup("foo"));
}

TEST(lab5, test11){
  Student * student1 = new Student(1, "Foo Bar");
  Group * group1 = new Group("group1");
  Group * group2 = new Group("group2");
  group1->add_student(student1);
  Deanery dean(group1);
  dean.groups.push_back(group2);
  dean.students.push_back(student1);
  EXPECT_EQ(true, dean.transfer("Foo Bar", "group2"));
}

TEST(lab5, test12){
  Group * group1 = new Group("group1");
  Deanery dean(group1);
  unsigned int exp = 0;
  EXPECT_EQ(exp, dean.expell_unsuccesfull(1));
}

TEST(lab5, test13){
  Group * group1 = new Group("group1");
  Deanery dean(group1);
  EXPECT_EQ(false, dean.update_files("abc"));
}
