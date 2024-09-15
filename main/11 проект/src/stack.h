#ifndef STACK_H
#define STACK_H

#define SUCCESS 0
#define FAIL -1

typedef struct Stack {
    int *data;
    int size;
    int top;
} Stack;

int stack_init(Stack *stack, int capacity);
int stack_push(Stack *stack, int value);
int stack_pop(Stack *stack, int *value);
void stack_destroy(Stack *stack);

#endif