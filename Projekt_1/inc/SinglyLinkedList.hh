#ifndef SINGLY_LINKED_LIST_HH
#define SINGLY_LINKED_LIST_HH
#include "libraries.hh"

template <typename T>
class SinglyLinkedList {
    struct node {
      T value;
      node* next;
    };
    node* head;
    node* tail;
    inline static uint list_size = 0;
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
    T front();
    T back();
    //void insert();
    //void remove(T element);
    //void operator[]();
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
  
  if (this->empty()) {
    this->head = this->tail = p;
  }
  else {
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
  else if (this->tail==this->head) {
    delete temp;
    this->tail = this->head = NULL;
    list_size--;
  }
  else {
    while(temp->next->next) {
      temp = temp->next;
    }
    delete (temp->next);
    temp->next = NULL;
    this->tail = temp;
    list_size--;
  }
}

template<typename T>
T SinglyLinkedList<T>::front()
{
  if (this->empty())
    return 0;
  else
    return  this->head->value;
}

template<typename T>
T SinglyLinkedList<T>::back()
{
  if (this->empty())
    return 0;
  else
    return this->tail->value;
}
/*
template<typename T>
void SinglyLinkedList<T>::remove(T element)
{ 
  node* prev = this->head;
  node* next = this->head->next;

  if (this->empty())
    cout << "Lista jest pusta" << endl;
  else if (this->head==this->tail) {
    if (head->value==element) {
      this->removeFront();
      this->head = this->tail = NULL;
  }
}*/

#endif