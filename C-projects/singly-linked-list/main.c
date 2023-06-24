#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* addNode(int data, Node* current){
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    current->next = newNode;
    return newNode;
}

int main(){
    Node* head = malloc(sizeof(Node));
    head->data = 10;
    head->next = NULL;
    int data = 0;
    int exit = 1;

    Node* current = head;

    while (exit != 0){
        printf("Insert the data for the next node: ");
        scanf("%d", &data);
        current = addNode(data, current);
        printf("Insert 0 if you want to exit: ");
        scanf("%d", &exit);
    }

    while(head!=NULL){
        printf("%d ", head->data);
        head=head->next;
    }

    return 0;
}