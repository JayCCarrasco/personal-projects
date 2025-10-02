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

void addNodePos(int data, int position, Node* head){
    Node* newNode = malloc(sizeof(Node));
    Node* temp = head;

    newNode->data = data;
    while (position != 2){
        temp = temp->next;
        position--;
    }

    newNode->next = temp->next;
    temp->next = newNode;

}

void addNodeBegin(Node** headB, int data){
    Node* temp = malloc(sizeof(Node));
    if(temp == NULL){
        printf("Error in memory allocation\n");
    }
    temp->data = data;
    temp->next = *headB;
    *headB = temp;
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

    int position = 0;
    printf("Insert the data: ");
    scanf("%d", &data);
    printf("Insert the position: ");
    scanf("%d", &position);

    if (position == 1){
        addNodeBegin(&head, data);
    } else {
        addNodePos(data, position, head);
    }
  

    while(head!=NULL){
        printf("%d ", head->data);
        head=head->next;
    }


    return 0;
}