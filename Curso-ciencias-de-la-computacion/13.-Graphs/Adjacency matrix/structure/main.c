#include<stdio.h>

#define V 5

void addEdge(int mat[V][V], int i, int j){
    mat[i][j] = 1;
    mat[j][i] = 1;
}

void displayMatrix(int adjMatrix[V][V]){
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            printf("%d", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int adjMatrix[V][V]={0};

    addEdge(adjMatrix,0,1);
    addEdge(adjMatrix,0,2);
    addEdge(adjMatrix,1,2);
    addEdge(adjMatrix,2,3);

    printf("Adjacency matrix representation:\n");
    displayMatrix(adjMatrix);

    return 0;
}