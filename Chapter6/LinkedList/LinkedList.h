//
// Created by Jin Choi on 2022/01/30.
//

#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

#include "Node.h"
class LinkedList {
    Node org;   // head node
public:
    LinkedList(): org(0) {}
    ~LinkedList() { clear(); }
    void clear() {
        while(!isEmpty())
            delete remove(0);
    }
    Node* getHead() { return org.getLink(); }
    bool isEmpty() { return getHead() == nullptr; }

    Node* getEntry(int pos) {
        Node* n = &org;
        for(int i = -1; i < pos; i++, n=n->getLink())
            if (n == nullptr)
                break;
        return n;
    }
    void insert(int pos, Node* n) {
        Node* prev = getEntry(pos-1);
        if (prev != nullptr)
            prev->insertNext(n);
    }

};
#endif //LINKEDLIST_LINKEDLIST_H
