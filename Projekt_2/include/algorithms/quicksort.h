#ifndef SORTING_ALGORITHMS_QUICKSORT_H
#define SORTING_ALGORITHMS_QUICKSORT_H
#include "libraries.hh"

// quicksort

template <typename T>
class QuickSort {
  public:
    QuickSort() {;}
    void sort(typename vector<T>::iterator start,
              typename vector<T>::iterator end);
};

template <typename T>
void QuickSort<T>::sort(typename vector<T>::iterator start ,typename vector<T>::iterator end)
{
if (start<end) 
    {
        int lenght = distance(start,end);
        typename vector<T>::iterator piv  = start + rand() % (lenght);
        typename vector<T>::iterator i = start;
        typename vector<T>::iterator j = start-1;

        swap(*piv,*(end));

        while (i != (end))
        {
            if (*i > *(end))
                i++;
            else
              swap(*i++,*++j);
        };
        swap(*(j+1),*(end));

        sort(start,j); 
        sort(j+2,end);
    }
}

#endif //SORTING_ALGORITHMS_QUICKSORT_H
