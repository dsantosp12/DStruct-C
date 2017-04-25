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
#include "queue_test.h"
#include "linked_list_test.h"

int main() {

  int numberFailed = 0;

  // Queue Suite
  Suite* queueSuite = queue_test_suite();
  SRunner* queueSuiteRunner = srunner_create(queueSuite);

  srunner_run_all(queueSuiteRunner, CK_NORMAL);
  numberFailed += srunner_ntests_failed(queueSuiteRunner);
  srunner_free(queueSuiteRunner);

  // LinkedList Suite
  Suite* linkedListSuite = linkedList_test_suite();
  SRunner* linkedListRunner = srunner_create(linkedListSuite);

  srunner_run_all(linkedListRunner, CK_NORMAL);
  numberFailed += srunner_ntests_failed(linkedListRunner);
  srunner_free(linkedListRunner);

  return (numberFailed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}