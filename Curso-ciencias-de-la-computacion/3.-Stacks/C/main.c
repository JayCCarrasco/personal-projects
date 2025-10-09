#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* createNode(int data){

    Node* node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;

    return node;
}

void addNode(Node** head, int data){
    Node* node = createNode(data);

    if (*head == NULL){
        *head = node;
    } else {
        node->next = *head;
        *head = node;
    }  
}

void deleteNode(Node** head){
    Node* deleteNode = *head;
    if(*head == NULL){
        printf("List is empty\n");
    }else{
        *head = (*head)->next;
    }
    

    free(deleteNode);


}

int main(){
    Node* head = NULL;
    Node* temp = NULL;

    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);

    temp = head;
    while(temp != NULL){
        printf("%d\n", temp->data);
        temp = temp->next;
    }

    printf("------------\n");

    deleteNode(&head);
    temp = head;
    while(temp != NULL){
        printf("%d\n", temp->data);
        temp = temp->next;
    }

    deleteNode(&head);
    temp = head;
    while(temp != NULL){
        printf("%d\n", temp->data);
        temp = temp->next;
    }

    deleteNode(&head);
    deleteNode(&head);
    deleteNode(&head);
    temp = head;
    while(temp != NULL){
        printf("%d\n", temp->data);
        temp = temp->next;
    }


    free(head);
    head = NULL;


}