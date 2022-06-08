#ifndef ADJACENCY_LIST_GRAPH_HPP_
#define ADJACENCY_LIST_GRAPH_HPP_
#include "graph.hpp"

//wskaznik na liste wierzcholkow incydentnych do siebie samego
template <typename T>
class listVertex : public Vertex<T> {
    shared_ptr<list<shared_ptr<Edge<T>>>> listPtr; 
  public:
    listVertex() {listPtr = nullptr;}
    listVertex(T newValue) : Vertex<T>(newValue) {}
    void set_ptr(auto new_ptr) { listPtr = new_ptr; }
    auto return_ptr() { return listPtr; }
};

template <typename T>
class listEdge : public Edge<T> {
    list<typename list<shared_ptr<Edge<T>>>::iterator> iterList;
  public:
    listEdge() {}
    listEdge(T newValue) : Edge<T>(newValue) {}
    void add_iter(auto new_iter) { iterList.push_back(new_iter); }
    auto return_iterList() { return iterList; }
};

template<typename T>
class AdjacencyListGraph : public Graph<T> {
    list<list<shared_ptr<Edge<T>>>> adjlist;
  public:
    AdjacencyListGraph() {}
    ~AdjacencyListGraph();
    virtual list<shared_ptr<Vertex<T>>> endVertices(const shared_ptr<Edge<T>>& e) override; 
    virtual shared_ptr<Vertex<T>> opposite(const shared_ptr<Vertex<T>>& v,const  shared_ptr<Edge<T>>& e) override;
    virtual const bool areAdjacent(const shared_ptr<Vertex<T>>& v,const shared_ptr<Vertex<T>>& w) override;
    virtual void replaceV(const shared_ptr<Vertex<T>>& v, const T& newValue) override;
    virtual void replaceE(const shared_ptr<Edge<T>>& e, const T& newValue) override;
  ///////////////////////////////////////////////////
    virtual void insertVertex(const T& newValue) override;
    virtual void insertEdge(const shared_ptr<Vertex<T>>& v,const shared_ptr<Vertex<T>>& w, const T& newValue) override;
    virtual void removeVertex(shared_ptr<Vertex<T>>& v) override;
    virtual void removeEdge(shared_ptr<Edge<T>>& e) override;
  ///////////////////////////////////////////////////
    virtual list<shared_ptr<Edge<T>>> incidentEdges(const shared_ptr<Vertex<T>>& v) override;
    virtual list<shared_ptr<Vertex<T>>> vertices() override;
    virtual list<shared_ptr<Edge<T>>> edges() override;
    static shared_ptr<Graph<T>> createGraph(std::istream& is);

};

template <typename T>
shared_ptr<Graph<T>> AdjacencyListGraph<T>::createGraph(istream &is)
{
  shared_ptr<AdjacencyListGraph<T>> graphPtr {new AdjacencyListGraph()};
  int eAm,aAm;
  int v1, v2, e1,start;

  is >> aAm >> eAm;

  for (int i=0; i<eAm;i++)
  {
    is >> v1 >> v2 >> e1;
    shared_ptr<Vertex<int>> ptr1 = graphPtr->vertexID(v1);
    shared_ptr<Vertex<int>> ptr2 = graphPtr->vertexID(v2);

    if (!ptr1)
    {
     graphPtr->insertVertex(v1);
     ptr1 = graphPtr->vertexID(v1);
    }
    if (!ptr2)
    {
     graphPtr->insertVertex(v2);
     ptr2 = graphPtr->vertexID(v2);
    }
        
    graphPtr->insertEdge(ptr1,ptr2,e1);
  }

  is >> start;
  shared_ptr<Vertex<T>> startV = graphPtr->vertexID(start);
  graphPtr->set_startVertex(startV);

  shared_ptr<Graph<T>> basicGraph = static_pointer_cast<Graph<T>>(graphPtr); 
  return basicGraph;
}

template <typename T>
AdjacencyListGraph<T>::~AdjacencyListGraph()
{ 
  auto lista = this->listEdges;
  typename list<shared_ptr<Edge<T>>>::iterator it = lista.begin();
  for (;it!=lista.end();it++)
    removeEdge(*it);
}

