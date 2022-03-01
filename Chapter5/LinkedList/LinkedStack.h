//
// Created by Jin Choi on 2022/01/22.
//

#ifndef LINKEDLIST_LINKEDSTACK_H
#define LINKEDLIST_LINKEDSTACK_H

#include "StudentNode.h"
class LinkedStack {
    StudentNode* top;
public:
    LinkedStack() { top = nullptr; }
    ~LinkedStack() { while(!isEmpty()) delete pop(); }

    bool isEmpty() { return top == nullptr; }
    void push(StudentNode* p) {
        if (isEmpty()) top = p;
        else {
            p->SetLink(top);
            top = p;
        }
    }
    StudentNode* pop() {
        if (isEmpty()) return nullptr;
        StudentNode *p = top;
        top = top->getLink();
        return p;
    }
    StudentNode* peek() { return top; }
    void display() {
        printf("[LinkedStack]\n");
        for (StudentNode* p = top; p != nullptr; p = p->getLink())
            p->display();
        printf("\n");
    }
};
#endif //LINKEDLIST_LINKEDSTACK_H
