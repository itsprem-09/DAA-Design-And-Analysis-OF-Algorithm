#include<stdio.h>
#include<stdlib.h>

// typedef used for giving alias to the structure

typedef struct Node
{
    int data;
    struct Node* next;
}Node;

Node* head = NULL;

void insertAtFirst(int value){
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

void insertAtLast(int value){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node* move = head;
    while (move->next != NULL)
    {
        move = move->next;
    }
    move->next = newNode;
}

void deleteAtFirst(){
    if (head == NULL)
    {
        printf("No Elements in Linked List!\n");
        return;
    }
    if (head->next == NULL)
    {
        head = NULL;
        printf("Element Deleted Successfully.\n");
        return;
    }
    head = head->next;
    printf("Element Deleted Successfully.\n");
}

void deleteAtLast(){
    if (head == NULL)
    {
        printf("No Elements in Linked List!\n");
        return;
    }
    if (head->next == NULL)
    {
        head = NULL;
        printf("Element Deleted Successfully.\n");
        return;
    }
    Node* move = head;
    while (move->next->next != NULL)
    {
        move = move->next;
    }
    move->next = NULL;
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
    insertAtLast(5);
    insertAtLast(10);
    insertAtLast(25);
    insertAtLast(55);
    deleteAtLast();
    display();
}