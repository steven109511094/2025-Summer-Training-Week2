#ifndef _QUEUE_H_
#define _QUEUE_H

#include <iostream>
#include <limits.h>

using namespace std;

//======================================================//
//  You shouldn't delete anything existed.              //
//  If necessary, you can add new members.              //
//  BTW, no STL container is allowed in this exercise.  //
//  For more information, please refer to myQueue.cpp.  //
//======================================================//

class Queue{
private:
    struct Node{
        int data;
        Node* next;
        Node() : data(0), next(nullptr){}
        Node(int data) : data(data), next(nullptr){}
        Node(int data, Node* next) : data(data), next(next){}
    };

    Node* _head;
    
public:
    Queue();
    ~Queue();

    // Help function
    void push(int data);
    bool pop();
    int front();
    bool empty();
};

#endif