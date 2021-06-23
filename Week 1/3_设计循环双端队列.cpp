#include <iostream>

class MyCircularDeque {
   private:
    int* num;
    int maxSize;
    int size;
    int head;

   public:
    /** Initialize your data structure here. Set the size of the deque to be k.
     */
    MyCircularDeque(int k) : maxSize(k) {
        num = new int[k];
        memset(num, 0, sizeof(int) * k);
        head = 0;
        size = 0;
    }

    /** Adds an item at the front of Deque. Return true if the operation is
     * successful. */
    bool insertFront(int value) {
        if (!isFull()) {
            head = (head + maxSize - 1) % maxSize;
            num[head] = value;
            ++size;
            return true;
        } else {
            return false;
        }
    }

    /** Adds an item at the rear of Deque. Return true if the operation is
     * successful. */
    bool insertLast(int value) {
        if (!isFull()) {
            int tail = (head + size) % maxSize;
            num[tail] = value;
            ++size;
            return true;
        } else {
            return false;
        }
    }

    /** Deletes an item from the front of Deque. Return true if the operation is
     * successful. */
    bool deleteFront() {
        if (!isEmpty()) {
            head = (head + 1) % maxSize;
            --size;
            return true;
        } else {
            return false;
        }
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is
     * successful. */
    bool deleteLast() {
        if (!isEmpty()) {
            --size;
            return true;
        } else {
            return false;
        }
    }

    /** Get the front item from the deque. */
    int getFront() {
        if (!isEmpty()) {
            return num[head];
        } else {
            return -1;
        }
    }

    /** Get the last item from the deque. */
    int getRear() {
        if (!isEmpty()) {
            return num[(head + size - 1) % maxSize];
        } else {
            return -1;
        }
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() { return size == 0; }

    /** Checks whether the circular deque is full or not. */
    bool isFull() { return size == maxSize; }
};