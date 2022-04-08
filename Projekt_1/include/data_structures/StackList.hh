#ifndef STACK_LIST_HH
#define STACK_LIST_HH
#include "libraries.hh"
#include "DoublyLinkedList.hh"

template<typename T>
class StackList {
    DoublyLinkedList<T> list;
  public:
    StackList() {;}
    ~StackList() {;}
    void push (const T& newElement) { this->list.addBack(newElement); }
    void pop() { this->list.removeBack(); } 
    void write_out() const { this->list.write_out(); }
    const T& top() { return this->list.back(); }
    const bool empty() const { return (this->list.empty()==1);}
    const size_t stackSize() const { return this->list.size(); }
};

#endif