#ifndef SORTING_ALGORITHMS_MERGESORT_H
#define SORTING_ALGORITHMS_MERGESORT_H
#include "libraries.hh"
// sortowanie przez scalanie

template <typename T>
class MergeSort {
  public:
    MergeSort() {;}
    void sort(typename vector<T>::iterator start ,typename vector<T>::iterator end);
    void merge(typename vector<T>::iterator begin, typename vector<T>::iterator mid, typename vector<T>::iterator end);
};

template <typename T>
void MergeSort<T>::sort(typename vector<T>::iterator start ,typename vector<T>::iterator end)
{
  int lenght = distance(start,end);

    if (lenght <= 1)
        return;
    
    typename vector<T>::iterator mid  = start + lenght/2; 

    sort(start,mid); 
    sort(mid,end);
    merge(start,mid,end); 
}

template <typename T>
void MergeSort<T>::merge(typename vector<T>::iterator begin, typename vector<T>::iterator mid, typename vector<T>::iterator end)
{
    typename vector<T>::iterator left = begin;
    typename vector<T>::iterator right = mid;
    vector<T> temp;
    temp.reserve(distance(begin,end));

    while (left!=mid && right!=end) 
    {
        if( *(left) < *(right))
          temp.push_back(*left++);
        else
          temp.push_back(*right++);
    };
  
    temp.insert(temp.end(),left,mid);
    temp.insert(temp.end(),right,end);
    move(temp.begin(),temp.end(),begin);
}
#endif //SORTING_ALGORITHMS_MERGESORT_H
