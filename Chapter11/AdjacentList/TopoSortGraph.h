//
// Created by Jin Choi on 2022/02/02.
//

#ifndef ADJACENTLIST_TOPOSORTGRAPH_H
#define ADJACENTLIST_TOPOSORTGRAPH_H

#include "AdjListGraph.h"
#include "ArrayStack.h"

class TopoSortGraph: public AdjListGraph {
    int inDeg[MAX_VTXS];
public:
    void insertDirEdge(int u, int v) {
        adj[u] = new Node(v, adj[u]);
    }
    void TopoSort() {
        // initialize
        for (int i = 0; i < size; i++)
            inDeg[i] = 0;
        for (int i = 0; i < size; i++) {
            Node *node = adj[i];
            while( node != nullptr ) {
                inDeg[node->getId()]++;
                node = node->getLink();
            }
        }
        // 집입 순서가 0인 정점을 스택에 삽입
        ArrayStack s;
        for (int i = 0; i < size; i++)
            if (inDeg[i] == 0) s.push(i);

        // 위상 순서를 생성
        while (s.isEmpty() == false) {
            int w = s.pop();
            printf(" %c ", getVertex(w));
            Node *node = adj[w];
            while (node != nullptr) {
                int u = node->getId();
                inDeg[u]--;
                if (inDeg[u] == 0)
                    s.push(u);
                node = node->getLink();
            }
        }
        printf("\n");
    }
};



#endif //ADJACENTLIST_TOPOSORTGRAPH_H
