#include "stack.h"

#include <stdlib.h>

int stack_init(Stack *stack, int capacity) {
    if (stack == NULL || capacity <= 0) {
        return FAIL;
    }

    stack->data = (int *)malloc(sizeof(int) * capacity);
    if (stack->data == NULL) {
        return FAIL;
    }

    stack->size = capacity;
    stack->top = -1;

    return SUCCESS;
}

int stack_push(Stack *stack, int value) {
    if (stack == NULL || stack->top == stack->size - 1) {
        return FAIL;
    }

    stack->top++;
    stack->data[stack->top] = value;

    return SUCCESS;
}

int stack_pop(Stack *stack, int *value) {
    if (stack == NULL || stack->top == -1) {
        return FAIL;
    }

    *value = stack->data[stack->top];
    stack->top--;

    return SUCCESS;
}

void stack_destroy(Stack *stack) {
    if (stack == NULL) {
        return;
    }

    free(stack->data);
    stack->data = NULL;
    stack->size = 0;
    stack->top = -1;
}