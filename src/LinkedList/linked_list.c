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
#include "linked_list.h"

pLinkedList makeList() {
  // Allocate enough space for a linked list, but malloc return a (void*)
  // We need to cast it to a pLinkedList.
  pLinkedList linkedList = (pLinkedList) malloc(sizeof(LinkedList));
  if (linkedList == NULL) {
    printf("Malloc failed\n");
    return 0;
  }

  // HOLY GRAIL STUFFS: Initialize everything!
  linkedList->head = NULL;
  linkedList->size = 0;

  return linkedList;
}

size_t appendToList(pLinkedList linkedList, T data) {

  if (linkedList == NULL) return 0; // Failed, bye, linked list invalid

  // Because we are definitely appending a Node, lets make it.
  pNode newNode = (pNode) malloc(sizeof(Node));
  if (newNode == NULL) {
    printf("Malloc failed\n");
    return 0;
  }
  newNode->next = NULL;
  newNode->data = (T*) malloc(sizeof(T));
  if (newNode->data == NULL) {
    printf("Malloc failed\n");
    return 0;
  }
  *newNode->data = data;

  pNode head = linkedList->head;

  if (head == NULL) {  // Nothing in the list, so lets putt it on the head
    linkedList->head = newNode;
  } else { // Nodes in the list, lets go to the last node
    pNode current = head;

    while (current->next != NULL) current = current->next;

    // At this point we are at the last node.
    current->next = newNode;
  }

  linkedList->size++;

  return 1; // Success!
}

pNode popFront(pLinkedList linkedList) {
  if (linkedList == NULL) return NULL; // No linked list
  if (linkedList->head == NULL) return NULL; // Nothing in the list

  pNode front = linkedList->head;

  linkedList->head = linkedList->head->next;
  linkedList->size--;

  front->next = NULL;

  return front;
}

pNode popBack(pLinkedList linkedList) {
  if (linkedList == NULL) return NULL; // No linked list
  if (linkedList->head == NULL) return NULL; // Nothing in the list
  pNode back;


  if(linkedList->head->next == NULL)
  {
      back = linkedList->head;
      linkedList->head = NULL;
  }
  else
  {
      pNode current = linkedList->head;

      // Go to the second to last node
      while(current->next->next != NULL)
      {
          current = current->next;
      }

      back = current->next;
      current->next = NULL;
  }

  linkedList->size--;

  return back;
}

void destroyList(pLinkedList *pPLinkedList) {
  if (pPLinkedList == NULL) return; // Is this even a thing?

  pLinkedList linkedList = *pPLinkedList;

  if (linkedList->head == NULL) { // Empty list...
    // Lets destroy the list!
    linkedList->size = 0;
    free(linkedList);
    linkedList = NULL;
    *pPLinkedList = NULL;
    return;
  }

  // Lets destroy the nodes.
  pNode current = linkedList->head;
  pNode next = current; // Because we want to do it efficiently! (Hopefully)

  while(current->next != NULL) {
    next = current->next; // We save the reference to the next node, so we
    // don't lose it after destroying the node.

    // Let's destroy the data inside.
    free(current->data);
    current->data = NULL;

    // Lets destroy the node itself.
    free(current);
    current = NULL;

    // Moving to the next node that we saved above.
    current = next;
  }

  // Important, last node still exists!
  free(current);
  current = NULL;

  // Lets destroy the list!
  linkedList->size = 0;
  free(linkedList);
  linkedList = NULL;
  *pPLinkedList = NULL;
}
