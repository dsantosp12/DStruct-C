/* *
 * MIT License
 *
 * Copyright (c) 2017 Daniel Santos
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * */

#include <stdlib.h>
#include <stdio.h>
#include "queue.h"
#include "../LinkedList/linked_list.h"

struct Queue {
  pLinkedList buffer;
};

pQueue makeQueue() {
  pQueue newQueue = malloc(sizeof(Queue));
  if (newQueue == NULL) {
    printf("Malloc failed\n");
    return 0;
  }

  newQueue->buffer = makeList();

  return newQueue;
}

size_t push(pQueue queue, T data) {
  if (queue == NULL) return 0; // FAILED, returns 0.

  appendToList(queue->buffer, data);

  return queue->buffer->size;
}

T* pop(pQueue queue) {
  if (queue == NULL) return NULL; // No Queue

  pNode front = popFront(queue->buffer);

  if (front == NULL) return NULL; // Nothing in the queue

  return front->data;
}

size_t queueSize(pQueue queue) {
  return queue->buffer->size;
}

void destroyQueue(pQueue* pPqueue) {
  if (pPqueue == NULL) return; // Nothing here.

  pQueue queue = *pPqueue;

  destroyList(&queue->buffer);
  queue->buffer = NULL;

  free(queue);
  *pPqueue = NULL;
  pPqueue = NULL;
  queue = NULL;
}

