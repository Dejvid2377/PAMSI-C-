#ifndef SHORTEST_PATH_ALGORITHMS_HPP_
#define SHORTEST_PATH_ALGORITHMS_HPP_

#include "graph.hpp"
#include "adjacency_list_graph.hpp"
#include "adjacency_matrix_graph.hpp"
#include "Heap.hh"
#include "libraries.hh"

int findVertex (vector<shared_ptr<Vertex<int>>> vec, shared_ptr<Vertex<int>> vert)
{
  vector<shared_ptr<Vertex<int>>>::iterator iter = vec.begin();
  for(int i=0;iter!=vec.end();i++,iter++)
  {
    if (vert==*iter)
      return i;
  }

  return -1;
}

/*
 * Klucz slownika to indeks wierzchołka końcowego
 * Wartość to std::pair, która zawiera:
 *   first - całkowita długość ścieżki
 *   second - wektor indeksów wierzchołków ze źródła do wirzechołka końcowego
 */
using ShortestPathResult = std::map<int, std::pair<int, std::vector<int>>>;

void dijkstra(Graph<int>& graph, int sourceIndex, ShortestPathResult& result)
{
  auto startVertex = graph.vertexID(sourceIndex);
  list<shared_ptr<Vertex<int>>> vertices = graph.vertices();
  typename list<shared_ptr<Vertex<int>>>::iterator verticeIter = vertices.begin();
  int size = graph.return_vAmount();
  int index, length;

  vector<int> indexV (size);
  for (int i=0; i<size;i++)
    indexV[i] = i;
  vector<int> costs (size,INT32_MAX);
  vector<shared_ptr<Vertex<int>>> prevElem (size,nullptr);
  vector<shared_ptr<Vertex<int>>> allVerts (size);
  for (int i=0;verticeIter!=vertices.end();verticeIter++,i++)
    allVerts[i] = *verticeIter; 
  vector <bool> attend (size,true);
  
  typename vector<int>::iterator indexIter = indexV.begin();
  index = findVertex(allVerts,startVertex);

  costs[index] = 0;

  while (!indexV.empty())
  {
    index = 0;
    length = INT32_MAX;

//przeszukiwanie tablicy kosztow tylko dla wierzcholkow nieprzetworzonych
    for (vector<int>::iterator iter = indexV.begin();iter!=indexV.end();++iter)
    {
      int & getIndex = *iter;
      
      if(costs[getIndex] < length)
      {
        length = costs[getIndex];
        index = getIndex;
        indexIter = iter;
      }
    }
//usuwamy "index" wierzcholka ktory nie bedzie juz rozpatrywany   
    indexV.erase(indexIter);
    attend[index] = false;
    auto ptr = allVerts[index];
    
    auto lst = graph.incidentEdges(ptr);

    while (!lst.empty())
    {
      list<shared_ptr<Edge<int>>>::iterator iter = lst.begin();
      auto oppst = graph.opposite(ptr,(*iter));
      int newindex = findVertex(allVerts,oppst);

      if (attend[newindex])
      {
        if(costs[newindex] > (costs[index]+(*iter)->return_value()))
        {
          costs[newindex] = costs[index]+ (*iter)->return_value();
          prevElem[newindex] = ptr;
        }
      }
      lst.erase(iter);
    }
  }

  for(int i=0;i<size;i++)
  {
    vector <int> v;
    v.push_back(allVerts[i]->return_value());
    shared_ptr<Vertex<int>> ptr = prevElem[i];
    while (ptr)
    {
      v.insert(v.begin(),ptr->return_value());
      index = findVertex(allVerts,ptr);
      ptr = prevElem[index];
    }
    result.insert( { allVerts[i]->return_value(), make_pair(costs[i] , v)}); 
  }
}

bool bellmanFord(Graph<int>& graph, int sourceIndex, ShortestPathResult& result)
{
  auto startVertex = graph.vertexID(sourceIndex);
  list<shared_ptr<Vertex<int>>> vertices = graph.vertices();
  list<shared_ptr<Edge<int>>> edges = graph.edges();
  typename list<shared_ptr<Vertex<int>>>::iterator verticeIter = vertices.begin();
  int size = graph.return_vAmount();
  bool test;
  int index;

  vector<int> costs (size,10000);
  vector<shared_ptr<Vertex<int>>> prevElem (size,nullptr);
  vector<shared_ptr<Vertex<int>>> allVerts (size);
  for (int i=0;verticeIter!=vertices.end();verticeIter++,i++)
    allVerts[i] = *verticeIter; 
  
  index = findVertex(allVerts,startVertex);
  costs[index] = 0;

  for (int i=0 ; i<size ; i++)
  { 
    test = true;
    
    for (typename list<shared_ptr<Edge<int>>>::iterator edgeIter = edges.begin();edgeIter!=edges.end();edgeIter++)
    {
      auto edgeValue = (*edgeIter)->return_value();
      auto start = (*edgeIter)->return_start();
      auto startIndex = findVertex(allVerts,start);
      auto end = (*edgeIter)->return_end();
      auto endIndex = findVertex(allVerts,end);

      if( costs[endIndex] > (edgeValue + costs[startIndex]))
      {
        costs[endIndex] = costs[startIndex] + edgeValue;
        prevElem[endIndex] = start;
        test = false;
      }
    } 

    if(i == (size-1))
      return true;
    
    if(test)
    {
      test = false;
      break;
    }  
  }

  index = findVertex(allVerts,startVertex);
  prevElem[index] = nullptr;

  for(int i=0;i<size;i++)
  {
    vector <int> v;
    v.push_back(allVerts[i]->return_value());
    shared_ptr<Vertex<int>> ptr = prevElem[i];
    
    while (ptr)
    {  
      v.insert(v.begin(),ptr->return_value());
      index = findVertex(allVerts,ptr);
      ptr = prevElem[index];
    }
    result.insert( { allVerts[i]->return_value(), make_pair(costs[i] , v)}); 
  }
  return test;
}







#endif /* SHORTEST_PATH_ALGORITHMS_HPP_ */
