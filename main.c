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

/* Function declarations */
void generateGraph(Edge edges[]);
void printGraph(const Edge edges[]);

void initializeFloyd(
    const Edge edges[],
    int dist[VERTICES][VERTICES],
    int next[VERTICES][VERTICES]
);

void floydWarshall(
    int dist[VERTICES][VERTICES],
    int next[VERTICES][VERTICES]
);

void printAllShortestPaths(
    int dist[VERTICES][VERTICES],
    int next[VERTICES][VERTICES]
);

int verifyGraph(
    const int graph[VERTICES][VERTICES],
    int dist[VERTICES][VERTICES]
);

int verifyAllShortestPaths(
    const int graph[VERTICES][VERTICES],
    int dist[VERTICES][VERTICES],
    int next[VERTICES][VERTICES]
);

int main(void) {
    Edge edges[EDGES];

    int dist[VERTICES][VERTICES];
    int next[VERTICES][VERTICES];
    int graph[VERTICES][VERTICES] = {0};

    srand((unsigned int)time(NULL));

    /* Step 1: Generate the graph */
    generateGraph(edges);

    /* Step 2: Build the graph matrix for verification */
    for (int i = 0; i < EDGES; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].weight;

        graph[u][v] = w;
        graph[v][u] = w;
    }

    /* Step 3: Print the graph */
    printGraph(edges);

    /* Step 4: Initialize distance and next matrices */
    initializeFloyd(edges, dist, next);

    /* Step 5: Calculate all-pairs shortest paths */
    floydWarshall(dist, next);

    /* Step 6: Print all 45 shortest paths */
    printAllShortestPaths(dist, next);

    //7
        /* Step 7: Verify the graph */
    verifyGraph(graph, dist);

    /* Step 8: Verify all shortest paths */
    verifyAllShortestPaths(graph, dist, next);
    return 0;
}
