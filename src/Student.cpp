#include "Student.h"
#include "Group.h"

Student::Student(int id, std::string fio){
    this->id = id;
    this->fio = fio;
}

Student::Student(int id){
    this->id = id;
    readFio();
    readMarks();
}

void Student::readMarks(){ //
    std::ifstream input_file("D:/qt-proj/lab/marks.txt");
    int numstr = this->id - 1;
    std::string line;
    if (input_file.is_open()){
        while(getline(input_file, line)){
            if(numstr==0){
                break;
            }
            numstr--;
         }
    }else{
        std::cout<<"err";
    }
    for(int i = 0;i < NUM_MARKS*2; i++){
        if(i % 2 == 0)
            this->marks.push_back(atoi(&line[i]));
    }
    this->num+=NUM_MARKS;
}

void Student::readFio(){
    std::ifstream input_file("D:/qt-proj/lab/students.txt");
    int numstr = this->id - 1;
    std::string line;
    if (input_file.is_open()){
        while(getline(input_file, line)){
            if(numstr==0){
                this->fio = line;
                break;
            }
            numstr--;
         }
    }else{
        std::cout<<"err";
    }

}

void Student::readId(){
    std::ifstream input_file("D:/qt-proj/lab/students.txt");
    std::string line;
    int numstr = 0;
    if (input_file.is_open()){
        while(getline(input_file, line)){
            if(line == this->fio){
                //std::cout<<line<<std::endl;
                this->id = numstr;
                break;
            }
            numstr++;
         }
    }else{
        std::cout<<"err";
    }

}

void Student::getInfo(){
    std::cout<<"id      : "<<this->id<<std::endl;
    std::cout<<"fio     : "<<this->fio<<std::endl;
    std::cout<<"marks   : ";
    for(int x: this->marks) std::cout<<x<<" ";
    std::cout<<"average :"<<this->average()<<std::endl;
    std::cout<<"num      : "<<num<<std::endl;

}

void Student::inGroup(Group *group){
    this->group = group;
};

int Student::average(){
    int sum = 0;
    for(auto x: this->marks)
        sum += x;
    return (sum/this->num);
}
