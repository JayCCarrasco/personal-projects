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
    Node* temp = *head;

    if (*head == NULL){
        *head = newNode;
        return;
    }

    while(temp->next != NULL){
        temp = temp->next;
    } 
    temp->next = newNode;
}

void isEmpty(Node* head){
    if (head == NULL){
        printf("It is empty\n");
    } else {
        printf("It is NOT empty\n");
    }
}

void lookForIndex(Node* head, int index){
    for(int i = 0; i < index; i++){
        head = head->next;
    }

    printf("The value in index %d is %d\n", index, head->data);
}

void insertAtIndex(Node** head, int index, int value){
    Node* newNode = createNode(value);
    Node* temp = *head;     //Memory allocation is for create the node, not for traverse the list

    if (index == 0){
        if(*head != NULL){
            newNode->next = temp;
        }
        *head = newNode;
        return;
    } else {
        for (int i = 0; i < index-1; i++){
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void deleteAtIndex(Node** head, int index){
    Node* temp = *head;

    if (index == 0){
        *head = temp->next;
        free(temp);
        return;
    } else {
        for (int i = 0; i < index-1; i++){
            temp = temp->next;
        }
        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        free(nodeToDelete);
    }
}

// Invertir la lista (versión con doble puntero y función void)
void reverseList(Node **head) {
    Node *prev = NULL;
    Node *curr = *head;
    Node *next = NULL;

    while (curr != NULL) {
        next = curr->next;   // Guardar el siguiente nodo
        curr->next = prev;   // Invertir el enlace
        prev = curr;         // Avanzar prev
        curr = next;         // Avanzar curr
    }

    *head = prev; // Actualizar el puntero head en el main
}

//Main
int main(){
    //var declaration
    Node* head = NULL;
    Node* temp = NULL;
    int data = 0;
    int exit = 1;
    int option = -1;
    int size = 0;
    int index = -1;

    while (exit != 0){
        printf("Choose one of the next options: \n");
        printf("0: Exit\n");
        printf("1: Insert values\n");
        printf("2: Get size\n");
        printf("3: Is it empty?\n");
        printf("4: Return value at index\n");
        printf("5: Insert data at index\n");
        printf("6: Delete at index\n");
        printf("7: Reverse list\n");
        scanf("%d", &option);

        switch (option){
            case 0:
                exit = 0;
                break;
            case 1: 
                printf("Insert data for next node: ");
                scanf("%d", &data);
                addNode(&head, data);
                break;
            case 2:
                temp = head;
                while(temp != NULL){
                    temp = temp->next;
                    size++;
                } 
                printf("Size is: %d\n", size);
                size = 0;
                free(temp);
                temp = NULL;
                break;
            case 3:
                isEmpty(head);
                break;
            case 4:
                printf("Insert index: ");
                scanf("%d", &index);
                lookForIndex(head, index);
                break;
            case 5:
                printf("Insert index: ");
                scanf("%d", &index);
                printf("Insert data: ");
                scanf("%d", &data);
                insertAtIndex(&head, index, data);
            case 6:
                printf("Insert index to delete\n");
                scanf("%d", &index);
                deleteAtIndex(&head, index);
            case 7: 
                reverseList(&head);
        }

    }

    //printf("Añadimos nodo");
    while(head != NULL){
        printf("V: %d ", head->data);
        head = head->next;
    }

    free(head);
    head = NULL;

    return 0;
}