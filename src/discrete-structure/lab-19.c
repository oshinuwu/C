#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

// Function to read the adjacency matrix for an undirected graph
void readAdjacencyMatrix(int adjMat[MAX_VERTICES][MAX_VERTICES], int n)
{
    char reply;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        { // Only check upper triangle
            printf("Are vertices %d and %d adjacent? (Y/N): ", i, j);
            fflush(stdin);
            scanf(" %c", &reply);
            adjMat[i][j] = (reply == 'Y' || reply == 'y') ? 1 : 0;
            adjMat[j][i] = adjMat[i][j]; // Symmetric for undirected graph
        }
    }
}

// Function to read the adjacency matrix for a directed graph
void readAdjacencyMatrixDirected(int adjMat[MAX_VERTICES][MAX_VERTICES], int n)
{
    char reply;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i != j) // No self-loops for directed edges
            {
                printf("Is there a directed edge from vertex %d to vertex %d? (Y/N): ", i, j);
                fflush(stdin);
                scanf(" %c", &reply);
                adjMat[i][j] = (reply == 'Y' || reply == 'y') ? 1 : 0;
            }
            else
            {
                adjMat[i][j] = 0; // No self-loop
            }
        }
    }
}

// Function to display the adjacency matrix
void displayAdjacencyMatrix(int adjMat[MAX_VERTICES][MAX_VERTICES], int n)
{
    printf("\nAdjacency Matrix:\n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%d ", adjMat[i][j]);
        }
        printf("\n");
    }
}

// Function to calculate and display the incidence matrix
void displayIncidenceMatrix(int adjMat[MAX_VERTICES][MAX_VERTICES], int n)
{
    int edgeCount = 0;
    // Count the edges
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (adjMat[i][j] == 1)
            {
                edgeCount++;
            }
        }
    }

    int incMat[MAX_VERTICES][MAX_VERTICES] = {0}; // Initialize incidence matrix to 0
    int edgeIndex = 0;

    // Fill the incidence matrix
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (adjMat[i][j] == 1)
            {
                incMat[i][edgeIndex] = 1; // Start vertex
                incMat[j][edgeIndex] = 0; // End vertex (not counted)
                edgeIndex++;
            }
        }
    }

    printf("\nIncidence Matrix:\n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < edgeCount; j++)
        {
            printf("%d ", incMat[i][j]);
        }
        printf("\n");
    }
}

// Function for undirected graph
void undirected()
{
    int n, adjMat[MAX_VERTICES][MAX_VERTICES] = {0};
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    readAdjacencyMatrix(adjMat, n);
    displayAdjacencyMatrix(adjMat, n);
    displayIncidenceMatrix(adjMat, n);
}

// Function for directed graph
void directed()
{
    int n, adjMat[MAX_VERTICES][MAX_VERTICES] = {0};
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    readAdjacencyMatrixDirected(adjMat, n);
    displayAdjacencyMatrix(adjMat, n);
    displayIncidenceMatrix(adjMat, n);
}

int main()
{
    int option;
    printf("Select an option:\n");
    printf("1. Directed Graph\n");
    printf("2. Undirected Graph\n");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
        directed();
        break;
    case 2:
        undirected();
        break;
    default:
        printf("Invalid option\n");
    }

    printf("\nName: Oshin Pant Roll No: 23 Lab No: 19");
    getch(); 
    return 0;
}
