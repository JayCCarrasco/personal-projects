//Singly linked list comprehension in C
//by Juan Carlos del Pozo

//Including libraries
#include <stdio.h>
#include <stdlib.h>

//Implementing node structure
typedef struct Node{
    int data;
    struct Node* next;
} Node;

Node* createNode(int value){
    Node* newNode = malloc(sizeof(Node));

    if (newNode == NULL){
        printf("Error allocating memory\n");
    }

    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

void addNode(Node** head, int value){
    Node* newNode = createNode(value);

    if (*head == NULL){
        *head = newNode;
        return;
    }

    Node* temp = malloc(sizeof(Node));
    temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    } 
    temp->next = newNode;

}


//Main
int main(){
    //var declaration
    Node* head = NULL;
    //int value = 0;

    /*Inserting nodes
    printf("Insert a value for next node: ");
    scanf("%d", &value);
    */

    addNode(&head, 10);
    addNode(&head, 20);
    addNode(&head, 30);

    //printf("Añadimos nodo");
    while(head != NULL){
        printf("V: %d ", head->data);
        head = head->next;
    }

    return 0;
}