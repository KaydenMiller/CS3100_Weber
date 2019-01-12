#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

stackT* NewStack(void)
{
    stackT* NewStack = malloc(sizeof(stackT));
    NewStack->head = NULL;

    return NewStack;
}

void Push(stackT* stack, valueT value)
{
    nodeT* node = malloc(sizeof(nodeT));
    node->value = value;
    node->next = NULL;

    node->next = stack->head;

    stack->head = node;
}

valueT Pop(stackT* stack)
{
    if (IsEmpty(stack))
    {
        printf("ERROR: Stack is empty!\n");
        return 0;
    }

    nodeT* temp = stack->head;
    valueT value = temp->value;

    stack->head = stack->head->next;

    free(temp);
    return value;
}

void EmptyStack(stackT *stack)
{
    if (stack->head == NULL)
    {
        printf("Stack is empty already!\n");
    }
    else
    {
        nodeT* temp;
        nodeT* kill;
        temp = stack->head;
        while (temp != NULL)
        {
            kill = temp;
            temp = temp->next;
            free(kill);
        }
        stack->head = NULL;
    }
}

void FreeStack(stackT* stack)
{
    if (stack->head != NULL)
    {
        printf("ERROR: Stack is not empty!\n");
        return;
    }

    stack = NULL;
    free(stack);
}

bool IsEmpty(stackT* stack)
{
    if (stack->head == NULL)
        return true;
    else 
    {        
        return false;
    }
}