template<typename T>
list<shared_ptr<Vertex<T>>> AdjacencyListGraph<T>::endVertices(const shared_ptr<Edge<T>>& e)
{
  list<shared_ptr<Vertex<T>>> lst;

  if (!(e->return_start() == nullptr))
  {
    typename list<shared_ptr<Edge<T>>>::iterator edgIt;  
    shared_ptr<Edge<T>> ePtr;

    for (edgIt=this->listEdges.begin(); edgIt!=this->listEdges.end(); edgIt++)
    {
      if (*edgIt == e)
      {
        lst.push_back(e->return_start());
        lst.push_back(e->return_end());
      }
    }
  }
  
  return lst;
}

template<typename T>
shared_ptr<Vertex<T>> AdjacencyListGraph<T>::opposite(const shared_ptr<Vertex<T>>& v,const shared_ptr<Edge<T>>& e)
{
  if (!(e->return_start()==nullptr))
  {
    if (v == e->return_start())
      return  e->return_end();
    else if (v == e->return_end())
      return e->return_start();
    else
      return nullptr;
  }
  return nullptr;
}

template<typename T>
const bool AdjacencyListGraph<T>::areAdjacent(const shared_ptr<Vertex<T>>& v,const shared_ptr<Vertex<T>>& w)
{
  auto vPtr = static_pointer_cast<listVertex<T>>(v); // rzutowanie z Vertex na listVertex
  auto lstPtr = vPtr->return_ptr(); //uzyskanie wskaznika na swoja liste sasiedztwa
  if (!(lstPtr == nullptr))
  {
    typename list<shared_ptr<Edge<T>>>::iterator it = lstPtr->begin(); 
    for (; it!=lstPtr->end(); it++)
    {
      auto tmpVertexPtr = opposite(v,(*it));      
      if(tmpVertexPtr==w)
        return true;
    }
  }
  
  return false;
}

template<typename T>
void AdjacencyListGraph<T>::replaceV(const shared_ptr<Vertex<T>>& v, const T& newValue) 
{
  v->set_value(newValue);
}

template<typename T>
void AdjacencyListGraph<T>::replaceE(const shared_ptr<Edge<T>>& e, const T& newValue)
{
  e->set_value(newValue);
}


template <typename T>
void AdjacencyListGraph<T>::insertVertex(const T& newValue)
{
  auto ptr = this->vertexID(newValue);
  if (!ptr)
  {
//tworzymy wskaznik na wierzcholek z wyznaczona wartoscia
    shared_ptr<listVertex<T>> adjPtr {new listVertex<T> (newValue)}; 

//tworzymy nowa liste sasiedztwa przypisana do wierzcholka
//dodajemy ja do zbioru list, ustalamy jej referencje
    shared_ptr<list<shared_ptr<Edge<int>>>> lstPtr {new list<shared_ptr<Edge<int>>>()};
    this->adjlist.push_back(*lstPtr);
    adjPtr->set_ptr(lstPtr);

//rzutujemy w dol wskaznik na wierzcholek, dodajemy na liste wierzcholkow bazowych
//zapisujemy wartosci pol bazowych wierzcholka  
    auto vPtr = static_pointer_cast<Vertex<T>>(adjPtr);
    this->listVertices.push_back(vPtr); 
    typename list<shared_ptr<Vertex<T>>>::iterator iter = --(this->listVertices.end());
    vPtr->set_iter(iter);
    this->vAmount++;
  }
  else
    cout << "Vertex with this paramethers already exist..." << endl;
}

template<typename T>
void AdjacencyListGraph<T>::insertEdge(const shared_ptr<Vertex<T>>& v,
                             const shared_ptr<Vertex<T>>& w,
                             const T& newValue) 
{
//tworzymy wskaznik na krawedz z wyznaczona wartoscia, zapisujemy informacje o wierzcholkach
  shared_ptr<listEdge<T>> adjPtr {new listEdge<T> (newValue)};
  adjPtr->set_start(v);
  adjPtr->set_end(w);

//w grafie nieskierowanym zapisujemy informacje o krawedzi na obu listach sasiedztwa
//rzutujemy do dolu wierzcholki, wyciagamy informacje o wskaznikach na ich listy sasiedztwa
  auto vPtr = static_pointer_cast<listVertex<T>>(v);
  auto vListPtr = vPtr->return_ptr();  
  auto wPtr = static_pointer_cast<listVertex<T>>(w);
  auto wListPtr = wPtr->return_ptr();

//dodajemy krawedz na kazda z list i zapisujemy pozycje na ktorej sie znajduje
//na liscie iteratorow przypisanej do krawedzi
  vListPtr->push_back(adjPtr);
  typename list<shared_ptr<Edge<T>>>::iterator vIter = --(vListPtr->end()); 
  adjPtr->add_iter(vIter);  
  wListPtr->push_back(adjPtr);
  typename list<shared_ptr<Edge<T>>>::iterator wIter = --(wListPtr->end());
  adjPtr->add_iter(wIter); 

//rzutujemy krawedz w gore i dodajemy do listy krawedzi
//wskazujemy krawedzi jej pozycje na liscie
  auto edgePtr = static_pointer_cast<Edge<T>>(adjPtr);
  this->listEdges.push_back(edgePtr);
  typename list<shared_ptr<Edge<T>>>::iterator edgeIter = --(this->listEdges.end());
  edgePtr->set_iter(edgeIter);
  this->eAmount++;

}

