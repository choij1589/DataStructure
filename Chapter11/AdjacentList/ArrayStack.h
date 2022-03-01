//
// Created by Jin Choi on 2022/02/02.
//

#ifndef ADJACENTLIST_ARRAYSTACK_H
#define ADJACENTLIST_ARRAYSTACK_H

#include <cstdio>
#include <cstdlib>

const unsigned int MAX_STACK_SIZE = 20;

inline void error(char* message) {
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}
class ArrayStack {
    int top;
    int data[MAX_STACK_SIZE];
public:
    ArrayStack() { top = -1; }
    ~ArrayStack() {}
    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX_STACK_SIZE-1; }

    void push(int e) {
        if ( isFull() )
            error("[Error] 스택 포화 에러");
        data[++top] = e;
    }
    int pop() {
        if (isEmpty())
            error("[Error] 스택 공백 에러");
        return data[top--];
    }
    int peek() {
        if (isEmpty())
            error("[Error] 스택 공백 에러");
        return data[top];
    }
    void display() {
        printf("[스택 항목의 수: %2d] ==> ", top+1);
        for (int i = 0; i <= top; i++)
            printf("<%2d>", data[i]);
        printf("\n");
    }
};


#endif //ADJACENTLIST_ARRAYSTACK_H
