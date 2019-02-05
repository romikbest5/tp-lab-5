class Group{

public:
    std::string title;
    std::set<Student *> students;
    std::map<int, Student *> positionById;
    std::map<std::string, std::set<Student *>> positionByFullName;
    int num;
    Student * head;

    explicit Group (std::string &title);

    void addStudent (Student * student);

    Student * choiceHead ();

    std::set<Student *> getStudent (FULLNAME fullName);

    Student * getStudent (int id);

    double getGPA ();

    void excludeStudent (Student *);

};