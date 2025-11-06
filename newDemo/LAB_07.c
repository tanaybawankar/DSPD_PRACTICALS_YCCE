#include <stdio.h>
#include <stdlib.h>

#define N 9

int graph[N + 1][N + 1];
int visited[N + 1];

// Function to add an edge between two nodes
void addEdge(int u, int v)
{
    graph[u][v] = 1;
    graph[v][u] = 1;
}

// Function to build a 3x3 grid graph (1–9)
void buildGridGraph()
{
    // Row connections
    addEdge(1, 2);
    addEdge(2, 3);

    addEdge(4, 5);
    addEdge(5, 6);

    addEdge(7, 8);
    addEdge(8, 9);

    // Column connections
    addEdge(1, 4);
    addEdge(4, 7);

    addEdge(2, 5);
    addEdge(5, 8);

    addEdge(3, 6);
    addEdge(6, 9);
}

// BFS traversal
void BFS(int start)
{
    int queue[N + 1], front = 0, rear = 0;

    for (int i = 1; i <= N; i++)
        visited[i] = 0;

    queue[rear++] = start;
    visited[start] = 1;

    printf("\nBFS Traversal: ");

    while (front < rear)
    {
        int node = queue[front++];
        printf("%d ", node);

        for (int i = 1; i <= N; i++)
        {
            if (graph[node][i] && !visited[i])
            {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

// DFS traversal
void DFS(int start)
{
    int stack[N + 1], top = -1;

    for (int i = 1; i <= N; i++)
        visited[i] = 0;

    stack[++top] = start;
    printf("\nDFS Traversal: ");

    while (top >= 0)
    {
        int node = stack[top--];

        if (!visited[node])
        {
            printf("%d ", node);
            visited[node] = 1;
        }

        // Push adjacent nodes in reverse order
        for (int i = N; i >= 1; i--)
        {
            if (graph[node][i] && !visited[i])
            {
                stack[++top] = i;
            }
        }
    }
    printf("\n");
}

// Main function
int main()
{
    buildGridGraph();
    printf("Graph: 3x3 Grid (Nodes 1–9)\n");
    printf("Starting from node 1\n");

    DFS(1);
    BFS(1);

    return 0;
}