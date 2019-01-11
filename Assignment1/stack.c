#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

stackT* NewStack(void)
{
    stackT* NewStack = malloc(sizeof(stackT));

    return NewStack;
}

void Push(stackT* stack, valueT value)
{
    printf("PUSHING!!");
    nodeT* node = malloc(sizeof(nodeT));
    node->value = value;
    if (stack->head != NULL)
        node->next = stack->head;
    else
        node->next = NULL;

    stack->head = node;
}

valueT Pop(stackT* stack)
{
    if (IsEmpty(stack))
    {
        printf("ERROR: Stack is empty!\n");
        return 0;
    }

    nodeT cur = *stack->head;

    free(stack->head);
    stack->head = cur.next;

    return cur.value;
}

void EmptyStack(stackT *stack)
{
    nodeT *pastNode = NULL;
    nodeT *curNode = NULL;

    curNode = stack->head;

    while (curNode->next != NULL)
    {
        pastNode = curNode;
        curNode = curNode->next;

        // Clean up past node
        pastNode->next = NULL;
        printf("Cleared Node: %c\n", pastNode->value);
        free(pastNode);

        
    }

    pastNode->next = NULL;
    free(pastNode);
    free(curNode);
    stack->head = NULL;
    free(stack->head);
}

void FreeStack(stackT* stack)
{
    if (stack->head == NULL)
    {
        printf("Stack->head is null! Free the stack.\n");
        //stack = NULL;
        //free(stack);
    }
    else
    {
        printf("ERROR: Stack not empty!\n");
    }
}

bool IsEmpty(stackT* stack)
{
    if (stack->head == NULL)
        return true;
    else 
    {
        if (stack->head->value == NULL)
            printf("VALUE IS NULL!");
            
        printf("Not empty! Value: %c\n", stack->head->value);
        return false;
    }
}