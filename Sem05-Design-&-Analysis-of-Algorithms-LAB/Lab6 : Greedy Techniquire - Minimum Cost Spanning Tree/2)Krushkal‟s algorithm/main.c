 #include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Edge {
    int src, dest, weight;
};

struct Subset {
    int parent;
    int rank;
};

int compare(const void* a, const void* b) {
    struct Edge* edge1 = (struct Edge*)a;
    struct Edge* edge2 = (struct Edge*)b;
    return edge1->weight - edge2->weight;
}

int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(struct Subset subsets[], int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    if (subsets[rootX].rank < subsets[rootY].rank)
        subsets[rootX].parent = rootY;
    else if (subsets[rootX].rank > subsets[rootY].rank)
        subsets[rootY].parent = rootX;
    else {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}

void kruskalMST(struct Edge edges[], int n, int m) {
    struct Edge result[MAX];  
    int e = 0; 
    int i = 0;  
    int totalWeight = 0;

    qsort(edges, m, sizeof(struct Edge), compare);

    struct Subset* subsets = (struct Subset*)malloc(n * sizeof(struct Subset));

    for (int v = 0; v < n; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    
    while (e < n - 1 && i < m) {
        struct Edge nextEdge = edges[i++];

        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        if (x != y) {
            result[e++] = nextEdge;
            totalWeight += nextEdge.weight;
            Union(subsets, x, y);
        }
    }

    printf("Edge    Cost\n");
    for (i = 0; i < e; i++)
        printf("%d--%d    %d\n", result[i].src + 1, result[i].dest + 1, result[i].weight);

    printf("Total Weight of the Spanning Tree: %d\n", totalWeight);

    free(subsets);
}

int main() {
    int n, m;

    printf("Enter the number of nodes and edges: ");
    scanf("%d %d", &n, &m);

    struct Edge edges[MAX];

    printf("Enter the edges (node1 node2 weight):\n");
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        edges[i].src = u - 1;  
        edges[i].dest = v - 1;
        edges[i].weight = w;
    }

    kruskalMST(edges, n, m);

    return 0;
}
