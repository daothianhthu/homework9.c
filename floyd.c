
#define VERTICES 10
#define INF 1000000000

typedef struct {
    int u;
    int v;
    int weight;
} Edge;

void initializeFloyd(
    const Edge edges[],
    int dist[VERTICES][VERTICES],
    int next[VERTICES][VERTICES]
) {
    // Initialize distance and next matrices.
    for (int i = 0; i < VERTICES; i++) {
        for (int j = 0; j < VERTICES; j++) {
            if (i == j) {
                dist[i][j] = 0;
                next[i][j] = i;
            } else {
                dist[i][j] = INF;
                next[i][j] = -1;
            }
        }
    }

    // Insert all undirected edges.
    for (int i = 0; i < 20; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].weight;

        dist[u][v] = w;
        dist[v][u] = w;

        next[u][v] = v;
        next[v][u] = u;
    }
}

void floydWarshall(
    int dist[VERTICES][VERTICES],
    int next[VERTICES][VERTICES]
) {
    for (int k = 0; k < VERTICES; k++) {
        for (int i = 0; i < VERTICES; i++) {
            for (int j = 0; j < VERTICES; j++) {
                if (dist[i][k] == INF ||
                    dist[k][j] == INF) {
                    continue;
                }

                int newDistance =
                    dist[i][k] + dist[k][j];

                if (newDistance < dist[i][j]) {
                    dist[i][j] = newDistance;
                    next[i][j] = next[i][k];
                }
            }
        }
    }
}
