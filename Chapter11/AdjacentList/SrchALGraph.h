//
// Created by Jin Choi on 2022/02/02.
//

#ifndef ADJACENTLIST_SRCHALGRAPH_H
#define ADJACENTLIST_SRCHALGRAPH_H

#include "AdjListGraph.h"
#include "CircularQueue.h"

class SrchALGraph: public AdjListGraph {
private:
    bool visited[MAX_VTXS];
public:
    void resetVisited() {
        for (int i = 0; i < size; i++)
            visited[i] = false;
    }
    bool isLinked(int u, int v) {
        for (Node *p = adj[u]; p != nullptr; p = p->getLink())
            if (p->getId() == v) return true;
        return false;
    }
    void DFS(int v) {
        visited[v] = true;
        printf("%c ", getVertex(v));
        for (Node *p=adj[v]; p != nullptr; p = p->getLink())
            if (visited[p->getId()] == false)
                DFS(p->getId());
    }
    void BFS(int v) {
        visited[v] = true;
        printf("%c ", getVertex(v));

        CircularQueue que;
        que.enqueue(v);

        while (!que.isEmpty()) {
            int v = que.dequeue();
            for (Node* w =adj[v]; w != nullptr; w = w->getLink()) {
                int id = w->getId();
                if (!visited[id]) {
                    visited[id] = true;
                    printf("%c ", getVertex(id));
                    que.enqueue(id);
                }
            }
        }
    }
};

#endif //ADJACENTLIST_SRCHALGRAPH_H
