#include <stdio.h>
#include <stdbool.h>

#define SIZE 5

typedef struct Queue{
    int data[SIZE];
    int front;
    int rear;
    int count;
} Queue;

void initQueue(Queue *q){
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

bool isFull(Queue *q){
    return q->count == SIZE;
}

bool isEmpty(Queue *q){
    return q->count == 0;
}
void enqueued(Queue* q, int data){
    if(isFull(q)){
        printf("Queue is full\n");
        printf("count is: %d\n", q->count);
        return;
    }

    q->rear = (q->rear+ 1) % SIZE;
    q->data[q->rear] = data;
    q->count++;
    printf("[front=%d, rear=%d, count=%d]\n", q->front, q->rear, q->count);
}

void dequeued(Queue *q){
    if (isEmpty(q)){
        printf("Queue is empty\n");
        return;
    }

    q->front = (q->front+ 1) % SIZE;
    q->count--;
    printf("[front=%d, rear=%d, count=%d]\n", q->front, q->rear, q->count);

}

void printQueue(Queue *q){
    if (isEmpty(q)){
        printf("Queue is empty\n");
        return;
    }
    printf("Queue is: ");
    for (int i = 0; i < q->count; i++) {
        int index = (q->front + i) % SIZE;
        printf(" %d ", q->data[index]);
    }
    printf("\n");
}

int main(){
    Queue q;
    int option = -1;
    int exit = -1;
    int value = 0;
    initQueue(&q);

    while (exit != 0){
        printf("Select an option: \n");
        printf("1: Enqueue\n");
        printf("2: Dequeue\n");
        printf("3: Print\n");
        printf("0: Exit\n");
        scanf("%d", &option);

        switch(option){
            case 0:
                exit = 0;
                printf("Exiting...");
                break;
            case 1: 
                printf("Select a value: \n");
                scanf("%d", &value);
                enqueued(&q, value);
                break;
            case 2:
                dequeued(&q);
                break;
            case 3: 
                printQueue(&q);
                break;
        }
    }   
    return 0;
}