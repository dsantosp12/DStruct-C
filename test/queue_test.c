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
#include "../src/Queue/queue.h"

unsigned int makeQueueTest() {
  pQueue queue = NULL;

  queue = makeQueue();

  if (queue == NULL) return 0;

  destroyQueue(&queue);
  return 1;
}

unsigned int pushTest() {
  pQueue queue = makeQueue();

  if (push(queue, 5) != 1) return 0;
  if (push(queue, 9) != 1) return 0;
  if (push(queue, 3) != 1) return 0;

  pQueue queue1 = NULL;

  if (push(queue1, 5) != 0) return 0;

  destroyQueue(&queue);
  return 1;
}

unsigned int popTest() {
  pQueue queue = makeQueue();

  push(queue, 4);
  push(queue, 2);
  push(queue, 1);

  if (*pop(queue) != 4) return 0;
  if (*pop(queue) != 2) return 0;
  if (*pop(queue) != 1) return 0;

  destroyQueue(&queue);
  return 1;
}

unsigned int queueSizeTest() {
  pQueue queue = makeQueue();

  push(queue, 4);
  push(queue, 4);
  push(queue, 4);
  push(queue, 4);
  push(queue, 4);

  if (queueSize(queue) != 5) return 0;

  destroyQueue(&queue);
  return 1;
}

unsigned int destroyQueueTest() {
  pQueue  queue = makeQueue();

  push(queue, 4);
  push(queue, 4);
  push(queue, 4);
  push(queue, 4);
  push(queue, 4);

  destroyQueue(&queue);

  if (queue != NULL) return 0;

  return 1;
}
