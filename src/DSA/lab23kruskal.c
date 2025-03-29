#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Maximum number of edges and vertices

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Structure to represent a graph
struct Graph {
    int V, E;              // Number of vertices and edges
    struct Edge* edge;     // Array of edges
};

// Structure to represent a subset for Union-Find
struct Subset {
    int parent;
    int rank;
};

// Function to create a graph with V vertices and E edges
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge*)malloc(E * sizeof(struct Edge));
    return graph;
}

// Find function using path compression (Union-Find)
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

// Union function by rank
void unionByRank(struct Subset subsets[], int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    if (subsets[rootX].rank < subsets[rootY].rank) {
        subsets[rootX].parent = rootY;
    } else if (subsets[rootX].rank > subsets[rootY].rank) {
        subsets[rootY].parent = rootX;
    } else {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}

// Compare function for qsort to sort edges by weight
int compareEdges(const void* a, const void* b) {
    struct Edge* edge1 = (struct Edge*)a;
    struct Edge* edge2 = (struct Edge*)b;
    return edge1->weight - edge2->weight;
}

// Function to implement Kruskal's Algorithm
void kruskalMST(struct Graph* graph) {
    int V = graph->V;
    struct Edge result[MAX];  // Array to store the MST
    int e = 0;                // Index for result[]
    int i = 0;                // Index for sorted edges

    // Sort all edges in increasing order of weight
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), compareEdges);

    // Allocate memory for creating subsets
    struct Subset* subsets = (struct Subset*)malloc(V * sizeof(struct Subset));

    // Initialize subsets with single elements
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Process edges one by one
    while (e < V - 1 && i < graph->E) {
        // Pick the smallest edge
        struct Edge nextEdge = graph->edge[i++];
        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        // If including this edge doesn't cause a cycle, include it in the MST
        if (x != y) {
            result[e++] = nextEdge;
            unionByRank(subsets, x, y);
        }
    }

    // Print the resulting MST
    printf("Edges in the Minimum Spanning Tree:\n");
    int minCost = 0;
    for (i = 0; i < e; i++) {
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
        minCost += result[i].weight;
    }
    printf("Minimum Cost of the Spanning Tree: %d\n", minCost);

    free(subsets);
}

int main() {
    int V = 4;  // Number of vertices
    int E = 5;  // Number of edges
    struct Graph* graph = createGraph(V, E);

    // Adding edges: src, dest, weight
    graph->edge[0].src = 0; graph->edge[0].dest = 1; graph->edge[0].weight = 10;
    graph->edge[1].src = 0; graph->edge[1].dest = 2; graph->edge[1].weight = 6;
    graph->edge[2].src = 0; graph->edge[2].dest = 3; graph->edge[2].weight = 5;
    graph->edge[3].src = 1; graph->edge[3].dest = 3; graph->edge[3].weight = 15;
    graph->edge[4].src = 2; graph->edge[4].dest = 3; graph->edge[4].weight = 4;

    kruskalMST(graph);

    free(graph->edge);
    free(graph);
    return 0;
}

