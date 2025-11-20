#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXV 100   //Maximum number of vertices

//Global variables
bool processed[MAXV];
bool discovered[MAXV];
int parent[MAXV];

//Graph
typedef struct Graph {
    int numVertices;
    int isDirected;
    int adjMatrix[MAXV][MAXV];
} Graph;

typedef struct stackNode{
    int vertex;
    struct stackNode* next;
}stackNode;

Graph* createGraph(int vertices, int isDirected){
    Graph*  newGraph= malloc(sizeof(Graph));

    newGraph->numVertices = vertices;
    newGraph->isDirected = isDirected;

    for(int i = 0; i < vertices; i++){
        for(int j = 0; j < vertices; j++){
            newGraph->adjMatrix[i][j] = 0;
        }
    }

    return newGraph;
}

void addEdge(Graph* g, int src, int dest){
    //Add edge from src to dest
    g->adjMatrix[src][dest] = 1;

    //If the graph is undirected, add edge from dest to src too
    if(!g->isDirected){
        g->adjMatrix[dest][src] = 1;
    }
}

void printGraph(Graph* g){
    printf("Vertex: Adjacency matrix\n");
    for(int i = 0; i < g->numVertices; i++){
        for(int j = 0; j < g->numVertices; j++){
            printf(" %d ", g->adjMatrix[i][j]);
        }
        printf("\n");
    }
        
}

void initialize_search(Graph *g){

    for (int i = 0; i < g->numVertices; i++){
        processed[i] = false;
        discovered[i] = false;
        parent[i] = -1;

    }
}

void push(stackNode** top, int v){
    stackNode* newNode = malloc(sizeof(stackNode));
    newNode->vertex = v;
    newNode->next = *top;
    *top = newNode;
}


int pop(stackNode** top){
    if ((*top) == NULL) return -1;
    stackNode* temp = *top;
    int v = temp->vertex;
    *top = temp->next;
    free(temp);
    return v;
}

void dfs(Graph* g, int start){
    initialize_search(g);

    stackNode* stack = NULL;

    push(&stack, start);
    discovered[start] = true;

    while(stack != NULL) {
        int v = pop(&stack);
        printf(" %d ", v);

        processed[v] = true;

        for(int y = 0; y < g->numVertices; y++){
            if(g->adjMatrix[v][y] == 1){
                if(!discovered[y]){
                    push(&stack, y);
                    discovered[y] = true;
                    parent[y] = v;
                } 
            }
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

    dfs(directedGraph, 0); 
    
}