template<typename T>
void AdjacencyListGraph<T>::removeVertex(shared_ptr<Vertex<T>>& v) 
{
//rzutujemy do dolu, uzyskujemy dostep do listy sasiedztwa wierzcholka v
  auto lstVertex = static_pointer_cast<listVertex<T>>(v);
  auto listPtr = lstVertex->return_ptr();

//ustawiamy iterator na poczatek listy sasiedztwa
  typename list<shared_ptr<Edge<T>>>::iterator iter = listPtr->begin();
  while(!listPtr->empty())
  {
//usuwamy kolejne krawedzi grafu
    this->removeEdge(*iter);
    iter = listPtr->begin();
  }
  this->vAmount--;

  
}

template<typename T>
void AdjacencyListGraph<T>::removeEdge(shared_ptr<Edge<T>>& e) 
{
//rzutujemy w gore krawedz, uzyskujemy wskazniki na wierzcholek startowy i koncowy
  auto listEdgePtr = static_pointer_cast<listEdge<T>>(e);
  auto startPtr = listEdgePtr->return_start();
  auto endPtr = listEdgePtr->return_end();

//rzutujemy w gore wierzcholki, w celu dostania sie do ich list sasiedztwa
  auto adjStartPtr = static_pointer_cast<listVertex<T>>(startPtr);
  auto adjEndPtr = static_pointer_cast<listVertex<T>>(endPtr);

//uzyskujemy wskazniki na ich listy sasiedztwa
  auto adjListStartPtr = adjStartPtr->return_ptr();
  auto adjListEndPtr = adjEndPtr->return_ptr();

//uzyskujemy dostep do listy pozycji krawedzi na kazdej z list sasiedztwa
//iteratory zawsze sa zapisywane w schemacie:
// - pierwsza pozycja listy - iterator na pozycje w liscie sasiedztwa wierzcholka startowego
// - druga pozycja listy - iterator na pozycje w liscie sasiedztwa wierzcholka koncowego
  auto listEdgeIterList = listEdgePtr->return_iterList();
  typename list<typename list<shared_ptr<Edge<T>>>::iterator>::iterator startIter = listEdgeIterList.begin();
  adjListStartPtr->erase(*startIter);
  typename list<typename list<shared_ptr<Edge<T>>>::iterator>::iterator endIter = ++listEdgeIterList.begin();
  adjListEndPtr->erase(*endIter);

//usuwamy krawedz z listy krawedzi
  this->listEdges.erase(listEdgePtr->return_iter());
  this->eAmount--;
}


template<typename T>
list<shared_ptr<Edge<T>>> AdjacencyListGraph<T>::incidentEdges(const shared_ptr<Vertex<T>>& v)
{
  auto listVertexPtr = static_pointer_cast<listVertex<T>>(v);
  auto listVertex = listVertexPtr->return_ptr();
  typename list<shared_ptr<Edge<T>>>::iterator it = listVertex->begin();
  list<shared_ptr<Edge<T>>> incidents;

  for (;it!=listVertex->end();it++)
  {
    if((*it)->return_start()==v)
      incidents.push_back(*it);
  }

  return incidents;
}

template<typename T>
list<shared_ptr<Vertex<T>>> AdjacencyListGraph<T>::vertices()
{
  return this->listVertices;
}

template<typename T>
list<shared_ptr<Edge<T>>> AdjacencyListGraph<T>::edges()
{
  return this->listEdges;
}


#endif