/* *
 * MIT License
 *
 * Copyright (c) 2017 Elmer Melendez
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

#include <stdio.h>
#include <check.h>
#include "../src/Stack/stack.h"

START_TEST(test_stack_make) {
    pStack stack = makeStack();

    ck_assert_ptr_nonnull(stack);
    ck_assert_int_eq(stackSize(stack), 0);

    destroyStack(&stack);

} END_TEST

START_TEST(test_stack_pushStack) {
    pStack stack = makeStack();

    ck_assert_int_eq(pushStack(stack, 5), 1);
    ck_assert_int_eq(pushStack(stack, 9), 2);
    ck_assert_int_eq(pushStack(stack, 3), 3);

    destroyStack(&stack);
    stack = NULL;

    ck_assert_int_eq(pushStack(stack, 4), 0);

  } END_TEST

START_TEST(test_stack_popStack) {
    pStack stack = makeStack();

    pushStack(stack, 5);
    pushStack(stack, 9);
    pushStack(stack, 3);

    T* value = NULL;

    value = popStack(stack);
    ck_assert_ptr_nonnull(value);
    ck_assert_int_eq(*value, 3);
    value = NULL;

    value = popStack(stack);
    ck_assert_ptr_nonnull(value);
    ck_assert_int_eq(*value, 9);
    value = NULL;

    value = popStack(stack);
    ck_assert_ptr_nonnull(value);
    ck_assert_int_eq(*value, 5);
    value = NULL;

    value = popStack(stack);
    ck_assert_ptr_null(value);
    value = NULL;

    destroyStack(&stack);
  } END_TEST

START_TEST(test_stack_size) {
    pStack stack = makeStack();

    pushStack(stack, 4);
    pushStack(stack, 4);
    pushStack(stack, 4);
    pushStack(stack, 4);
    pushStack(stack, 4);

    ck_assert_int_eq(stackSize(stack), 5);

    destroyStack(&stack);
  } END_TEST

START_TEST(test_stack_destroy) {
    pStack stack = makeStack();

    pushStack(stack, 4);
    pushStack(stack, 4);
    pushStack(stack, 4);
    pushStack(stack, 4);
    pushStack(stack, 4);

    ck_assert_int_eq(stackSize(stack), 5);

    destroyStack(&stack);

    ck_assert_ptr_null(stack);
  } END_TEST

Suite* stack_test_suite() {
  Suite *suite;
  TCase *testCaseCore;

  suite = suite_create("Stack");

  testCaseCore = tcase_create("Core");

  // Add test cases
  tcase_add_test(testCaseCore, test_stack_make);
  tcase_add_test(testCaseCore, test_stack_pushStack);
  tcase_add_test(testCaseCore, test_stack_popStack);
  tcase_add_test(testCaseCore, test_stack_size);
  tcase_add_test(testCaseCore, test_stack_destroy);

  suite_add_tcase(suite, testCaseCore);

  return suite;
}
