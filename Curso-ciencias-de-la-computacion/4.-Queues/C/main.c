#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

Node* addNode(int data, Node* current){
    Node* newP  = malloc(sizeof(Node));
    if (newP == NULL){
        printf("Error: Dynamic allocation failed.\n");       
    }
    newP->data = data;
    newP->next = NULL;
    current->next = newP;

    return newP;
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
    Node* current = head;
    int headDeclared = 0;
    int size = 0;
    int exit = 1;
    int position = 0;
    int option = 0;
    if (head == NULL){
        printf("Error: Dynamic allocation failed.\n");
    }
    int data = 0;
    //printf("Insert the first value of the linked list: \n");
    

    while (exit != 0){

        printf("Please, select the operation\n");
        printf("1: Enqueue\n");
        printf("2: Dequeue\n");
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
                    printf("Insert the first value for queue: \n");
                    scanf("%d", &data);
                    head->data = data;
                    head->next = NULL;
                    current = head;
                    headDeclared = 1;
                    break;
                }
                printf("Insert next value queue: \n");
                scanf("%d", &data);
                current = addNode(data, current);
                break;
            case 2:
                deleteNode(&head);
                break;
        }

        if (head != NULL){
            size = 0;

            printf("pointer head: %d\n", head->data);

            temp = head;
            
            while (temp != NULL){
                printf("%d ", temp->data);
                temp = temp->next;
                size++;
            }
        

            printf("\n");

            printf("The size of the singly linked list is: %d \n", size);
        } else {
            headDeclared = 0;
        }
        

    }

    free(head);
    head = NULL;
    free(current);
    current = NULL;
    free(temp);
    temp = NULL;

    return 0;
}