#ifndef SORTING_ALGORITHMS_HEAPSORT_H
#define SORTING_ALGORITHMS_HEAPSORT_H
#include "Heap.hh"
#include "libraries.hh"

// sortowanie przez kopcowanie

template<typename T>
class HeapSort {
  public:
    HeapSort() {;}
    void sort(typename vector<T>::iterator begin, typename vector<T>::iterator end)
    {
      size_t lenght = distance(begin,end);
      Heap<int> heapp(lenght);
      typename vector<T>::iterator element = begin;

      while (element != end)
        heapp.insert(*element++);
      element--;

      while(element != begin-1)
      {
        *element = heapp.removeMax();
        element--;
      }
    }
};

#endif //SORTING_ALGORITHMS_HEAPSORT_H
