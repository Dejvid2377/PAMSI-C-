#ifndef QUEUE_TAB_HH
#define QUEUE_TAB_HH
#include "libraries.hh"

template<typename T>
class QueueTab {
    int q_size, f_ptr, b_ptr;
    int array_size;
    T* Array;
  public:
    QueueTab() { q_size={0}; f_ptr={0}; b_ptr={0}; array_size={10}; Array={new T [array_size]}; }
    explicit QueueTab(size_t initialCapacity);
    ~QueueTab() { delete[] this->Array; }
    void enqueue(const T& newElement);
    T dequeue();
    const bool empty() const;
    const bool full() const;
    const size_t queueSize();
    const T& front() { return this->Array[this->f_ptr]; }
    void queueExtend();
};

template<typename T>
QueueTab<T>::QueueTab(size_t initialCapacity)
{
  q_size = 0;
  f_ptr = 0;
  b_ptr = 0;
  array_size = initialCapacity;
  Array = new T [array_size];
}

template<typename T>
const bool QueueTab<T>::empty() const
{
  return (this->f_ptr==this->b_ptr);
}

template<typename T>
const bool QueueTab<T>::full() const
{
  return ((this->b_ptr+1 == this->f_ptr) || ((this->b_ptr==this->array_size) && (this->f_ptr==0)) );
}

template<typename T>
const size_t QueueTab<T>::queueSize()
{
  this->q_size = (this->array_size-this->f_ptr+this->b_ptr)%this->array_size;
  return this->q_size;
}

template<typename T>
void QueueTab<T>::enqueue(const T& newElement)
{
  if(!this->full())
  {
    if(this->b_ptr==this->array_size)
    {
      if (this->f_ptr==this->array_size)
      { 
        this->b_ptr=0;
        this->f_ptr=0;
        this->Array[this->b_ptr] = newElement;
        b_ptr++;
      }
      else
      {
        this->b_ptr=0;
        this->Array[this->b_ptr] = newElement;
      }
    }
    else
    {
      this->Array[this->b_ptr] = newElement;
      this->b_ptr++;
    }
  }
  else
  {
    this->queueExtend();
    this->enqueue(newElement);
  }    
}

template<typename T>
T QueueTab<T>::dequeue()
{
  if(this->empty())
  {
    static T rnd_value;
    cout << "Queue is empty, there's nothing to dequeue. Returning nothing: ";
    return rnd_value;
  }
  else
  {
    T dequeue_value = Array[f_ptr];
    this->f_ptr++;
    return dequeue_value;
  }
  
}

template<typename T>
void QueueTab<T>::queueExtend()
{
  cout << "Queue overloaded, making extension..." << endl;
  int newSize = 2*this->array_size;
  T* newArray = new T [newSize];
  for (int i=0,j=f_ptr; i<this->array_size;i++,j++)
    newArray[j] = this->Array[j];
  for(int i=0;i<f_ptr;i++)
    newArray[i] = this->Array[i];
  delete[] Array;
  this->Array = newArray;
  this->array_size = newSize;
  this->f_ptr=0;
  this->b_ptr=this->array_size/2;
}
#endif