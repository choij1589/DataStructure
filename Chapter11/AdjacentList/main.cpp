//#include "SrchALGraph.h"
#include "TopoSortGraph.h"

int main() {
    /*
    SrchALGraph g;

    for (int i = 0; i < 4; i++)
        g.insertVertex('A'+i);
    g.insertEdge(0, 1);
    g.insertEdge(0, 3);
    g.insertEdge(1, 2);
    g.insertEdge(1, 3);
    g.insertEdge(2, 3);
    printf("인접 리스트로 표현한 그래프\n");
    g.display();

    printf("DFS ==> ");
    g.resetVisited();
    g.DFS(0);
    printf("\n");

    printf("BFS ==> ");
    g.resetVisited();
    g.BFS(0);
    printf("\n");
    */
    TopoSortGraph tg;
    for (int i = 0; i < 6; i++)
        tg.insertVertex('A'+i);
    tg.insertDirEdge(0, 2); tg.insertDirEdge(0, 3);
    tg.insertDirEdge(1, 3); tg.insertDirEdge(1, 4);
    tg.insertDirEdge(2, 3); tg.insertDirEdge(2, 5);
    tg.insertDirEdge(3, 5); tg.insertDirEdge(4, 5);
    printf("Topology Sort:\n");
    tg.TopoSort();

    return 0;
}