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
#ifndef C_DSTRUCT_QUEUE_H
#define C_DSTRUCT_QUEUE_H

/**
 * \brief     T is the template type used in the queue. For other types
 * support, change 'int' to the type desired.
 * */
typedef int T;

/**
 * \brief     A forward declaration of the queue. This gives the client
 * access to the Queue object itself without knowing the expecificts of the
 * implementation making the object opaque.
 * */
typedef struct Queue Queue;
typedef Queue* pQueue;

/**
 * \brief     Creates the queue.
 *
 * \returns   pQueue
 * */
pQueue makeQueue();

/**
 * \brief     Push a T to the queue.
 *
 * \param     pQueue queue, T data
 *
 * \return    size_t the new size of the queue.
 * */
size_t push(pQueue queue, T data);

/**
 * \brief     Remove the next item in the queue.
 *
 * \param     pQueue queue
 *
 * \return    T*, where T is the data.
 * */
T* pop(pQueue queue);

/**
 * \brief     Returns the size of the current queue
 *
 * \param     pQueue queue
 *
 * \return    size_t the size of the queue.
 * */
size_t queueSize(pQueue queue);

/**
 * \brief     Deallocates the queue and the data if any.
 *
 * \param     pQueue* pPqueue
 *
 * */
void destroyQueue(pQueue* pPqueue);

#endif //C_DSTRUCT_QUEUE_H
