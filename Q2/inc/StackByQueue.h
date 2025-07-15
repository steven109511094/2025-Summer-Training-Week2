#ifndef _STACK_BY_QUEUE_H_
#define _STACK_BY_QUEUE_H_

#include <iostream>
#include <limits.h>

#include "Queue.h"

using namespace std;

//=============================================================//
//  You shouldn't delete anything existed.                     //
//  If necessary, you can add new members but no more queues.  //
//  BTW, no STL container is allowed in this exercise.         //
//  For more information, please refer to myStack.cpp.         //
//=============================================================//

class StackByQueue{
private:
    Queue myQueue;

public:
    StackByQueue();
    ~StackByQueue();

    void push(const int& x);    // Insert one element at the top
    bool pop();                 // Erase the top element
    int top();                  // Get the data of the top element
    bool empty();               // Judge if this container is empty
};


#endif