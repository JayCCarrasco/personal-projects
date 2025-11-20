#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct queueNode{
    Node* treeNode;
    struct queueNode* next;
}queueNode;

void enqueue(queueNode** front, queueNode** rear, Node* node){
    queueNode* newNode = malloc(sizeof(queueNode));
    newNode->treeNode = node;
    newNode->next = NULL;

    if (*rear) (*rear)->next = newNode;
    else *front = newNode;
    *rear = newNode;
}

Node* dequeue(queueNode** front, queueNode** rear){
    if ((*front) == NULL) return NULL;
    queueNode* temp = *front;
    Node* node = temp->treeNode;
    *front = temp->next;
    if (*front == NULL) (*rear = NULL);
    free(temp);
    return node;
}

void breadthFirstSearch(Node* root){
    if (root == NULL) return;

    queueNode* front = NULL;
    queueNode* rear = NULL;
    enqueue(&front, &rear, root);

    while(front != NULL) {
        Node *current = dequeue(&front, &rear);
        printf(" %d ", current->data);

        if (current->left){
            enqueue(&front, &rear, current->left);
        }
        if (current->right){
            enqueue(&front, &rear, current->right);
        }
    }
}

Node* createNode(int data, Node* left, Node* right){
    Node* node = malloc(sizeof(Node));
    node->data = data;
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

    breadthFirstSearch(n1);

    freeTree(n1); 

    return 0;
}