#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Structure for a graph
struct Graph {
    int vertices;
    int edges;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
};

// Function to initialize a graph
void initializeGraph(struct Graph* graph, int vertices) {
    graph->vertices = vertices;
    graph->edges = 0;

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int source, int destination) {
    if (source >= 0 && source < graph->vertices && destination >= 0 && destination < graph->vertices) {
        graph->adjacencyMatrix[source][destination] = 1;
        graph->adjacencyMatrix[destination][source] = 1; // For an undirected graph
        graph->edges++;
    }
}

// Function to print the adjacency matrix
void printGraph(struct Graph* graph) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->vertices; i++) {
        for (int j = 0; j < graph->vertices; j++) {
            printf("%d ", graph->adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    struct Graph graph;
    int vertices, edges, source, destination;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    initializeGraph(&graph, vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        printf("Enter edge %d (source destination): ", i + 1);
        scanf("%d %d", &source, &destination);
        addEdge(&graph, source, destination);
    }

    printGraph(&graph);

    return 0;
}
