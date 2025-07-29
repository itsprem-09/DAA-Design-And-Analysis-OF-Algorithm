#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
}Node;

Node* head = NULL;

// this push method is same as the insert at first operation for LL
void push(int value){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}

// this pop method is same as the delete at first operation for LL
int pop(){
    int val = -1;
    if (head == NULL)
    {
        printf("No Elements in Stack!\n");
        return val;
    }
    if (head->next == NULL)
    {
        val = head->data;
        head = NULL;
        printf("Element Deleted Successfully.\n");
        return val;
    }
    val = head->data;
    head = head->next;
    printf("Element Deleted Successfully.\n");
    return val;
}

void display(){
    Node* temp = head;
    printf("----------------------------------\n");
    while (temp != NULL)
    {
        printf("%d ", *temp);
        temp = temp->next;
    }
    printf("\n----------------------------------\n");
}

void main(){
    push(5);
    push(10);
    push(25);
    push(55);
    pop();
    display();
}

