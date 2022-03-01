//
// Created by Jin Choi on 2022/01/22.
//

#ifndef LINKEDLIST_STUDENT_H
#define LINKEDLIST_STUDENT_H

#include <cstdio>
#include <cstdlib>
#include <cstring>
const unsigned int MAX_STRING = 100;

class Student {
private:
    int id;
    char name[MAX_STRING];
    char dept[MAX_STRING];
public:
    Student(int i=0, char* n="", char* d="") { set(i, n, d); }
    void set(int i, char* n, char* d) { id = i; strcpy(name, n); strcpy(dept, d); }
    void display() {
        printf(" 학번:%-15d 성명:%-10s 학과:%-20s\n", id, name, dept);
    }

};

#endif //LINKEDLIST_STUDENT_H
