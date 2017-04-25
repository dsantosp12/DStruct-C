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

#include <check.h>
#include "../src/Queue/queue.h"

START_TEST(test_queue_make) {
    pQueue queue = makeQueue();

    ck_assert_ptr_nonnull(queue);
    ck_assert_int_eq(queueSize(queue), 0);

    destroyQueue(&queue);

} END_TEST

START_TEST(test_queue_push) {
    pQueue queue = makeQueue();

    ck_assert_int_eq(push(queue, 5), 1);
    ck_assert_int_eq(push(queue, 9), 2);
    ck_assert_int_eq(push(queue, 3), 3);

    destroyQueue(&queue);
    queue = NULL;

    ck_assert_int_eq(push(queue, 4), 0);

  } END_TEST

START_TEST(test_queue_pop) {
    pQueue queue = makeQueue();

    push(queue, 5);
    push(queue, 9);
    push(queue, 3);

    T* value = NULL;

    value = pop(queue);
    ck_assert_ptr_nonnull(value);
    ck_assert_int_eq(*value, 5);
    value = NULL;

    value = pop(queue);
    ck_assert_ptr_nonnull(value);
    ck_assert_int_eq(*value, 9);
    value = NULL;

    value = pop(queue);
    ck_assert_ptr_nonnull(value);
    ck_assert_int_eq(*value, 3);
    value = NULL;

    value = pop(queue);
    ck_assert_ptr_null(value);
    value = NULL;

    destroyQueue(&queue);
  } END_TEST

START_TEST(test_queue_size) {
    pQueue queue = makeQueue();

    push(queue, 4);
    push(queue, 4);
    push(queue, 4);
    push(queue, 4);
    push(queue, 4);

    ck_assert_int_eq(queueSize(queue), 5);

    destroyQueue(&queue);
  } END_TEST

START_TEST(test_queue_destroy) {
    pQueue queue = makeQueue();

    push(queue, 4);
    push(queue, 4);
    push(queue, 4);
    push(queue, 4);
    push(queue, 4);

    ck_assert_int_eq(queueSize(queue), 5);

    destroyQueue(&queue);

    ck_assert_ptr_null(queue);
  } END_TEST

Suite* queue_test_suite() {
  Suite *suite;
  TCase *testCaseCore;

  suite = suite_create("Queue");

  testCaseCore = tcase_create("Core");

  // Add test cases
  tcase_add_test(testCaseCore, test_queue_make);
  tcase_add_test(testCaseCore, test_queue_push);
  tcase_add_test(testCaseCore, test_queue_pop);
  tcase_add_test(testCaseCore, test_queue_size);
  tcase_add_test(testCaseCore, test_queue_destroy);

  suite_add_tcase(suite, testCaseCore);

  return suite;
}
