#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data){
    Node* node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;

    return node;
}

void addNode (Node** head, Node** tail, int data){
    Node* node = createNode(data);

    if(*head == NULL){
        *head = node;
        *tail = node;
        //printf("Damos cabeza");
    } else {
        (*tail)->next = node;
        *tail = node;

        //printf("Dando cola");
    }
}

void deleteNode(Node**head, Node** tail){
    if (*head == NULL) return;  

    Node* temp = *head;
    *head = (*head)->next;
    free(temp);

    if (*head == NULL) {  
        *tail = NULL;
    }
}

void print(Node* head){
    Node* temp = head;

    while(temp != NULL){
        printf(" %d ", temp->data);
        temp = temp->next;
    }

}


int main() {
    Node* head = NULL;
    Node* tail = NULL;
    int data = 0;

    addNode(&head, &tail, 10);
    addNode(&head, &tail, 20);
    addNode(&head, &tail, 30);
    print(head);

    deleteNode(&head, &tail);
    print(head);
    deleteNode(&head, &tail);
    print(head);
    deleteNode(&head, &tail);
    print(head);

    free(head);
    free(tail);

    return 0;
}