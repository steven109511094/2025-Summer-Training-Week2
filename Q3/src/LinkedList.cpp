#include "LinkedList.h"

LinkedList::LinkedList(){
}

LinkedList::~LinkedList(){
}

void LinkedList::push_back(const int& data){
}

bool LinkedList::pop_back(){
}

void LinkedList::insert(const Iterator& pos, const int& data){
}

bool LinkedList::erase(Iterator& pos){
}

const int& LinkedList::front(){
}

const int& LinkedList::back(){
}

bool LinkedList::empty(){
}

void LinkedList::sort(){
}

LinkedList::Iterator LinkedList::begin(){
}

LinkedList::Iterator LinkedList::end(){
}

LinkedList::Iterator LinkedList::rbegin(){
}

LinkedList::Iterator LinkedList::rend(){
}

// Iterator
LinkedList::Iterator::Iterator(){
}

LinkedList::Iterator::~Iterator(){
}

const int& LinkedList::Iterator::operator*() const{
}

LinkedList::Iterator& LinkedList::Iterator::operator++(){
}

LinkedList::Iterator& LinkedList::Iterator::operator--(){
}

bool LinkedList::Iterator::operator!=(const Iterator& other) const{
}