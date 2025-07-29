#include<stdio.h>
#include<stdbool.h>
#define MAX 10

struct Stack
{
    int stack[MAX];
    int top; 
};


void initStack(struct Stack* st){
    st->top = -1;
}

bool isFull(struct Stack* st){
    return st->top == MAX - 1;
}

bool isEmpty(struct Stack* st){
    return st->top == -1;
}

void push(struct Stack* st, int val){
    if (isFull(st))
    {
        printf("Stack Overflow!");
        return;
    }
    st->top++;
    st->stack[st->top] = val;
}

int pop(struct Stack* st){
    if (isEmpty(st))
    {
        printf("Stack Underflow!");
        return -1;
    }
    int val = st->stack[st->top];
    st->top--;
    return val;
}

void display(struct Stack* st){
    int i;
    printf("----------------------------------\n");
    for (i = 0; i <= st->top; i++)
    {
        printf("%d ", st->stack[i]);
    }
    printf("\n----------------------------------\n");
}

int peep(struct Stack* st, int index){
    if ( st->top - index + 1 < 0 )
    {
        printf("Stack Overflow!");
        return -1;
    }
    return st->stack[st->top - index + 1];
}

void change(struct Stack* st, int index, int val){
    if ( st->top - index + 1 < 0 )
    {
        printf("Stack Overflow!");
        return;
    }
    st->stack[st->top - index + 1] = val;
    return;
}

void main(){
    struct Stack* st;
    initStack(st);
    push(st, 5);
    push(st, 15);
    push(st, 10);
    push(st, 22);
    push(st, 8);
    pop(st);
    display(st);
    printf("Peep : %d \n", peep(st, 2));
    change(st, 2, 99);
    display(st);
}