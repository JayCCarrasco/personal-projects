//Stack implementation in C
//By JCPC

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

Node* pushNode (Node* head, int data){
    Node* node = createNode(data);
    node->next = head;
    return node;
}

void deleteNode(Node** head){
    Node* tmp = *head;

    if(*head == NULL){
        printf("Stack is already empty\n");
        return;
    }

    *head = tmp->next;
    free(tmp);
}

void printStack(Node* head){
    if(head == NULL){
        printf("Stack is empty\n");
        return;
    }
    printf("The stack is: ");
    while(head != NULL){
        printf(" %d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main(){

    Node* head = NULL;
    int option = -1;
    bool exit = false;
    int data = 0;

    while(exit == false){
        printf("Choose option\n");
        printf("0: Exit\n");
        printf("1: Push\n");
        printf("2: Delete\n");
        printf("3: Print\n");
        scanf("%d", &option);
        switch(option){
            case 0:
                exit = true;
                break;
            case 1:
                printf("Select data: ");
                scanf("%d", &data);
                head = pushNode(head, data);
                break;
            case 2:
                deleteNode(&head);
                break;
            case 3:
                printStack(head);
                break;
        }
    }
    return 0;
}
