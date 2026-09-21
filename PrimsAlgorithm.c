#include <stdio.h>
#define MAX 100
#define INF 99999
int main() {
    int n;
    int graph[MAX][MAX];
    int visited[MAX];
    int i, j;
    int edges = 0;
    int totalCost = 0;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    printf("(Enter 0 if there is no edge)\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0 && i != j)
                graph[i][j] = INF;
        }
    }
    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }
    visited[0] = 1;
    printf("\nEdges in Minimum Spanning Tree:\n");
    while (edges < n - 1) {
        int min = INF;
        int u = -1;
        int v = -1;
        for (i = 0; i < n; i++) {
            if (visited[i]) {
                for (j = 0; j < n; j++) {
                    if (!visited[j] && graph[i][j] < min) {
                        min = graph[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        if (u == -1 || v == -1) {
            printf("Graph is disconnected.\n");
            return 0;
        }
        printf("%d -- %d = %d\n", u, v, min);
        totalCost += min;
        visited[v] = 1;
        edges++;
    }
    printf("\nMinimum Cost = %d\n", totalCost);
    return 0;
}