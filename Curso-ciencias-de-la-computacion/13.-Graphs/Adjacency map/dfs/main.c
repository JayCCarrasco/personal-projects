#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "uthash.h"

#define MAXV 100   //Maximum number of vertices

//Global variables
bool processed[MAXV + 1];
bool discovered[MAXV + 1];
int parent[MAXV + 1];

//Node
typedef struct Neighbor{
    int vertex;
    UT_hash_handle hh;
} Neighbor;

typedef struct AdjListEntry{
    int vertex;
    Neighbor* neighbors;
    UT_hash_handle hh;
} AdjListEntry;

//Graph
typedef struct Graph {
    int numVertices;
    int isDirected;
    AdjListEntry* adjMap;   //vertices hash map
} Graph;

typedef struct stackNode{
    int vertex;
    struct stackNode* next;
}stackNode;

Graph* createGraph(int vertices, int isDirected){
    Graph*  newGraph= malloc(sizeof(Graph));

    newGraph->numVertices = vertices;
    newGraph->isDirected = isDirected;

    newGraph->adjMap = NULL;

    return newGraph;
}

AdjListEntry* getOrCreateVertex(Graph* g, int v){
    AdjListEntry* entry;

    HASH_FIND_INT(g->adjMap, &v, entry);

    if(!entry){
        entry = malloc(sizeof(AdjListEntry));
        entry->vertex = v;
        entry->neighbors = NULL;
        HASH_ADD_INT(g->adjMap, vertex, entry);
    }
    return entry;
}

void addNeighbor(AdjListEntry* entry, int v){
    Neighbor* n;

    HASH_FIND_INT(entry->neighbors, &v, n);
    
    if(!n){
        n = malloc(sizeof(Neighbor));
        n->vertex = v;
        HASH_ADD_INT(entry->neighbors, vertex, n);
    }
}

void addEdge(Graph* g, int src, int dest){
    //Add edge from src to dest
    AdjListEntry* entry = getOrCreateVertex(g, src);
    addNeighbor(entry, dest);

    //If the graph is undirected, add edge from dest to src too
    if(!g->isDirected){
        entry = getOrCreateVertex(g, dest);
        addNeighbor(entry, src);
    }
}

void printGraph(Graph* g){
    printf("Vertex: Adjacency list\n");
    
    AdjListEntry *entry, *entryTmp;
    Neighbor *n, *nTmp;

    HASH_ITER(hh, g->adjMap, entry, entryTmp){
        printf("%d ->", entry->vertex);
        HASH_ITER(hh, entry->neighbors, n, nTmp){
            printf("%d ->", n->vertex);
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

        AdjListEntry *entry;

        HASH_FIND_INT(g->adjMap, &v, entry);
        if(!entry) continue;

        Neighbor *n, *nTmp;
        HASH_ITER(hh, entry->neighbors, n, nTmp){
            int y = n->vertex;

            if(!discovered[y]){
                push(&stack, y);
                discovered[y] = true;
                parent[y] = v;
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


