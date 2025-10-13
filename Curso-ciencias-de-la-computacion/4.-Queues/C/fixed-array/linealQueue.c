#include <stdio.h>
#include <stdbool.h>

#define SIZE 5

typedef struct Queue {

    int data[SIZE];
    int front;
    int rear;

} Queue;

bool isFull(Queue* q){
    return q->rear == SIZE -1;
}

bool isEmpty(Queue* q){
    return q->front > q->rear;
}

void initQueue(Queue* q){
    q->front = 0;
    q->rear = -1;

}

void enqueue (Queue* q, int value){

    if (isFull(q)){
        printf("Queue is full\n");
        return;
    }

    q->rear++;
    q->data[q->rear] = value;
    printf("Enqueued %d\n", value);  
}

int dequeue (Queue *q){
    if (isEmpty(q)){
        printf("Queue is empty\n");
        return -1;
    }

    int value = q->data[q->front];
    q->front++;
    printf("Dequeued\n");
    
    return value;   
}

void printQueue(Queue *q){
    /*if (isEmpty(q)){
        printf("Queue is empty\n");
        return;
    }*/

    for(int i = q->front; i <= q->rear; i++){
        printf(" %d ", q->data[i]);
    }
}

int main(){
    
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    printQueue(&q);
    dequeue(&q);
    printQueue(&q);
    dequeue(&q);
    printQueue(&q);
    enqueue(&q, 50);
    printQueue(&q);
    enqueue(&q, 60);
    printQueue(&q);

    return 0;
}
