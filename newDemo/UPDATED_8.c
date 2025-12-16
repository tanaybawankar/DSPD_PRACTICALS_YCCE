#include <stdio.h>

#define MAX 30

typedef struct {
    int u, v, w;
} Edge;

Edge edges[MAX];
Edge mst[MAX];

int parent[MAX];
int n, e;   // n = vertices, e = edges

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void union_sets(int a, int b) {
    int x = find(a);
    int y = find(b);
    parent[x] = y;
}

void kruskal() {
    int i, j, k = 0;
    int totalWeight = 0;
    Edge temp;

    // Sort edges by weight (simple bubble sort)
    for (i = 0; i < e - 1; i++) {
        for (j = 0; j < e - i - 1; j++) {
            if (edges[j].w > edges[j + 1].w) {
                temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    // Initialize disjoint sets
    for (i = 0; i < n; i++)
        parent[i] = i;

    // Kruskal’s algorithm
    for (i = 0; i < e && k < n - 1; i++) {
        int a = find(edges[i].u);
        int b = find(edges[i].v);

        if (a != b) {
            mst[k++] = edges[i];
            totalWeight += edges[i].w;
            union_sets(a, b);
        }
    }

    // Print MST
    printf("Edges in the Minimum Spanning Tree:\n");
    for (i = 0; i < k; i++) {
        printf("%d -- %d == %d\n", mst[i].u, mst[i].v, mst[i].w);
    }
    printf("Total weight of MST = %d\n", totalWeight);
}

int main() {
    int i;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter %d edges (u v w) with vertices numbered 0 to %d:\n", e, n - 1);
    for (i = 0; i < e; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    kruskal();

    return 0;
}
