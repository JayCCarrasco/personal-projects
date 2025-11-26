#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

/* ---------- NODO DE ADYACENCIA ---------- */
typedef struct Node {
    int vertex;
    int weight;
    struct Node* next;
} Node;

/* ---------- GRAFO ---------- */
typedef struct Graph {
    int numVertices;
    int isDirected;
    Node** adjLists;
} Graph;

/* ---------- HEAP ---------- */
typedef struct {
    int vertex;
    int dist;
} HeapNode;

typedef struct {
    int size;
    int capacity;
    HeapNode* arr;
} MinHeap;

/* ---------- CREAR GRAFO ---------- */
Node* createNode(int v, int w) {
    Node* n = malloc(sizeof(Node));
    n->vertex = v;
    n->weight = w;
    n->next = NULL;
    return n;
}

Graph* createGraph(int vertices, int isDirected) {
    Graph* g = malloc(sizeof(Graph));
    g->numVertices = vertices;
    g->isDirected = isDirected;
    g->adjLists = malloc(vertices * sizeof(Node*));

    for (int i = 0; i < vertices; i++)
        g->adjLists[i] = NULL;

    return g;
}

void addEdge(Graph* g, int src, int dest, int weight) {
    Node* n = createNode(dest, weight);
    n->next = g->adjLists[src];
    g->adjLists[src] = n;

    if (!g->isDirected) {
        n = createNode(src, weight);
        n->next = g->adjLists[dest];
        g->adjLists[dest] = n;
    }
}

void printGraph(Graph* g) {
    for (int i = 0; i < g->numVertices; i++) {
        printf("%d -> ", i);
        Node* p = g->adjLists[i];
        while (p) {
            printf("%d(%d) ", p->vertex, p->weight);
            p = p->next;
        }
        printf("\n");
    }
}

/* ---------- MIN HEAP ---------- */
MinHeap* createHeap(int capacity) {
    MinHeap* h = malloc(sizeof(MinHeap));
    h->size = 0;
    h->capacity = capacity;
    h->arr = malloc(capacity * sizeof(HeapNode));
    return h;
}

void swap(HeapNode* a, HeapNode* b) {
    HeapNode t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(MinHeap* h, int i) {
    int p = (i - 1) / 2;
    if (i && h->arr[i].dist < h->arr[p].dist) {
        swap(&h->arr[i], &h->arr[p]);
        heapifyUp(h, p);
    }
}

void heapifyDown(MinHeap* h, int i) {
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < h->size && h->arr[l].dist < h->arr[smallest].dist)
        smallest = l;
    if (r < h->size && h->arr[r].dist < h->arr[smallest].dist)
        smallest = r;

    if (smallest != i) {
        swap(&h->arr[i], &h->arr[smallest]);
        heapifyDown(h, smallest);
    }
}

void push(MinHeap* h, int v, int dist) {
    h->arr[h->size] = (HeapNode){v, dist};
    heapifyUp(h, h->size);
    h->size++;
}

HeapNode pop(MinHeap* h) {
    HeapNode root = h->arr[0];
    h->arr[0] = h->arr[--h->size];
    printf("ahora es: %d", h->arr[0]);
    heapifyDown(h, 0);
    return root;
}

bool isEmpty(MinHeap* h) {
    return h->size == 0;
}

/* ---------- IMPRIMIR CAMINO ---------- */
void printPath(int parent[], int v) {
    if (v == -1) return;
    printPath(parent, parent[v]);
    printf("%d ", v);
}

/* ---------- DIJKSTRA ---------- */
void dijkstra(Graph* g, int start) {

    int V = g->numVertices;
    int* dist = malloc(V * sizeof(int));
    int* parent = malloc(V * sizeof(int));


    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        parent[i] = -1;
    }

    dist[start] = 0;

    MinHeap* heap = createHeap(V);
    push(heap, start, 0);

    while (!isEmpty(heap)) {

        HeapNode h = pop(heap);
        int u = h.vertex;
        int d = h.dist;

        if (d > dist[u]) continue;   // entrada obsoleta

        Node* p = g->adjLists[u];
        while (p) {
            int v = p->vertex;
            int w = p->weight;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                push(heap, v, dist[v]);
            }
            p = p->next;
        }
    }

    printf("\nDistancias desde %d:\n", start);
    for (int i = 0; i < V; i++)
        printf("0 -> %d = %d\n", i, dist[i]);

    printf("\nCamino minimo 0 -> 5: ");
    printPath(parent, 3);
    printf("\n");

    free(dist);
    free(parent);
}

/* ---------- MAIN ---------- */
int main() {

    Graph* g = createGraph(6, 0);

    addEdge(g, 0, 1, 7);
    addEdge(g, 0, 2, 9);
    addEdge(g, 0, 5, 14);
    addEdge(g, 1, 2, 10);
    addEdge(g, 1, 3, 15);
    addEdge(g, 2, 3, 11);
    addEdge(g, 2, 5, 2);
    addEdge(g, 3, 4, 6);
    addEdge(g, 4, 5, 9);

    printGraph(g);
    dijkstra(g, 0);

    return 0;
}
