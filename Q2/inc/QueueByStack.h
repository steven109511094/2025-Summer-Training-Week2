#ifndef _QUEUE_BY_STACK_H_
#define _QUEUE_BY_STACK_H_

#include <iostream>
#include <limits.h>

#include "Stack.h"

using namespace std;

//============================================================//
//  You shouldn't delete anything existed.                    //
//  If necessary, you can add new members but no more stacks. //
//  BTW, no STL container is allowed in this exercise.        //
//  For more information, please refer to myQueue.cpp.        //
//============================================================//

class QueueByStack{
private:
    Stack myStack1;
    Stack myStack2;
    
public:
    QueueByStack();
    ~QueueByStack();

    // Help function
    void push(const int& data);     // Insert one element at the back
    bool pop();                     // Erase the front element
    int front();                    // Get the data of the front element
    bool empty();                   // Judge if this container is empty
};

#endif