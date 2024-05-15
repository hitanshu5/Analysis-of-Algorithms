#include <stdio.h>
#include <limits.h>

#define V 6

int min(int dist[], int sptset[]) {
    int min = INT_MAX, min_index;
    for (int i = 0; i < V; i++) {
        if (sptset[i] == 0 && dist[i] < min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

void print_sol(int dist[]) {
    for (int i = 0; i < V; i++) {
        printf("%d \t\t %d\n", i + 1, dist[i]);
    }
}

void dijkstra(int graph[V][V], int src) {
    int dist[V], sptset[V];
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptset[i] = 0;
    }
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++) {
        int u = min(dist, sptset);
        sptset[u] = 1;
        for (int k = 0; k < V; k++) {
            if (!sptset[k] && graph[u][k] && dist[u] != INT_MAX && dist[u] + graph[u][k] < dist[k]) {
                dist[k] = dist[u] + graph[u][k];
            }
        }
    }
    print_sol(dist);
}

void main() {
    int graph[V][V] = {
        {0, 4, 0, 0, 0, 0},
        {4, 0, 8, 0, 0, 0},
        {0, 8, 0, 7, 0, 4},
        {0, 0, 7, 0, 9, 14},
        {0, 0, 0, 9, 0, 10},
        {0, 0, 4, 14, 10, 0}
    };
    dijkstra(graph, 0);
}
