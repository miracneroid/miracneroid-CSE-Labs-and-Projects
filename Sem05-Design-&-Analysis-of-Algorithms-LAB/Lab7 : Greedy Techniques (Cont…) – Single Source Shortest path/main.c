#include <stdio.h>
#include <limits.h>

#define MAX 100

int minDistance(int dist[], int visited[], int V) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v], min_index = v;
        }
    }
    return min_index;
}

void printPath(int parent[], int j) {
    if (parent[j] == -1)
        return;
    printPath(parent, parent[j]);
    printf("->%d", j + 1);
}

void printSolution(int dist[], int parent[], int V, int src) {
    printf("Source Destination Cost Path\n");
    for (int i = 0; i < V; i++) {
        printf("%d\t%d\t%d\t", src + 1, i + 1, dist[i]);
        if (dist[i] == 0) {
            printf("-\n");
        } else {
            printf("%d", src + 1);
            printPath(parent, i);
            printf("\n");
        }
    }
}

void dijkstra(int graph[MAX][MAX], int V, int src) {
    int dist[V];
    int visited[V];
    int parent[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
        parent[i] = -1;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited, V);
        visited[u] = 1;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    printSolution(dist, parent, V, src);
}

int main() {
    int V, src;
    int graph[MAX][MAX];

    FILE *file = fopen("inDiAdjMat1.dat", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return -1;
    }

    printf("Enter the Number of Vertices: ");
    scanf("%d", &V);

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            fscanf(file, "%d", &graph[i][j]);
        }
    }
    fclose(file);

    printf("Enter the Source Vertex: ");
    scanf("%d", &src);
    src--;

    dijkstra(graph, V, src);

    return 0;
}
