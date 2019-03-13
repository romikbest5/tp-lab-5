#include "gtest/gtest.h"
#include "Header.h"

//tests for class Student
TEST(Student, Student_addMark) 
{
	Student A(1, "Polina Smolnikova");
	A.addMark(5);
	A.addMark(10);
	A.addMark(6);
	EXPECT_EQ(7, A.average());
}

TEST(Student, Student_enrollment)
{
	Group B("PMI");
	Student A(1, "Polina Smolnikova");
	EXPECT_EQ("PMI", A.enrollment(B));
}
//tests for class Group
TEST(Group, Group_groupAverage) 
{
	Student A(1, "Polina Smolnikova");
	Student B(2, "Lubov Grinenko");
	Group C("PMI");
	A.enrollment(C);
	B.enrollment(C);
	A.addMark(10);
	B.addMark(6);
	EXPECT_EQ(8, C.groupAverage());
}
TEST(Group, Group_choise_head)
{
	Student A(1, "Polina Smolnikova");
	Student B(2, "Lubov Grinenko");
	Group C("PMI");
	A.enrollment(C);
	B.enrollment(C);
	EXPECT_EQ("Polina Smolnikova",C.choiseHead(&A));
}
TEST(Group, Group_search)
{
	Student B(2, "Lubov Grinenko");
	Group C("PMI");
	B.enrollment(C);
	EXPECT_EQ(0, C.elimination(&B));
}
//tests for class Deanery
TEST(Deanery, Deanery_replace)
{
	Deanery IMIKN;
	EXPECT_EQ("15PMI",IMIKN.replace(*IMIKN.students[0], *IMIKN.groups[2]));
}