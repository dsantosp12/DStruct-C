//
// Created by Elmer Melendez on 9/8/17.
//

#include <stdlib.h>
#include <stdio.h>
#include "stack.h"
#include "../LinkedList/linked_list.h"


struct Stack {
 pLinkedList buffer;
};


// Make stack

pStack makeStack(void) {
    pStack stack = malloc(sizeof(Stack));
    if(stack == NULL) {
        printf("Stack was not malloced\n");
        return NULL;
    }

    stack->buffer = makeList();

    return stack;
}

// Push to stack

size_t pushStack(pStack stack, T data) {

    if(stack == NULL) {
        printf("Stack push failed\n");
        return 0;
    }

    appendToList(stack->buffer, data);
    return stack->buffer->size;

}

// Pop stack

T* popStack(pStack stack){
    if(stack == NULL) {
        return NULL;
    }
    pNode back = popBack(stack->buffer);

    if(back == NULL){
        return NULL;
    }

    return back->data;
}

// Stack Size
size_t stackSize(pStack stack) {
    return stack->buffer->size;
}

// Delete stack

void destroyStack(pStack* pPStack){
    if (pPStack == NULL) return; // Nothing here.

    pStack stack = *pPStack;

    destroyList(&stack->buffer);
    stack->buffer = NULL;

    free(stack);
    *pPStack = NULL;
    pPStack = NULL;
    stack = NULL;
}