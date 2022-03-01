#include "ConnectedComponentGraph.h"

int main() {
    SrchAMGraph g;
    g.load("graph.txt");
    printf("graph.txt");
    g.display();

    printf("DFS ==> ");
    g.resetVisited();
    g.DFS(0);
    printf("\n");

    printf("BFS ==> ");
    g.resetVisited();
    g.BFS(0);
    printf("\n");

    ConnectedComponentGraph cg;
    for(int i = 0; i < 5; i++)
        cg.insertVertex('A'+i);
    cg.insertEdge(1, 0);
    cg.insertEdge(2, 0);
    cg.insertEdge(3, 4);

    printf("연결 성분 테스트 그래프\n");
    cg.display();
    cg.resetVisited();
    cg.findConnectedComponent();

    return 0;
}
