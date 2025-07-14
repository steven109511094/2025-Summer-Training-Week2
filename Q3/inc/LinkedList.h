#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include <iostream>
#include <limits.h>

using namespace std;

//===========================================================//
//  You shouldn't delete anything existed.                   //
//  If necessary, you can add new members.                   //
//  BTW, no STL container is allowed in this exercise.       //
//  For more information, please refer to myLinkedList.cpp.  //
//===========================================================//

class LinkedList{
private:
    struct Node{
        int data;
        Node* prev;
        Node* next;
        Node() : data(0), prev(nullptr), next(nullptr) {}
        Node(int data) : data(data), prev(nullptr), next(nullptr) {}
        Node(int data, Node* prev, Node* next) : data(data), prev(prev), next(next) {}
    };

    Node* _head;
    Node* _tail;
    uint size;

public:
    LinkedList();
    ~LinkedList();

    class Iterator{
    private:
        Node* curNode;  

    public:
        Iterator();
        ~Iterator();

        const int& operator*() const;                   // Getter
        Iterator& operator++();                         // Forward iteration
        Iterator& operator--();                         // Backward iteration
        bool operator!=(const Iterator& other) const;   // Comparison between two node pointer

        friend class LinkedList;                        // For accessing private member
    };

    void push_back(const int& data);                    // Insert one element at the back of the tail element
    bool pop_back();                                    // Erase the tail element
    void insert(const Iterator& pos, const int& data);  // Insert one element at specified position
    bool erase(Iterator& pos);                          // Erase one element at specified position
    const int& front();                                 // Get the data of the head element
    const int& back();                                  // Get the data of the tail element
    bool empty();                                       // Judge if this container is empty
    void sort();                                        // Ascending order sort

    // For forward traversal
    Iterator begin();
    Iterator end();

    // For backward traversal
    Iterator rbegin();
    Iterator rend();

private:
    // More functions...
};

#endif