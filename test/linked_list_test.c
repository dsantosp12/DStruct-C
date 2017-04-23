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

#include <stddef.h>
#include "../src/LinkedList/linked_list.h"

// Returns 1 if passed, otherwise 0.
unsigned int makeListTest() {
  pLinkedList newList = 0;

  newList = makeList();

  if (newList == NULL) return 0;

  destroyList(&newList);
  return 1;
}

unsigned int appendToListTest() {
  pLinkedList  list = makeList();

  int arr[] = {5, 6, 7, 8};

  for (int i = 0; i < 4; i++)
    appendToList(list, arr[i]);

  int i = 0;
  for (pNode it = list->head; it->next != 0; it = it->next, i++) {
    if (*it->data != arr[i]) return 0;
  }

  destroyList(&list);
  return 1;
}

unsigned int popFrontTest() {
  pLinkedList list = makeList();

  int arr[] = {5, 6, 7, 8};

  for (int i = 0; i < 4; i++)
    appendToList(list, arr[i]);

  if (*popFront(list)->data != 5) return 0;
  if (*popFront(list)->data != 6) return 0;
  if (*popFront(list)->data != 7) return 0;
  if (*popFront(list)->data != 8) return 0;
  if (*popFront(list)->data != NULL) return 0;

  destroyList(&list);
  return 1;
}

unsigned int destroyListTest() {
  pLinkedList list = makeList();

  int arr[] = {5, 6, 7, 8};

  for (int i = 0; i < 4; i++)
    appendToList(list, arr[i]);

  destroyList(&list);

  if (list->head != NULL) return 0;
  if (list->size != 0) return 0;

  return 1;
}
