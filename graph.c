
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define VERTICES 10
#define EDGES 20

typedef struct {
    int u;
    int v;
    int weight;
} Edge;

void generateGraph(Edge edges[]) {
    int used[VERTICES][VERTICES] = {0};
    int count = 0;

    /*
       First, create a random spanning tree.
       This guarantees that the graph is connected.
    */
    for (int v = 1; v < VERTICES; v++) {
        int u = rand() % v;
        int weight = rand() % 100 + 1;

        edges[count].u = u;
        edges[count].v = v;
        edges[count].weight = weight;

        used[u][v] = 1;
        used[v][u] = 1;
        count++;
    }

    /*
       Add random edges until there are exactly 20.
    */
    while (count < EDGES) {
        int u = rand() % VERTICES;
        int v = rand() % VERTICES;

        if (u == v || used[u][v]) {
            continue;
        }

        int weight = rand() % 100 + 1;

        edges[count].u = u;
        edges[count].v = v;
        edges[count].weight = weight;

        used[u][v] = 1;
        used[v][u] = 1;
        count++;
    }
}

void printGraph(const Edge edges[]) {
    printf("Graph\n");
    printf("Vertices : %d\n", VERTICES);
    printf("Edges    : %d\n\n", EDGES);
    printf("Edges\n");

    printf("%-15s %s\n", "Edge", "Weight");

    for (int i = 0; i < EDGES; i++) {
        printf("(%d, %d)          %d\n",
               edges[i].u,
               edges[i].v,
               edges[i].weight);
    }
}
