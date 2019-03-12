 #include "Group.h"

Group::Group(std::string title) : title(title){}

void Group::addStudent(Student* student){
    this->students.push_back(student);
    student->inGroup(this);
    this->num++;
}

void Group::getInfo() {
    std::cout<<"====[GROUP: "<<this->title<<"]===="<<std::endl;
    std::cout<<"head: "<<this->head->fio<<std::endl;
    std::cout<<"number of students: "<<this->students.size()<<std::endl;
    std::cout<<"avearage mark in "<<this->title<<": "<<this->average()<<std::endl;
    for (auto x: this->students)
       std::cout<<"id: "<<x->id<<"| fio: "<<x->fio<<"     average mark: "<<x->average()<<std::endl;
    std::cout<<"====[/GROUP: "<<this->title<<"]===="<<std::endl<<std::endl;
}

void Group::election(){
    srand(time(nullptr));
    int index_head = rand() % int(students.size());
    this->head = students[index_head];
}

Student* Group::search(std::string fio, int id){
    for(auto x: this->students){
        if ((x->fio == fio)&&(x->id == id)) {
            return x;
        }
    }
    return nullptr;
}

Student* Group::search(std::string fio){
    for(auto x: this->students){
        if (x->fio == fio) {
            return x;
        }
    }
    return nullptr;
}

Student* Group::search(int id){
    for(auto x: this->students){
        if (x->id == id) {
            return x;
        }
    }
    return nullptr;
}

int Group::searchTwoness(){
    for(auto x: this->students){
        if (x->average() < PASS_GRADE) {
            return x->id;
        }
    }
    return -1;
}

int Group::average(){
    int sum = 0;
    for (auto x: this->students)
        sum+=x->average();
    return sum/int(this->students.size());
}

bool Group::expell(int id){
    Student* student = this->search(id);
    if (this->head == student){
        this->election();
    }

    if (student == nullptr)
        return false;
    auto pos = find(this->students.begin(), this->students.end(), student) - this->students.begin();
    this->students.erase(this->students.begin() + pos);
    return true;
}

bool Group::expell(std::string fio){
    Student* student = this->search(fio);
    if (student == nullptr)
        return false;
    auto pos = find(students.begin(), students.end(), student) - students.begin();
    students.erase(students.begin() + pos);
    return true;
}

