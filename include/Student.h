#include <utility>

#include <vector>
#include <set>
#include <string>
#include <map>

struct FULLNAME{

    std::string firstName, secondName, patronymic;

    std::string getString(){
        std::string ans = firstName;
        return ans.append(" ").append(secondName).append(" ").append(patronymic);
    }

    explicit FULLNAME (std::string name){
        firstName = std::move(name);
    }

    FULLNAME (){
        firstName = "";
        secondName = "";
        patronymic = "";
    }

};

struct MARK{
    std::string subject;
    int val;
};

class Marks{

public:
    std::map<std::string, int> subject;
    double GPA = 0;

    void add (MARK mark){
        subject[mark.subject] = mark.val;
        GPA = (GPA * (subject.size() - 1) + mark.val)/(double)subject.size();
    }

    double getGPA (){
        return GPA;
    }

    int getCountOfSubjects (){
        return static_cast<int>(subject.size());
    }

};

class Group;

class Student{

public:

    int id;
    FULLNAME fullName;
    Group * group;
    double GPA;
    Marks marks;

    Student (FULLNAME fullName, int id);

    void changeGroup (Group * group);

    void addMark (MARK &mark);

    double getGPA ();

};