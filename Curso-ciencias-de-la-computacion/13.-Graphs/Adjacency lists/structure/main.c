#include <stdio.h>
#include <stdlib.h>

//Node
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

//Graph
typedef struct Graph {
    int numVertices;
    struct Node** adjLists; //Pointer to an array of pointers Node
    int isDirected;
} Graph;

Node* createNode(int v){
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int vertices, int isDirected){
    Graph*  newGraph= malloc(sizeof(Graph));

    newGraph->numVertices = vertices;
    newGraph->isDirected = isDirected;

    newGraph->adjLists = malloc(vertices * sizeof(Node*));  //Size of a pointer to node as adjList is an array of pointers to node

    for(int i = 0; i < vertices; i++){
        newGraph->adjLists[i] = NULL;
    }

    return newGraph;
}

void addEdge(Graph* g, int src, int dest){
    //Add edge from src to dest
    Node* newNode = createNode(dest);
    newNode->next = g->adjLists[src];
    g->adjLists[src] = newNode;

    //If the graph is undirected, add edge from dest to src too
    if(!g->isDirected){
        newNode = createNode(src);
        newNode->next = g->adjLists[dest];
        g->adjLists[dest] = newNode;
    }
}

void printGraph(Graph* g){
    printf("Vertex: Adjacency list\n");
    for(int v = 0; v < g->numVertices; v++){
        Node* temp = g->adjLists[v];
        printf("%d---->", v);
        while(temp){
            printf(" %d ->", temp->vertex);
            temp = temp->next;
        }
        printf(" NULL\n");
    }
}

int main(){
    //Creating an undirected graph with 3 vertices
    Graph* undirectedGraph = createGraph(3,0);

    //Add edges to the undirectedGraph
    addEdge(undirectedGraph, 0, 1);
    addEdge(undirectedGraph, 0, 2);
    addEdge(undirectedGraph, 1, 2);

    printf("Adjacency list for Undirected graph: \n");
    printGraph(undirectedGraph);

    // Create a directed graph with 3 vertices
    Graph* directedGraph = createGraph(3, 1);

    // Add edges to the directed graph
    addEdge(directedGraph, 1, 0);
    addEdge(directedGraph, 1, 2);
    addEdge(directedGraph, 2, 0);

    printf("\nAdjacency List for Directed Graph:\n");
    printGraph(directedGraph);


}

