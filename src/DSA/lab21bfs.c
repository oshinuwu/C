#include <stdio.h>
#include <stdbool.h>

#define V 6  // Number of vertices

// Queue for BFS
int queue[V], front = -1, rear = -1;

void enqueue(int v) {
    if (rear == V-1) return;
    if (front == -1) front = 0;
    queue[++rear] = v;
}

int dequeue() {
    if (front == -1) return -1;
    int v = queue[front++];
    if (front > rear) front = rear = -1;
    return v;
}

bool isEmpty() {
    return front == -1;
}

// Graph representation (adjacency matrix)
int graph[V][V] = {
    {0,1,1,0,0,0},
    {1,0,0,1,1,0},
    {1,0,0,0,1,0},
    {0,1,0,0,1,1},
    {0,1,1,1,0,1},
    {0,0,0,1,1,0}
};

// BFS implementation
void BFS(int start) {
    bool visited[V] = {false};
    printf("BFS: ");
    enqueue(start);
    visited[start] = true;

    while (!isEmpty()) {
        int v = dequeue();
        printf("%d ", v);

        for (int i = 0; i < V; i++) {
            if (graph[v][i] && !visited[i]) {
                enqueue(i);
                visited[i] = true;
            }
        }
    }
    printf("\n");
}

// DFS implementation
void DFS(int v, bool visited[]) {
    visited[v] = true;
    printf("%d ", v);

    for (int i = 0; i < V; i++) {
        if (graph[v][i] && !visited[i]) {
            DFS(i, visited);
        }
    }
}

int main() {
    printf("Traversals for the graph:\n");
    BFS(0);  // BFS starting from vertex 0

    bool visited[V] = {false};
    printf("DFS: ");
    DFS(0, visited);  // DFS starting from vertex 0
    printf("\n");

    printf("\nName:Oshin Pant Roll No:23 Lab No:21");
    fflush(stdin);
	getchar();
    getchar();
    return 0;
}