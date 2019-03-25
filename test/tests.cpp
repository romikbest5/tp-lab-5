#include "gtest/gtest.h"

#include "dean.h"

TEST(,test1)
{
    Deanery Fimikn;
    Fimikn.make_students_list_from_file("../src/students.txt");
    Fimikn.make_group_fromfile("../src/groups.txt");
    Fimikn.add_random_mark();
    Fimikn.choose_head();
    Fimikn.student_transfer(6,"Bi");
    EXPECT_EQ( COMPLETED, Fimikn.getState());
}
