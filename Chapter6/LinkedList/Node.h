//
// Created by Jin Choi on 2022/01/30.
//

#ifndef LINKEDLIST_NODE_H
#define LINKEDLIST_NODE_H

#include <cstdio>
#include <cstdlib>

class Node {
    Node* link;
    int data;
public:
    Node(int val=0): data(val), link(nullptr) {}
    Node* getLink() { return link; }
    void setLink(Node* next) { link = next; }
    void display() { printf("<%2d>", data); }
    bool hasData(int val) { return data == val; }
    void insertNext(Node* n) {
        if (n != nullptr) {
            n->link = link;
            link = n;
        }
    }
    Node* removeNext() {
        Node* removed = link;
        if (removed != nullptr)
            link = removed->link;
        return removed;
    }
};

#endif //LINKEDLIST_NODE_H
