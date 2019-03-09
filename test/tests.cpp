#include "gtest/gtest.h"
#include "Methods.cpp"
#include <string>

TEST(student, methods1) {
	Student st(11, "F I O");
	EXPECT_EQ(11, st.getId());
	EXPECT_EQ("F I O", st.getFio());
}

TEST(student, methods2) {
	Student st(11, "F I O");
	st.addMark(5);
	st.addMark(4);
	vector<int> exp = { 5, 4 };
	EXPECT_EQ(exp, st.getMarks());
	EXPECT_EQ(4.5, st.averageMark());
}

TEST(group, methods1) {
	Student st1(11, "F I O");
	Student st2(12, "S A D");
	st1.addMark(5);
	st1.addMark(4);
	st2.addMark(3);
	st2.addMark(2);
	Group gr("PMI");
	gr.addStudent(&st1);
	gr.addStudent(&st2);
	EXPECT_EQ(3.5, gr.averageGroup());
}

TEST(group, methods2) {
	Student st1(11, "F I O");
	Student st2(12, "S A D");
	Group gr("PMI");
	gr.addStudent(&st1);
	gr.addStudent(&st2);
	EXPECT_EQ("S A D", gr.searchFio("S A D")->getFio());
}