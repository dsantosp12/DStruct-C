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

/**
 * \brief     T is the template type used in the queue. For other types
 * support, change 'int' to the type desired.
 * */
typedef int T;

typedef struct Node Node;
typedef Node* pNode;

/**
 * \brief     Declaration of the Node structure.
 * */
struct Node {
  T* data;
  pNode next;
};

typedef struct LinkedList LinkedList;
typedef LinkedList* pLinkedList;

/**
 * \brief     Declaration of the LinkedList structure.
 * */
struct LinkedList {
  pNode head;
  unsigned int size;
};

/**
 * \brief     Creates the LinkedList.
 *
 * \returns   pLinkedList
 * */
pLinkedList makeList();

/**
 * \brief     Append data to the linked list.
 *
 * \param     pLinkedList linkedList, T data
 *
 * \return    unsigned int the new size of the queue.
 * */
size_t appendToList(pLinkedList linkedList, T data);

/**
 * \brief     Remove the front node and return it.
 *
 * \param     pLinkedList linkedList
 *
 * \return    pNode the node structure.
 * */
pNode popFront(pLinkedList linkedList);

/**
 * \brief     Remove the back node and return it.
 *
 * \param     pLinkedList linkedList
 *
 * \return    pNode the node structure.
 * */
pNode popBack(pLinkedList linkedList);

/**
 * \brief     Deallocate the linkedList and its nodes.
 *
 * \param     pLinkedList* linkedList
 *
 * */
void destroyList(pLinkedList *linkedList);

#endif //C_DSTRUCT_LINKED_LIST_H
