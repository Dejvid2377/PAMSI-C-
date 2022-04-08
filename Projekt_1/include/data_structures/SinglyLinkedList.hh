#ifndef SINGLY_LINKED_LIST_HH
#define SINGLY_LINKED_LIST_HH
#include "libraries.hh"

/* to do
    void insert(const T& newElement, int index);
    void remove(const T& element);
*/

template <typename T>
class SinglyLinkedList {
    struct node {
      T value;
      node* next;
    };
    node* head;
    node* tail;
    uint list_size = 0;
  public:
    SinglyLinkedList();
    ~SinglyLinkedList();
    const bool empty() const { return (this->head==NULL); }
    const void write_out() const;
    const int size() const { return this->list_size; }
    void addFront(T element);
    void removeFront();
    void addBack(T element);
    void removeBack();
    const T& front() const;
    const T& back() const;
    //void insert();
    //void remove(T element);
    T & operator[](const uint &index);
};

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList()
{
  this->head = NULL; 
  this->tail = NULL;
}

template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
  while(!this->empty())
    this->removeFront();
}

template<typename T>
const void SinglyLinkedList<T>::write_out() const
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
void SinglyLinkedList<T>::addFront(T element)
{
  node* p = new node;
  p->value = element;

  if (this->empty()) {
    p->next =  NULL;
    this->head = this->tail = p;
  }
  else {
    p->next = this->head;
    this->head = p;
  }
  list_size++;
}

template <typename T>
void SinglyLinkedList<T>::removeFront()
{
  if(this->empty())
    cout << "Lista jest pusta" << endl;
  else {
    node* temp = this->head;
    if (this->head == this->tail)
      this->head = this->tail = NULL;
    else
      this->head = temp->next;
    delete temp;
    list_size--;
  }
}

template <typename T>
void SinglyLinkedList<T>::addBack(T element)
{
  node* p = new node;
  p->value = element;
  p->next = NULL;
  
  if (this->empty())
    this->head = this->tail = p;
  else 
  {
    tail->next = p;
    this->tail = p;
  }
  list_size++;
}

template <typename T>
void SinglyLinkedList<T>::removeBack()
{
  node* temp = this->head;

  if(this->empty())
    cout << "Lista jest pusta" << endl;
  else if (this->tail==this->head) 
  {
    temp = this->tail;
    this->tail = this->head = NULL;
    list_size--;
    delete temp;
  }
  else 
  {
    while(temp->next->next) { temp = temp->next; }
    delete (temp->next);
    temp->next = NULL;
    this->tail = temp;
    list_size--;
  }
}

template<typename T>
const T& SinglyLinkedList<T>::front() const
{
  static T t;
  if (this->empty())
    return t;
  else
    return this->head->value;
}

template<typename T>
const T& SinglyLinkedList<T>::back() const
{
  static T t;
  if (this->empty())
    return t;
  else
    return this->tail->value;
}

/*
template<typename T>
void SinglyLinkedList<T>::remove(T element)
{ 
  node* prev_elem = this->head;
  node* next_elem = this->head->next;

  if (this->empty())
    cout << "Lista jest pusta" << endl;
  else if (list_size==1 && this->head->value==element)
    this->removeFront();
  else 
  {
    while (next_elem->next != this->tail) 
    {
      if (next_elem->value == element)
      {
        node* temp = new node;
        temp = next_elem;
        prev_elem->next = next_elem->next;
        next_elem = next_elem->next;
        delete temp;
      }
      else  
      {
        prev_elem = prev_elem->next;
        next_elem = next_elem->next;
      }
    }
    //delete prev_elem;
    //delete next_elem;
  }
}*/

template<typename T>
T& SinglyLinkedList<T>::operator[](const uint &index)
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
    else
      throw(index);
  }

  catch(...) {
    cout << "Wrong index number" << endl;
    cout << "Last possible index number is [" << list_size-1 << "] with value: ";
    return this->tail->value;
  }
}
#endif