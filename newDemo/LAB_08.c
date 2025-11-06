#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

int graph[MAX][MAX];
int dist[MAX];
int visited[MAX];
int parent[MAX];
int n;

// Function to find the vertex with the minimum distance
int minDistance()
{
    int min = INF, min_index = -1;
    for (int v = 1; v <= n; v++)
    {
        if (!visited[v] && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Dijkstra’s Algorithm
void dijkstra(int start)
{
    for (int i = 1; i <= n; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }

    dist[start] = 0;

    for (int count = 1; count <= n - 1; count++)
    {
        int u = minDistance();
        if (u == -1)
            break; // no more reachable nodes
        visited[u] = 1;

        for (int v = 1; v <= n; v++)
        {
            if (!visited[v] && graph[u][v] && dist[u] != INF &&
                dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    // Display the result
    printf("\nNode\tDistance from %d\tParent", start);
    for (int i = 1; i <= n; i++)
    {
        printf("\n%d\t", i);
        if (dist[i] == INF)
            printf("-1\t\t");
        else
            printf("%d\t\t", dist[i]);
        if (parent[i] == -1)
            printf("None");
        else
            printf("%d", parent[i]);
    }

    printf("\n\nShortest Path Tree (Edges):\n");
    for (int i = 1; i <= n; i++)
    {
        if (parent[i] != -1)
            printf("%d -> %d\n", parent[i], i);
    }
}

int main()
{
    int edges, u, v, w, start;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Initialize graph with 0
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            graph[i][j] = 0;

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v w):\n");
    for (int i = 0; i < edges; i++)
    {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; // Undirected
    }

    printf("Enter starting node: ");
    scanf("%d", &start);

    dijkstra(start);

    return 0;
}