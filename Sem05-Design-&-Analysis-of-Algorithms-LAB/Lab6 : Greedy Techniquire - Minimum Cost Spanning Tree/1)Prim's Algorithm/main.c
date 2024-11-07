#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 100

int minKey(int key[], bool mstSet[], int V) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void printMST(int parent[], int graph[MAX][MAX], int V) {
    printf("Cost Adjacency Matrix of the Minimum Spanning Tree:\n");
    int totalCost = 0;
    for (int i = 1; i < V; i++) {
        printf("%d - %d    %d\n", parent[i] + 1, i + 1, graph[i][parent[i]]);
        totalCost += graph[i][parent[i]];
    }
    printf("Total Weight of the Spanning Tree: %d\n", totalCost);
}

void primMST(int graph[MAX][MAX], int V, int startVertex) {
    int parent[MAX];  
    int key[MAX];     
    bool mstSet[MAX];   
 
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }
 
    key[startVertex] = 0;
    parent[startVertex] = -1; 
 
    for (int count = 0; count < V - 1; count++) {
        
        int u = minKey(key, mstSet, V);
 
        mstSet[u] = true;
 
        for (int v = 0; v < V; v++) {
            
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

   
    printMST(parent, graph, V);
}

int main() {
    FILE *file;
    int graph[MAX][MAX];
    int V, startVertex;

    
    file = fopen("inUnAdjMat.dat", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            fscanf(file, "%d", &graph[i][j]);
        }
    }

    fclose(file);

    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);
    startVertex--;  

    primMST(graph, V, startVertex);

    return 0;
}
