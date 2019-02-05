//
// Created by iamilyasedunov on 26.01.19.
//
#include <QString>
#include <string>
#include <fstream>
//class Student;
#include "Group.h"

const int NUM_MARKS = 10;

class Student {
private:
    int id;
    std::string fio;
    //Group &group;
    int marks[NUM_MARKS];
    int num = NUM_MARKS;

public:
    Student(int id, std::string fio){
        this->id = id;              // != 30, 60, 90 там пробелы
        this->fio = fio;
        //Group* tmp = new Group();

    }
    void readMarks(){ //
        std::ifstream input_file("D:/qt-proj/lab/marks.txt");
        int numstr = this->id - 1;
        std::string line;
        if (input_file.is_open()){
            while(getline(input_file, line)){
                if(numstr==0){
                    //std::cout<<line<<std::endl;
                    break;
                }
                numstr--;
             }
        }else{
            std::cout<<"err";
        }
        //const char* strToCh = line.c_str();
        int index = 0;
        for(int i = 0;i < NUM_MARKS*2; i++){
            if(i % 2 == 0)
                this->marks[index++] = atoi(&line[i]);
        }
    }

    void readFio(){
        std::ifstream input_file("D:/qt-proj/lab/students.txt");
        int numstr = this->id - 1;
        std::string line;
        if (input_file.is_open()){
            while(getline(input_file, line)){
                if(numstr==0){
                    //std::cout<<line<<std::endl;
                    this->fio = line;
                    break;
                }
                numstr--;
             }
        }else{
            std::cout<<"err";
        }

    }

    void getInfo(){
        std::cout<<"id   : "<<this->id<<std::endl;
        std::cout<<"fio  : "<<this->fio<<std::endl;
        std::cout<<"marks: ";
        for(int x: this->marks) std::cout<<x<<" ";
        std::cout<<std::endl<<"num  : "<<num<<std::endl;
    }

    void read()
    {
        std::string line;

        std::ifstream in("D:/qt-proj/lab/students.txt"); // окрываем файл для чтения
        if (in.is_open()){
            while (getline(in, line)){
                std::cout << line << std::endl;
            }
         }
        else{
            std::cout << "Err" << std::endl;

        }

        in.close();     // закрываем файл
     }

};
