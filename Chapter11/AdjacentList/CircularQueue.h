//
// Created by Jin Choi on 2022/02/02.
//

#ifndef ADJACENTLIST_CIRCULARQUEUE_H
#define ADJACENTLIST_CIRCULARQUEUE_H

#include <cstdio>
#include <cstdlib>
#define MAX_QUEUE_SIZE  100

inline void error(char* message) {
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

class CircularQueue {
protected:
    int     front;
    int     rear;
    int     data[MAX_QUEUE_SIZE];
public:
    CircularQueue()     { front = rear = 0; }
    bool isEmpty()      { return front == rear; }
    bool isFull()       { return (rear+1)%MAX_QUEUE_SIZE == front; }
    void enqueue(int val) {
        if (isFull())
            error("[Error] 큐가 포화상태입니다\n");

        rear = (rear+1) % MAX_QUEUE_SIZE;
        data[rear] = val;
    }
    int dequeue() {
        if (isEmpty())
            error("[Error] 큐가 공백상태입니다\n");

        front = (front+1) % MAX_QUEUE_SIZE;
        return data[front];
    }
    int peek() {
        if (isEmpty())
            error("[Error] 큐가 공백상태입니다\n");

        return data[(front+1) % MAX_QUEUE_SIZE];
    }
    void display() {
        printf("큐 내용: ");
        int maxi = (front < rear) ? rear : rear+MAX_QUEUE_SIZE;
        for (int i = front+1; i <= maxi; i++)
            printf("[%2d] ", data[i%MAX_QUEUE_SIZE]);
        printf("\n");
    }
};

#endif //ADJACENTLIST_CIRCULARQUEUE_H
