#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXV 100   //Maximum number of vertices

//Global variables
bool processed[MAXV + 1];
bool discovered[MAXV + 1];
int parent[MAXV + 1];

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

typedef struct queueNode{
    int vertex;
    struct queueNode* next;
}queueNode;

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

void initialize_search(Graph *g){

    for (int i = 0; i < g->numVertices; i++){
        processed[i] = false;
        discovered[i] = false;
        parent[i] = -1;

    }
}

void enqueue(queueNode** front, queueNode** rear, int v){
    queueNode* newNode = malloc(sizeof(queueNode));
    newNode->vertex = v;
    newNode->next = NULL;

    if (*rear) (*rear)->next = newNode;
    else *front = newNode;
    *rear = newNode;
}

int dequeue(queueNode** front, queueNode** rear){
    if ((*front) == NULL) return -1;

    queueNode* temp = *front;
    int v = temp->vertex;

    *front = temp->next;
    if (*front == NULL) (*rear = NULL);

    free(temp);
    return v;
}

void bfs(Graph* g, int start){
    initialize_search(g);

    queueNode* front = NULL;
    queueNode* rear = NULL;

    enqueue(&front, &rear, start);
    discovered[start] = true;

    while(front != NULL) {
        int v = dequeue(&front, &rear);
        printf(" %d ", v);

        processed[v] = true;

        Node* p = g->adjLists[v];

        printf("v es: %d\n", v);

        printf("pvertex es: %d\n", p->vertex);

        while (p != NULL){
            int y = p->vertex;

            if (!processed[y] || g->isDirected){
                //printf("do something when see edge\n");
            }

            if(!discovered[y]){
                enqueue(&front, &rear, y);
                discovered[y] = true;
                parent[y] = v;
            }
            p = p->next;
        }
        //printf("Do something when you see late vertex\n");
    }
}

int main(){
    /*//Creating an undirected graph with 3 vertices
    Graph* undirectedGraph = createGraph(8,0);

    //Add edges to the undirectedGraph
    addEdge(undirectedGraph, 0, 1);
    addEdge(undirectedGraph, 0, 6);
    addEdge(undirectedGraph, 0, 7);
    addEdge(undirectedGraph, 1, 2);
    addEdge(undirectedGraph, 1, 4);
    addEdge(undirectedGraph, 1, 6);
    addEdge(undirectedGraph, 2, 3);
    addEdge(undirectedGraph, 2, 4);
    addEdge(undirectedGraph, 2, 4);
    addEdge(undirectedGraph, 4, 5);

    printf("Adjacency list for Undirected graph: \n");
    printGraph(undirectedGraph);
*/
    
    // Create a directed graph with 3 vertices
    Graph* directedGraph = createGraph(8, 1);

    // Add edges to the directed graph
    addEdge(directedGraph, 0, 1);
    addEdge(directedGraph, 0, 6);
    addEdge(directedGraph, 0, 7);
    addEdge(directedGraph, 1, 2);
    addEdge(directedGraph, 1, 4);
    addEdge(directedGraph, 1, 6);
    addEdge(directedGraph, 2, 3);
    addEdge(directedGraph, 2, 4);
    addEdge(directedGraph, 3, 4);
    addEdge(directedGraph, 4, 5);

    printf("\nAdjacency List for Directed Graph:\n");
    printGraph(directedGraph);

    bfs(directedGraph, 0); 
}

