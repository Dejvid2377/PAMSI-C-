#ifndef HEAP_HH
#define HEAP_HH
#include "libraries.hh"

template <typename T>
class Heap {
    T* Array;
    size_t heap_size, capacity;
  protected:
    size_t parent_loc (size_t index);
    size_t lchild_loc (size_t index); 
    size_t rchild_loc (size_t index);
  public:
    Heap() {heap_size = {0}; capacity = {10}; Array = new T [capacity];}
    explicit Heap(size_t initial_capacity);
    ~Heap() { delete[] this->Array; }
    void insert(const T& newElement);
    size_t change_position(size_t parent);
    T& removeMax();
    size_t size() { return this->heap_size; }
    bool empty() { return (this->heap_size == 0 );}
    bool full() { return (this->heap_size == this->capacity );}
    void heapExtend();
    void show_heap();
    T& operator[](int index);
};

template<typename T>
Heap<T>::Heap(size_t initial_capacity)
{
    heap_size = 0;
    capacity = initial_capacity;
    Array = new T [capacity];
    for (int i=0;i<capacity;i++)
      Array[i] = 0;
}

template<typename T>
size_t Heap<T>::parent_loc(size_t index)
{
  if (index==1)
    return 0;
  else
    return index/2;
}

template<typename T>
size_t Heap<T>::lchild_loc(size_t index)
{
  if (heap_size < 2 || index*2 > capacity)
    return 0;
  else 
    return index*2;
}

template<typename T>
size_t Heap<T>::rchild_loc(size_t index)
{
  if (heap_size < 2 || index*2+1 > capacity)
    return 0;
  else 
    return index*2+1;
}

template <typename T>
void Heap<T>::insert(const T& newElement)
{
  if (!this->full())
  {
    Array[heap_size++] = newElement;
    size_t parent = heap_size;
    while (parent!=1 )
      parent = parent_loc(change_position(parent));
  }
  else
  {
    heapExtend();
    insert(newElement);
  }
}

template<typename T>
size_t Heap<T>::change_position(size_t parent)
{
    if (Array[parent_loc(parent)-1] < Array[parent-1])
    {
      T temp = Array[parent_loc(parent)-1];
      Array[parent_loc(parent)-1] = Array[parent-1];
      Array[parent-1] = temp; 
      return parent;
    }
    else  
      return 2;
}

template <typename T>
T& Heap<T>::removeMax()
{
  if (!empty())
  {
    T temp = Array[0];
    Array[0] = Array[heap_size-1];
    Array[(heap_size--)-1] = temp;
    size_t parent = 1;

    while (parent*2+1 <= heap_size)
    { 
      if (Array[lchild_loc(parent)-1] >= Array[rchild_loc(parent)-1])
      {
        if (Array[lchild_loc(parent)-1] > Array[parent-1])
        {
          T temp = Array[lchild_loc(parent)-1];
          Array[lchild_loc(parent)-1] = Array[parent-1];
          Array[parent-1] = temp;
        }
        parent = lchild_loc(parent);
      }
      else
      {
        if (Array[rchild_loc(parent)-1] > Array[parent-1])
        {
          T temp = Array[rchild_loc(parent)-1];
          Array[rchild_loc(parent)-1] = Array[parent-1];
          Array[parent-1] = temp;
        }
        parent = rchild_loc(parent);
      }
    }

    if (heap_size == 2)
    {
      if (Array[lchild_loc(parent)-1] > Array[0])
      {
        T temp = Array[lchild_loc(parent)-1];
        Array[lchild_loc(parent)-1] = Array[0];
        Array[0] = temp;
      }
    }  

    //dopoki dzieci sa wieksze, zamieniaj
    return Array[heap_size];
  }
  else
  {
    cout << "Heap is empty. There is nothing to remove..";
    static T value;
    return value;
  }

}

template <typename T>
T& Heap<T>::operator[](int index)
{
  try {
    if (index <= heap_size && index!=0)
      return Array[index-1];
    else
      throw(index);
  }

  catch(...) {
    cout << "Wrong index number" << endl;
    cout << "Heap root is located in index [1]" << endl;
    cout << "Last possible index number is [" << heap_size << "] with value: ";
    return Array[heap_size-1];
  }
}

template<typename T>
void Heap<T>::show_heap()
{
  for (int i=0;i<heap_size;i++)
    cout << Array[i] << " ";
}

template<typename T>
void Heap<T>::heapExtend()
{
  cout << "Heap overloaded, making extension..." << endl;
  int newSize = 2*capacity;
  T* newArray = new T [newSize];
  for (int i=0;i<heap_size;i++)
    newArray[i] = this->Array[i];
  delete[] Array;
  Array = newArray;
  capacity = newSize;
}

#endif