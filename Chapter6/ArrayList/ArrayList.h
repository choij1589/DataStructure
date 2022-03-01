//
// Created by Jin Choi on 2022/01/30.
//

#ifndef ARRAYLIST_ARRAYLIST_H
#define ARRAYLIST_ARRAYLIST_H

#include <cstdio>
#include <cstdlib>
#define MAX_LIST_SIZE   100

class ArrayList {
    int data[MAX_LIST_SIZE];
    unsigned int length;
public:
    ArrayList() { length = 0; }
    void insert(int pos, int e) {
        if (!isFull() && 0 <= pos && pos <= length) {
            for (int i = length; i > pos; i--)
                data[i] = data[i-1];
            data[pos] = e;
            length++;
        }
        else {
            printf("List is full or wrong position");
            exit(EXIT_FAILURE);
        }
    }
    void remove(int pos) {
        if (!isEmpty() && 0<=pos && pos < length) {
            for (int i = pos+1; i < length; i++)
                data[i-1] = data[i];
            length--;
        }
        else {
            printf("List is empty or wrong position");
            exit(EXIT_FAILURE);
        }
    }
    int getEntry(int pos) { return data[pos]; }
    bool isEmpty() { return length == 0; }
    bool isFull() { return length == MAX_LIST_SIZE; }
    bool find(int item) {
        for (int i = 0; i < length; i++)
            if (data[i] == item ) return true;
        return false;
    }
    void replace(int pos, int e) { data[pos] = e; }
    int size() { return length; }
    void display() {
        printf("[배열로 구현한 리스트 전체 항목 수 = %2d] : ", size());
        for(int i = 0; i < size(); i++)
            printf("[%2d] ", data[i]);
        printf("\n");
    }
    void clear() { length = 0; }
};

#endif //ARRAYLIST_ARRAYLIST_H
