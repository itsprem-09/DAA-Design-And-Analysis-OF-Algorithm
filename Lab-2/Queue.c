#include<stdio.h>
#include<stdbool.h>
#define MAX 10

typedef struct Queue
{
    int queue[MAX];
    int front;
    int rear;
}Queue;

void initQueue(Queue* q){
    q->front = -1;
    q->rear = -1;
}

bool isFull(Queue* q){
    return q->rear == MAX - 1;
}

bool isEmpty(Queue* q){
    return q->front == -1; 
}

void enqueue(Queue* q, int value){
    if ( isFull(q) )
    {
       printf("Queue Overflow!");
       return;
    }
    q->rear++;
    q->queue[q->rear] = value;
    if ( q->front == -1 )
    {
        q->front = 0;
    }
    return;
}

int dequeue(Queue* q){
    if (isEmpty(q))
    {
        printf("Queue Underflow!");
        return -1;
    }
    int val = q->queue[q->front];
    if (q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    q->front++;
    return val;    
}

void display(Queue* q){
    printf("\n-----------------------------------\n");
    int i;
    for (i = q->front; i <= q->rear; i++)
    {
        printf("%d ", q->queue[i]);
    }
    printf("\n-----------------------------------\n");    
}

void main(){
    Queue* q;
    initQueue(q);
    enqueue(q, 5);
    enqueue(q, 19);
    enqueue(q, 25);
    enqueue(q, 55);
    printf("%d is Deleted.", dequeue(q));
    display(q);
}