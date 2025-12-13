#include <stdio.h>
#define SIZE 6
#define EDGES 20
#define INFINITY 99999

typedef int adjacencyMatrix[SIZE][SIZE];
typedef int SET[SIZE];

typedef struct {
    int tail;
    int head;
    int weight;
} edgetype;

typedef struct {
    int distance[SIZE];
    int parent[SIZE];
} DP;

void initMatrix(adjacencyMatrix m);
void printMatrix(adjacencyMatrix m);
void populateMatrix(adjacencyMatrix m, edgetype edges[]);
DP dijkstra(adjacencyMatrix m, int src);

int main() {
    edgetype edges[20] = {
    // {tail, head, weight}  -- Original Vertex (1-6)
        {0, 1, 5},   // 1-2
        {0, 2, 12},  // 1-3
        {0, 5, 8},   // 1-6
        {1, 0, 5},  // 2-1 (Back edge)
        {1, 3, 3},   // 2-4 (Lowest weight)
        {1, 4, 10},  // 2-5
        {2, 3, 18},  // 3-4 (Highest weight)
        {2, 5, 9},   // 3-6
        {3, 0, 7},   // 4-1
        {3, 4, 14},  // 4-5
        {3, 5, 11},  // 4-6
        {4, 1, 10},  // 5-2
        {4, 5, 13},  // 5-6
        {5, 0, 8},   // 6-1 (Lowest weight)
        {5, 2, 9},   // 6-3
        {5, 4, 13},   // 6-5
        {0, 3, 7},  // 1-4
        {2, 1, 6},   // 3-2
        {4, 4, 19},  // 5-5 (Loop)
        {3, 2, 18}   // 4-3 (Highest weight)
    };
    adjacencyMatrix mat;
    initMatrix(mat);
    populateMatrix(mat, edges);
    printMatrix(mat);

    DP d = dijkstra(mat, 3);

    printf("\n\nINDEX DISTANCE PARENT\n");
    for (int i = 0; i < SIZE; i++) {
        if (d.distance[i] == INFINITY) {
            printf("%i\t ∞ \t %i\n",i, d.parent[i]);
        } else {
            printf("%i\t %i \t %i\n",i, d.distance[i], d.parent[i]);
        }

    }
}

void initMatrix(adjacencyMatrix m) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            m[i][j] = INFINITY;
        }
    }
}
void printMatrix(adjacencyMatrix m) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (m[i][j] == INFINITY) {
                printf("∞\t");
            } else
            printf("%i\t", m[i][j]);
        }
        printf("\n");
    }
}

void populateMatrix(adjacencyMatrix m, edgetype edges[]) {
    for (int x = 0; x < EDGES; x++) {
        int i = edges[x].tail;
        int j = edges[x].head;
        m[i][j] = edges[x].weight;
    }
}

int allVisited(SET v) {
    int i;
    for (i = 0; i < SIZE && v[i] == 1; i++);
    return (i < SIZE) ? 0 : 1;

    // return 0 if one of the vertices are still not visited; 1 if all are visited
}

DP dijkstra(adjacencyMatrix m, int src) {
    // populate vertex set
    SET V;
    for (int i = 0; i < SIZE; i++) {
        V[i] = (i == src) ? 1 : 0;
    }

    // populate distance parent matrix
    DP dp;
    for (int i = 0; i < SIZE; i++) {
        dp.distance[i] = m[src][i];
        dp.parent[i] = src;
    }

    //print dp matrix
    // vertex loop
    while (allVisited(V) == 0) {
        int min = src;

        for (int i = 0; i < SIZE; i++) {
            if (V[i] == 0 && dp.distance[i] < dp.distance[min]) {
                min = i;
            }
        }

        if (min == src) {
            break;
        }

        V[min] = 1;

        //relaxation
        if (allVisited(V) == 0) {
            for (int i = 0; i < SIZE; i++) {
                if (V[i] == 0) {
                    int curr_dist = dp.distance[i];
                    int add_dist = dp.distance[min] + m[min][i];

                    if (add_dist < curr_dist) {
                        dp.distance[i] = add_dist;
                        dp.parent[i] = min;
                    }
                }
            }
        }
    }

    dp.distance[src] = 0;

    return dp;

}