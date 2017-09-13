//
// Created by Elmer Melendez on 9/8/17.
//

#include "../Queue/queue.h"

#ifndef C_DSTRUCT_STACK_H
#define C_DSTRUCT_STACK_H

typedef int T;

typedef struct Stack Stack;
typedef Stack* pStack;

// Make stack

pStack makeStack(void);

// Push to stack

size_t pushStack(pStack stack, T data);

// Pop stack

T* popStack(pStack stack);

// Size of stack

size_t stackSize(pStack stack);

// Delete stack

void destroyStack(pStack* pPStack);

#endif //C_DSTRUCT_STACK_H
