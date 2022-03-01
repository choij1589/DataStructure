//
// Created by Jin Choi on 2022/01/22.
//

#ifndef LINKEDLIST_STUDENTNODE_H
#define LINKEDLIST_STUDENTNODE_H

#include "Student.h"
class StudentNode: public Student {
    StudentNode* link;
public:
    StudentNode(int id=0, char* name="", char* dept="")
        : Student(id, name, dept) { link = nullptr; }
    ~StudentNode() {}
    StudentNode* getLink() { return link; }
    void SetLink(StudentNode *p) { link = p; }
};

#endif //LINKEDLIST_STUDENTNODE_H
