// dijkstras :

#include <stdio.h>
#define infinity 999

void dij(int n, int v, int cost[10][10], int dist[])
{

    int i, u, count, w, flag[10], min;

    for (i = 1; i <= n; i++)
    {

        flag[i] = 0;

        dist[i] = cost[v][i];
    }

    count = 2;

    while (count <= n)
    {

        min = infinity;

        for (w = 1; w <= n; w++)
        {

            if (dist[w] < min && !flag[w])
            {

                min = dist[w];

                u = w;
            }
        }

        flag[u] = 1;

        count++;

        for (w = 1; w <= n; w++)
        {

            if ((dist[u] + cost[u][w] < dist[w]) && !flag[w])
            {

                dist[w] = dist[u] + cost[u][w];
            }
        }
    }
}

int main()
{
    printf("Implementing Dijkstra's algorithm\n\n");

    int n, v, i, j, cost[10][10], dist[10];

    printf("\nEnter the number of nodes: ");

    scanf("%d", &n);

    printf("\nEnter the weights of edges (0 if there is no edge): \n");

    for (i = 1; i <= n; i++)
    {

        for (j = 1; j <= n; j++)

        {
            printf("\nSource : %d\tDestination : %d\t\tWeight of Edge : ", i, j);

            scanf("%d", &cost[i][j]);

            if (cost[i][j] == 0)
            {

                cost[i][j] = infinity;
            }
        }
    }

    printf("\nWhat is the source node: ");

    scanf("%d", &v);

    dij(n, v, cost, dist);

    printf("\nShortest Path from:\n");

    for (i = 1; i <= n; i++)
    {

        if (i != v)
        {

            printf("node %d to node %d = %d\n", v, i, dist[i]);
        }
    }

    printf("\n\nName : Oshin Pant  Roll no. : 23  Lab No:22");
    fflush(stdin);
	getchar();
    getchar();
    return 0;
}