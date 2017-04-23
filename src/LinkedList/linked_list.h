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
#ifndef C_DSTRUCT_LINKED_LIST_H
#define C_DSTRUCT_LINKED_LIST_H

typedef int T;

typedef struct Node Node;
typedef Node* pNode;

struct Node {
  T* data;
  pNode next;
};

typedef struct LinkedList LinkedList;
typedef LinkedList* pLinkedList;

struct LinkedList {
  pNode head;
  unsigned int size; // NOTE: 4 more bytes no really necessary, but for
  // looping and perfomace
};

// Create Linked List and initialize it. O(1) computation.
pLinkedList makeList();

// Insert data to the list. O(n) computation. Why?
unsigned int appendToList(pLinkedList linkedList, T data);

// Remove the front node and returns it. O(1) computation
pNode popFront(pLinkedList linkedList);

// Destroy a LinkedList. Notice that we are taking a pointer to a pLinkedList
// O(n) computation. Why?
void destroyList(pLinkedList *linkedList);

#endif //C_DSTRUCT_LINKED_LIST_H
