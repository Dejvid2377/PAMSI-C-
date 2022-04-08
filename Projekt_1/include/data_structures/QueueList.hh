#ifndef QUEUE_LIST_HH
#define QUEUE_LIST_HH
#include "libraries.hh"
#include "SinglyLinkedList.hh"

template<typename T>
class QueueList {
      SinglyLinkedList<T> list;
    public:
      QueueList() {;}
      ~QueueList() {;}
      void enqueue(const T& newElement) { this->list.addBack(newElement); }
      void dequeue() { this->list.removeFront(); }
      const T& front() { return this->list.front(); }
      const bool empty() const { return (this->list.empty()==1); }
      const size_t queueSize() { return this->list.size(); }
};


#endif