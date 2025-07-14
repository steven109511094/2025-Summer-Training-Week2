#ifndef _STACK_H_
#define _STACK_H_

#include <iostream>
#include <limits.h>

using namespace std;

//======================================================//
//  You shouldn't delete anything existed.              //
//  If necessary, you can add new members.              //
//  BTW, no STL container is allowed in this exercise.  //
//  For more information, please refer to myStack.cpp.  //
//======================================================//

class Stack{
private:
    struct Node{
        int data;
        Node* prev;
        Node() : data(0), prev(nullptr){}
        Node(int data) : data(data), prev(nullptr){}
        Node(int data, Node* prev) : data(data), prev(prev){}
    };

    Node* _top;

public:
    Stack();
    ~Stack();

    // help functions
    void push(const int& data);
    bool pop();
    const int& top() const;
    bool empty();
};

#endif