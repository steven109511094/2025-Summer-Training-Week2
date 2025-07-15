2025-Summer-Training-Week2
===

Introduction
---

This week's training content is related to class & pointer.

The exercise is intended to enhance students' understanding of classes and their proficiency with pointers by implementing an STL-like container through imitation.

Additionally, to increase the level of challenge, constraints from data structures and considerations of algorithmic complexity were incorporated.

The exercise is divided into the following three parts:

Specification
---
### Q1: Basic Stack and Queue
Stack: LIFO (Last In First Out)

| Function | Specification |
| :-- | :--  |
| `void` push(const int & *data*) | Insert 1 element with *data* at the top. |
| `bool` pop() | If there is no element in this container, return false. <br> Otherwise, erase 1 element at the top and return true.|
| `int` top() | If there is no element in this container, return INT_MIN. <br> Otherwise, return the data of the top element.|
| `bool` empty() | If there is no element in this container, return true. <br> Otherwise, return false.|

Queue: FIFO (First In First Out)

| Function | Specification |
| :-- | :--  |
| `void` push(const int & *data*) | Insert 1 element with *data* at the front. |
| `bool` pop() | If there is no element in this container, return false. <br> Otherwise, erase 1 element at the front and return true.|
| `int` front() | If there is no element in this container, return INT_MIN. <br> Otherwise, return the data of the front element.|
| `bool` empty() | If there is no element in this container, return true. <br> Otherwise, return false.|

:::danger
Constraint:
1. No STL container is allowed.
2. All operations must have a time complexity of O(1).
:::

### Q2: Advanced Stack and Queue
This part is generally similar to Q1, except that you are required to implement a **queue using stacks** and a **stack using queues**.

:::danger
Constraint:
1. No STL container is allowed.
2. When implementing `QueueByStack`, you should amortize each operation to time complexity of O(1).
3. When implementing `StackByQueue`, you are only allowed to use a single queue.
:::

### Q3: Doubly Linked List 
Doubly linked list: 

| Function | Specification |
| :-- | :--  |
| `void` push_back(const int & *data*) | Insert 1 element with *data* at the back |
| `bool` pop_back() | If there is no element in this container, return false. <br> Otherwise, erase 1 element at the back and return false.|
| `void` insert(const Iterator& *pos*, const int & *data*) | Insert 1 element at the designated position *pos*. <br> If *pos* is out of this container, insert the element at the back.|
| `bool` erase(Iterator& *pos*) | If there is no element at the designated position *pos*, return false. <br> Otherwise, erase the element at the position and return true.|
| `const int&` front() | If there is no element in this container, return INT_MIN. <br> Otherwise, return the data of the front element.|
| `const int&` back() | If there is no element in this container, return INT_MIN. <br> Otherwise, return the data of the back element.|
| `bool` empty() | If there is no element in this container, return true. <br> Otherwise, return false.|
| `void` sort() | Ascending-order sort all elements in this container.|

Iterator:
| Function | Specification |
| :-- | :--  |
|`const int&` operator*() const | If the iterator point to `nullptr`, return INT_MIN. <br> Otherwise, return the data of the element pointed by the iterator.|
|`Iterator&` operator++() | Let the iterator point to next element.|
|`Iterator&` operator- -() | Let the iterator point to previous element.|
|`bool` operator!=(const Iterator& other) const | If the two iterator point to 2 different elements, return true. <br> Otherwise, return false.|

:::danger
Constraint:
1. No STL container is allowed.
2. The sort operation should have a time complexity of O(nlogn) and a space complexity of O(1).
:::

Execution
---
### Q1: Basic Stack and Queue
Stack:
1. make stack
2. ./myStack
3. make check_stack_ans
4. make check_stack_mem

Queue:
1. make queue
2. ./myQueue
3. make check_queue_ans
4. make check_queue_mem

### Q2: Advanced Stack and Queue
Stack:
1. make stack
2. ./myStack
3. make check_stack_ans
4. make check_stack_mem

Queue:
1. make queue
2. ./myQueue
3. make check_queue_ans
4. make check_queue_mem

### Q3: Doubly Linked List
1. make
2. ./myLinkedList
3. make check_ans
4. make check_mem

:::success
You can modify gen_pattern.cpp in each part and run command "make gen_pattern" in terminal for more patterns.
:::

# Have fun \!\!\!\!\!
![114514](Image/114514.jpg)
