
class Deanery{

public:
    int id = 0;
    std::set<Student *> students;
    std::vector<Group *> groups;

    void loadStudentsFromFile (std::string & fileName);

    void loadGroupFromFile (std::string & fileName, Group * group);

    void setMark (Student * student, MARK mark);

    void deductionStudentByCriteria (bool (* criteria)(Student *));

    std::set<Student *, bool (*)(Student *, Student *)> * getStatistics (Group * group);

    std::set<Student *, bool (*)(Student *, Student *)> * getStatistics ();

    void saveStatistics (std::string & fileName);

    void saveStatistics (std::string & fileName, Group * group);

    void printStatistics (std::set<Student *, bool (*)(Student *, Student *)> * st, std::ostream * cout);

    void replaceStudent (Student * student, Group * from, Group * to);

    void deductionStudent (Student *);

    void saveData (std::string & fileName);

    void printData (std::ostream * print);

    void choiceHead (Group *);

    Group * createGroup (std::string title);

};