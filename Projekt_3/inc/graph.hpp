#ifndef GRAPH_HPP_
#define GRAPH_HPP_
#include "libraries.hh"

//klasy vertex, edge i adjlist
//przeciazenie istream

template <typename T>
class Vertex {
  protected:
    T value;
    typename list<shared_ptr<Vertex<T>>>::iterator iter;
  public:
    Vertex() {}
    Vertex(T newValue): value(newValue) {}
    void set_value(const T & newValue) {value = newValue;}
    T & return_value () { return value;}
    void set_iter (auto new_iter) { iter = new_iter;}
    auto return_iter() {return iter;}
};

template <typename T>
class Edge {
  protected:
    T value; 
    shared_ptr<Vertex<T>> start;
    shared_ptr<Vertex<T>> end;
    typename list<shared_ptr<Edge<T>>>::iterator iter;
  public:
    Edge() {start = end = nullptr;}
    Edge(T newValue): value(newValue) {start=end=nullptr;}
    void set_value(const T & newValue) {value = newValue;}
    T & return_value () { return value;}
    void set_iter (auto new_iter) { iter = new_iter;}
    auto return_iter() {return iter;}
    void set_start(auto ptr) { start = ptr;}
    auto return_start() { return start; }
    void set_end(auto ptr) { end = ptr;}
    auto return_end() { return end; }

};

template<typename T>
class Graph {
  protected:
    int vAmount, eAmount;
    shared_ptr<Vertex<T>> startVertex;
    list<shared_ptr<Edge<T>>> listEdges;
    list<shared_ptr<Vertex<T>>> listVertices;
  public:
    Graph() {vAmount = 0; eAmount =0;}
    virtual list<shared_ptr<Vertex<T>>> endVertices(const shared_ptr<Edge<T>>& e); 
    virtual shared_ptr<Vertex<T>> opposite(const shared_ptr<Vertex<T>>& v,const shared_ptr<Edge<T>>& e);
    virtual const bool areAdjacent(const shared_ptr<Vertex<T>>& v,const shared_ptr<Vertex<T>>& w);
    virtual void replaceV(const shared_ptr<Vertex<T>>& v, const T& newValue) {}
    virtual void replaceE(const shared_ptr<Edge<T>>& e, const T& newValue) {}
  ///////////////////////////////////////////////////
    virtual void insertVertex(const T& newValue) {}
    virtual void insertEdge(const shared_ptr<Vertex<T>>& v,const shared_ptr<Vertex<T>>& w, const T& newValue) {}
    virtual void removeVertex(shared_ptr<Vertex<T>>& v) {}
    virtual void removeEdge(shared_ptr<Edge<T>>& e) {}
  ///////////////////////////////////////////////////
    virtual list<shared_ptr<Edge<T>>> incidentEdges(const shared_ptr<Vertex<T>>& v);
    virtual list<shared_ptr<Vertex<T>>> vertices();
    virtual list<shared_ptr<Edge<T>>> edges();
  /////////////////////////////////////////////////////  
    shared_ptr<Vertex<T>> vertexID(const T& v);
    void set_startVertex(auto newPtr) {startVertex = newPtr;}
    auto return_startVertex() {return this->startVertex;}
    void print();
    const int return_vAmount() const {return this->vAmount;}
};

template<typename T>
list<shared_ptr<Vertex<T>>> Graph<T>::endVertices(const shared_ptr<Edge<T>>& e)
{
  return this->listVertices;
}

template<typename T>
shared_ptr<Vertex<T>> Graph<T>::opposite(const shared_ptr<Vertex<T>>& v,const shared_ptr<Edge<T>>& e)
{
  return *listVertices.begin();
}

template<typename T>
const bool Graph<T>::areAdjacent(const shared_ptr<Vertex<T>>& v,const shared_ptr<Vertex<T>>& w)
{
  return false;
}

template<typename T>
list<shared_ptr<Edge<T>>> Graph<T>::incidentEdges(const shared_ptr<Vertex<T>>& v)
{
  return this->listEdges;
}

template<typename T>
list<shared_ptr<Vertex<T>>> Graph<T>::vertices()
{
  return this->listVertices;
}

template<typename T>
list<shared_ptr<Edge<T>>> Graph<T>::edges()
{
  return this->listEdges;
}

template <typename T>
shared_ptr<Vertex<T>> Graph<T>::vertexID(const T& v)
{
  typename list<shared_ptr<Vertex<T>>>::iterator verIt;  
  
  for (verIt=listVertices.begin(); verIt!=listVertices.end(); verIt++)
  {
    if( (*verIt)->return_value() == v)
      return *verIt;
  }
  
  return nullptr;
}

template <typename T>
void Graph<T>::print()
{
  typename list<shared_ptr<Edge<T>>>::iterator iter = this->listEdges.begin();

  cout << this->vAmount << " " << this->eAmount << endl;

  for (;iter!=this->listEdges.end();iter++)
  {
    cout << (*iter)->return_start()->return_value() << " ";
    cout << (*iter)->return_end()->return_value() << " ";
    cout << (*iter)->return_value() << endl;
  }
  cout << (this->startVertex)->return_value() << endl;

}

#endif