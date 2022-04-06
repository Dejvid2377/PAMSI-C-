#ifndef STACK_TAB_HH
#define STACK_TAB_HH
#include "libraries.hh"

template<typename T>
class StackTab {
    int size, t_ptr; 
    T* Array;
  public:
    StackTab() { size={10}; t_ptr={0}; Array={new T [size]}; }
    explicit StackTab(size_t initialCapacity);
    ~StackTab() { delete[] this->Array; }
    void push (const T& newElement);
    T pop();
    const T& top() { return this->Array[t_ptr-1]; }
    const bool empty()const { return (this->t_ptr==0);}
    const bool full() const { return (this->t_ptr==this->size); }
    const size_t stacksize() const { return this->t_ptr;}
    void stackExtend();
};

template<typename T>
StackTab<T>::StackTab(size_t initialCapacity)
{   
    size = initialCapacity;
    t_ptr = 0;
    Array = new T [size];
}

template<typename T>
void StackTab<T>::push(const T& newElement)
{
  if (!full())
  {
    this->Array[this->t_ptr] = newElement;
    this->t_ptr++;
  }
  else
  {
    this->stackExtend();
    push(newElement);
  }
}

template<typename T>
T StackTab<T>::pop()
{
  static T rng_value;
  if (this->empty())
  {
    cout << "Stack is empty, there is no elements to pop" << endl;
    return rng_value;
  }
  else
  {
    return this->Array[t_ptr-1];
    this->t_ptr--;
  }
}

template<typename T>
void StackTab<T>::stackExtend()
{
  cout << "Stack overloaded, making extension..." << endl;
  int newSize = 2*this->size;
  T* newArray = new T [newSize];
  for (int i=0;i<size;i++)
    newArray[i] = this->Array[i];
  delete[] Array;
  this->Array = newArray;
  this->size = newSize;
}

#endif 