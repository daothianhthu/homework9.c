
#include <stdio.h>

#define VERTICES 10
#define INF 1000000000

void printAllShortestPaths(
    int dist[VERTICES][VERTICES],
    int next[VERTICES][VERTICES]
) {
    int totalPairs = 0;

    printf("\n========== Shortest Paths ==========\n\n");

    for (int u = 0; u < VERTICES; u++) {
        for (int v = u + 1; v < VERTICES; v++) {
            printf("%d -> %d\n", u, v);
            printf("Path     : ");

            if (dist[u][v] == INF || next[u][v] == -1) {
                printf("No path\n");
                printf("Distance : INF\n\n");
                continue;
            }

            int current = u;
            int steps = 0;

            printf("%d", current);

            while (current != v && steps < VERTICES) {
                current = next[current][v];

                if (current == -1) {
                    break;
                }

                printf(" -> %d", current);
                steps++;
            }

            printf("\nDistance : %d\n\n", dist[u][v]);
            totalPairs++;
        }
    }

    printf("Total vertex pairs : %d\n", totalPairs);
}

int verifyAllShortestPaths(
    const int graph[VERTICES][VERTICES],
    int dist[VERTICES][VERTICES],
    int next[VERTICES][VERTICES]
) {
    int checkedPairs = 0;
    int errors = 0;

    printf("\n========== Verification ==========\n");

    for (int u = 0; u < VERTICES; u++) {
        for (int v = u + 1; v < VERTICES; v++) {
            int current = u;
            int totalWeight = 0;
            int steps = 0;
            int valid = 1;

            while (current != v) {
                int following = next[current][v];

                if (following < 0 || following >= VERTICES ||
                    graph[current][following] == 0 ||
                    steps >= VERTICES) {
                    valid = 0;
                    break;
                }

                totalWeight += graph[current][following];
                current = following;
                steps++;
            }

            if (!valid || totalWeight != dist[u][v]) {
                printf("FAIL: %d -> %d\n", u, v);
                errors++;
            } else {
                checkedPairs++;
            }
        }
    }

    printf("Valid paths : %d\n", checkedPairs);
    printf("Errors      : %d\n", errors);

    if (errors == 0 && checkedPairs == 45) {
        printf("Result      : ALL 45 PATHS PASSED\n");
        return 1;
    }

    printf("Result      : VERIFICATION FAILED\n");
    return 0;
}
#define EDGES 20
#define MAX_WEIGHT 100

int verifyGraph(
    const int graph[VERTICES][VERTICES],
    int dist[VERTICES][VERTICES]
) {
    int edgeCount = 0, selfLoop = 0, badWeight = 0, asymmetric = 0;

    for (int i = 0; i < VERTICES; i++) {
        for (int j = 0; j < VERTICES; j++) {
            if (i == j) {
                if (graph[i][j] != 0) selfLoop++;
                continue;
            }
            if (graph[i][j] != graph[j][i]) asymmetric++;

            if (j > i && graph[i][j] != 0) {      // mỗi cạnh chỉ đếm 1 lần
                edgeCount++;
                if (graph[i][j] < 1 || graph[i][j] > MAX_WEIGHT) badWeight++;
            }
        }
    }

    int connected = 1;
    for (int i = 0; i < VERTICES && connected; i++)
        for (int j = 0; j < VERTICES; j++)
            if (dist[i][j] >= INF) { connected = 0; break; }

    printf("\n========== Graph Verification ==========\n");
    printf("Vertices        : %d\n", VERTICES);
    printf("Edges           : %d (expected %d)\n", edgeCount, EDGES);
    printf("Self-loop       : %d\n", selfLoop);
    printf("Asymmetric      : %d\n", asymmetric);
    printf("Invalid weights : %d\n", badWeight);
    printf("Connected       : %s\n", connected ? "Yes" : "No");

    int ok = edgeCount == EDGES && !selfLoop && !asymmetric &&
             !badWeight && connected;
    printf("Result          : %s\n", ok ? "GRAPH VALID" : "GRAPH INVALID");
    return ok;
}