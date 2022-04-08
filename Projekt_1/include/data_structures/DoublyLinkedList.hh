#ifndef DOUBLY_LINKED_LIST_HH
#define DOUBLY_LINKED_LIST_HH
#include "libraries.hh"

template <typename T>
class DoublyLinkedList {
    struct node {
      T value;
      node* next;
      node* prev;
    };
    node* head;
    node* tail;
    uint list_size = 0;
  public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    const bool empty() const { return (this->head==NULL); }
    const void write_out() const;
    const int size() const { return this->list_size; }
    void addFront(const T newElement);
    void removeFront();
    void addBack(const T newElement);
    void removeBack();
    const T& front() const;
    const T& back() const;
    //void insert(const T& newElement, int index);
    //void remove(const T& element);
    T& operator[](const uint index);
};

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
  this->head = NULL; 
  this->tail = NULL;
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
  while(!this->empty())
    this->removeFront();
}

template<typename T>
const void DoublyLinkedList<T>::write_out() const
{
  node* p = this->head;

  if (this->empty())
    cout << "Lista jest pusta";
  else {
    while (p != NULL) {
      cout << p->value << " ";
      p = p->next;
    }
  }
  cout << endl;
}

template <typename T>
void DoublyLinkedList<T>::addFront(const T newElement)
{
  node* p = new node;
  p->value = newElement;
  p->prev =  NULL;    
  
  if (this->empty()) {
    p->next =  NULL;    
    this->head = this->tail = p;
  }
  else {
    p->next = this->head;
    p->next->prev = p;
    this->head = p;
  }
  list_size++;
}

template <typename T>
void DoublyLinkedList<T>::removeFront()
{
  if(this->empty())
    cout << "Lista jest pusta" << endl;
  else {
    node* temp = this->head;
    if(this->head == this->tail)
      this->head = this->tail = NULL;
    else
      this->head = temp->next;
    delete temp;
    list_size--;
  }
}

template <typename T>
void DoublyLinkedList<T>::addBack(const T newElement)
{
    node* p = new node;
    p->value = newElement;
    p->next = NULL;
  
  if (this->empty()) {
    p->prev = NULL;
    this->head = this->tail = p;
  }
  else {
    p->prev = this->tail;
    tail->next = p;
    this->tail = p;
  }
  list_size++;
}

template <typename T>
void DoublyLinkedList<T>::removeBack()
{
  if(this->empty())
    cout << "Lista jest pusta" << endl;
  else {
    node* p = this->tail;
    if (this->head == this->tail)
      this->head = this->tail = NULL;
    else {
      this->tail = p->prev;
      p->prev->next = NULL;
    }
    delete p;
    list_size--;
  }
}

template <typename T>
const T& DoublyLinkedList<T>::front() const
{
  static T t;
  if (this->empty())
    return t;
  else
    return this->head->value;
}

template <typename T>
const T& DoublyLinkedList<T>::back() const
{
  static T t;
  if (this->empty())
    return t;
  else
    return this->tail->value;
}
/*
template <typename T>
void DoublyLinkedList<T>::insert(const T& newElement, int index)
{
    // TODO: zaimplementuj
}
template <typename T>
void DoublyLinkedList<T>::remove(const T& element)
{
    // TODO: zaimplementuj
}*/
template <typename T>
T& DoublyLinkedList<T>::operator[](const uint index)
{
  try {
    if (index<list_size) {
      node* p = this->head;
      for (uint i=0;i<index;i++) {
        p = p->next;
      }
      return p->value;
      delete p;
    }
    else {}
      throw(index);
  }

  catch(...) {
    cout << "Wrong index number" << endl;
    cout << "Last possible index number is [" << list_size-1 << "] with value: ";
    return this->tail->value;
  }
}

#endif