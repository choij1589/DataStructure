//
// Created by Jin Choi on 2022/01/22.
//

#ifndef LINKEDQUEUE_NODE_H
#define LINKEDQUEUE_NODE_H

#include <cstdio>
class Node {
    Node* link;
    int data;
public:
    Node(int val=0): data(val), link(nullptr) {}
    Node* getLink()          { return link; }
    void setLink(Node* next) { link = next; }
    void display()           { printf(" <%d>", data); }
};

#endif //LINKEDQUEUE_NODE_H
