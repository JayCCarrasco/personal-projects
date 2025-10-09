#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

void addBegin(int data, Node** head){
    Node* newP = malloc(sizeof(Node));
    if (newP == NULL){
        printf("Error: Dynamic allocation failed.\n");       
    }
    newP->data = data;
    newP->next = *head; //El siguiente nodo a newP es al que apuntaba head
    *head = newP;   //El head real apunta a newP **head es el puntero del puntero head real, no son lo mismo
}

void deleteNode(Node** head){
    Node* current = *head;

    if (head == NULL){
        printf("List is already empty.");
    }

    *head = current->next;
    free(current);
}



int main(){
    Node* head = malloc(sizeof(Node));
    Node* temp = head;
    int headDeclared = 0;
    int size = 0;
    int exit = 1;
    int option = 0;
    if (head == NULL){
        printf("Error: Dynamic allocation failed.\n");
    }
    int data = 0;
    printf("Insert the first value of the linked list: \n");
    

    while (exit != 0){

        printf("Please, select the operation\n");
        printf("1: Insert values in the array.\n");
        printf("2: Check if array is empty\n");
        printf("3: Delete\n");
        printf("0: Exit\n");
        scanf("%d", &option);

        switch(option) {
            case 0: 
                exit = 0; 
                break;
            case 1:
                if (head == NULL) {
                    head = malloc(sizeof(Node));
                }
                if (headDeclared == 0){
                    printf("Insert the first value for stack: \n");
                    scanf("%d", &data);
                    head->data = data;
                    head->next = NULL;
                    headDeclared = 1;
                    break;
                }
                printf("Insert next value for the stack: \n");
                scanf("%d", &data);
                addBegin(data, &head);
                break;
            case 2:
                if (size == 0){
                    printf("The list is empty\n");
                } else {
                    printf("The list is not empty\n");
                }
                break;
            case 3:
                deleteNode(&head);
                break; 
        }

        if(headDeclared != 0){

            size = 0;

            temp = head;

            printf("pointer head: %d\n", head->data);
            
            while (temp != NULL){
                printf("%d ", temp->data);
                temp = temp->next;
                size++;
            }
        

            printf("\n");

            printf("The size of the singly linked list is: %d \n", size);
        }
        

    }

    free(head);
    head = NULL;

    return 0;
}