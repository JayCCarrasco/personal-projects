#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    bool visited;
    struct Node* left;
    struct Node* right;
} Node;

//depthFirstSearch configure as PostOrder DFS
void depthFirstSearch(Node* root){
    if (root == NULL) return;
    depthFirstSearch(root->left);
    depthFirstSearch(root->right);
    if(root->visited == false){
        printf("%d ", root->data);
        root->visited = true;
    }
}

Node* createNode(int data, Node* left, Node* right){
    Node* node = malloc(sizeof(Node));
    node->data = data;
    node->visited = false;
    node->left = left;
    node->right = right;
    
    return node;
}

void freeTree(Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    Node* n1 = NULL;
    Node* n2 = NULL;
    Node* n3 = NULL;
    Node* n4 = NULL;
    Node* n5 = NULL;
    Node* n6 = NULL;
    Node* n7 = NULL;
    Node* n8 = NULL;
    Node* n9 = NULL;
    
    n9 = createNode(90, NULL, NULL);
    n8 = createNode(80, n9, NULL);
    n5 = createNode(50, NULL, NULL);
    n6 = createNode(60, NULL, NULL);
    n7 = createNode(70, NULL, NULL);
    n4 = createNode(40, n5, NULL);
    n3 = createNode(30, n7, n8);
    n2 = createNode(20, n4, n6);
    n1 = createNode(10, n2, n3);

    depthFirstSearch(n1);

    freeTree(n1); 

    return 0;
}