#include "stack.h"

#include <assert.h>
#include <stdio.h>

int test_push(void) {
    Stack stack;
    int result = stack_init(&stack, 5);
    assert(result == SUCCESS);

    result = stack_push(&stack, 10);
    assert(result == SUCCESS);
    result = stack_push(&stack, 20);
    assert(result == SUCCESS);
    result = stack_push(&stack, 30);
    assert(result == SUCCESS);
    result = stack_push(&stack, 40);
    assert(result == SUCCESS);
    result = stack_push(&stack, 50);
    assert(result == SUCCESS);
    result = stack_push(&stack, 60);
    assert(result == FAIL);

    stack_destroy(&stack);

    return SUCCESS;
}

int test_pop(void) {
    Stack stack;
    int result = stack_init(&stack, 5);
    assert(result == SUCCESS);

    int value;

    result = stack_push(&stack, 10);
    assert(result == SUCCESS);
    result = stack_push(&stack, 20);
    assert(result == SUCCESS);

    result = stack_pop(&stack, &value);
    assert(result == SUCCESS);
    assert(value == 20);

    result = stack_pop(&stack, &value);
    assert(result == SUCCESS);
    assert(value == 10);

    result = stack_pop(&stack, &value);
    assert(result == FAIL);

    stack_destroy(&stack);

    return SUCCESS;
}

int main(void) {
    int result = SUCCESS;

    result = test_push();
    if (result == SUCCESS) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL!\n");
    }

    result = test_pop();
    if (result == SUCCESS) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }

    return result;
}
