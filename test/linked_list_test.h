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
#include <check.h>

#include "../src/LinkedList/linked_list.h"

START_TEST(test_linkedList_make) {
    pLinkedList newList = NULL;

    newList = makeList();

    ck_assert_ptr_nonnull(newList);

    destroyList(&newList);
  } END_TEST

START_TEST(test_linkedList_appendToList) {
    pLinkedList list = makeList();

    int arr[] = {5, 6, 7, 8};

    for (int i = 0; i < 4; i++)
      appendToList(list, arr[i]);

    int i = 0;
    for (pNode it = list->head; it->next != 0; it = it->next, i++)
      ck_assert_int_eq(*it->data, arr[i]);

    destroyList(&list);
  } END_TEST

START_TEST(test_linkedList_removeFront) {
    pLinkedList list = makeList();

    int arr[] = {5, 6, 7, 8};

    for (int i = 0; i < 4; i++)
      appendToList(list, arr[i]);

    for (int j = 0; j < 4; j++)
      ck_assert_int_eq(*popFront(list)->data, arr[j]);

    destroyList(&list);
  } END_TEST

START_TEST(test_linkedList_removeBack) {
        pLinkedList list = makeList();

        int arr[] = {5, 6, 7, 8};

        for (int i = 0; i < 4; i++)
            appendToList(list, arr[i]);

        for (int j = 4; j < 0; j--)
            ck_assert_int_eq(*popBack(list)->data, arr[j]);

        destroyList(&list);
    } END_TEST

START_TEST(test_linkedList_destroy) {
    pLinkedList list = makeList();

    int arr[] = {5, 6, 7, 8};

    for (int i = 0; i < 4; i++)
      appendToList(list, arr[i]);

    destroyList(&list);

    ck_assert_ptr_null(list);

  } END_TEST

Suite* linkedList_test_suite() {
    Suite *suite;
    TCase *testCaseCore;

    suite = suite_create("LinkedList");

    testCaseCore = tcase_create("Core");

  // Test cases

    tcase_add_test(testCaseCore, test_linkedList_make);
    tcase_add_test(testCaseCore, test_linkedList_appendToList);
    tcase_add_test(testCaseCore, test_linkedList_removeFront);
    tcase_add_test(testCaseCore, test_linkedList_removeBack);
    tcase_add_test(testCaseCore, test_linkedList_destroy);

    suite_add_tcase(suite, testCaseCore);

    return suite;
}
