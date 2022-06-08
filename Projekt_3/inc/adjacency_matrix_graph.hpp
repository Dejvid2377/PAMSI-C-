#ifndef ADJACENCY_MATRIX_GRAPH_HPP_
#define ADJACENCY_MATRIX_GRAPH_HPP_
#include "graph.hpp"

template <typename T>
class matrixVertex : public Vertex<T> {
    int key;
  public:
    matrixVertex() { key=0; } 
    matrixVertex(T newValue) : Vertex<T>(newValue) {}
    void set_key(auto new_key) { key = new_key; }
    auto return_key() { return key; }
};

template <typename T>
class AdjacencyMatrixGraph : public Graph<T> {
  private:
    shared_ptr<Edge<T>> ** Array;
    int arraySize;
    int vertexKey;
  protected:
    void extendMatrix();
    void reduceMatrix(const int & index);
    bool checkMember(const shared_ptr<Vertex<T>>& v);
  public:
    AdjacencyMatrixGraph() {arraySize=0;vertexKey=0;}
    ~AdjacencyMatrixGraph();
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
    void print_matrix();
};


template <typename T>
AdjacencyMatrixGraph<T>::~AdjacencyMatrixGraph()
{ 
  if (arraySize>0)
  {
    for (int i=0;i<arraySize;i++)
      delete[] Array[i];
    delete[] Array;
  }
}

template <typename T>
shared_ptr<Graph<T>> AdjacencyMatrixGraph<T>::createGraph(istream &is)
{
  shared_ptr<AdjacencyMatrixGraph<T>> graphPtr {new AdjacencyMatrixGraph()};
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

template<typename T>
list<shared_ptr<Vertex<T>>> AdjacencyMatrixGraph<T>::endVertices(const shared_ptr<Edge<T>>& e)
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
shared_ptr<Vertex<T>> AdjacencyMatrixGraph<T>::opposite(const shared_ptr<Vertex<T>>& v,const shared_ptr<Edge<T>>& e)
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
const bool AdjacencyMatrixGraph<T>::areAdjacent(const shared_ptr<Vertex<T>>& v,const shared_ptr<Vertex<T>>& w)
{
  auto matrixVPtr = static_pointer_cast<matrixVertex<T>>(v);
  auto matrixWPtr = static_pointer_cast<matrixVertex<T>>(w);

  auto vKey = matrixVPtr->return_key();
  auto wKey = matrixWPtr->return_key();

  if (Array[vKey][wKey] || Array[wKey][vKey])
    return true;
  else 
    return false;
}

template<typename T>
void AdjacencyMatrixGraph<T>::replaceV(const shared_ptr<Vertex<T>>& v, const T& newValue) 
{
  v->set_value(newValue);
}

template<typename T>
void AdjacencyMatrixGraph<T>::replaceE(const shared_ptr<Edge<T>>& e, const T& newValue)
{
  e->set_value(newValue);
}


template <typename T>
void AdjacencyMatrixGraph<T>::insertVertex(const T& newValue)
{
//tworzymy wskaznik na wierzcholek z wyznaczona wartoscia
    shared_ptr<matrixVertex<T>> adjPtr {new matrixVertex<T> (newValue)}; 

//ustalamy klucz indetyfikacyjny dla obiektu i zwiekszamy jego wartosc o 1
    adjPtr->set_key(vertexKey);

//powiekszamy macierz sasiedztwa (o ile nie jest to pierwsza instancja)
    this->extendMatrix();

//rzutujemy w dol wskaznik na wierzcholek, dodajemy na liste wierzcholkow bazowych
//zapisujemy wartosci pol bazowych wierzcholka  
    auto vPtr = static_pointer_cast<Vertex<T>>(adjPtr);
    this->listVertices.push_back(vPtr); 
    typename list<shared_ptr<Vertex<T>>>::iterator iter = --(this->listVertices.end());
    vPtr->set_iter(iter);
    this->vAmount++;
    vertexKey++;
}

template<typename T>
void AdjacencyMatrixGraph<T>::insertEdge(const shared_ptr<Vertex<T>>& v,
                                         const shared_ptr<Vertex<T>>& w,
                                         const T& newValue) 
{
  if (this->checkMember(v) && this->checkMember(w))
  {
//tworzymy wskaznik na krawedz z wyznaczona wartoscia, zapisujemy informacje o wierzcholkach
    shared_ptr<Edge<T>> adjPtr {new listEdge<T> (newValue)};
    auto vp = *v->return_iter();
    auto wp = *w->return_iter();
    adjPtr->set_start(vp);
    adjPtr->set_end(wp);

//rzutujemy do gory wierzcholki, wyciagamy informacje o identyfikatorach
    auto vPtr = static_pointer_cast<matrixVertex<T>>(vp);
    auto wPtr = static_pointer_cast<matrixVertex<T>>(wp);
    auto vKey = vPtr->return_key();  
    auto wKey = wPtr->return_key();

//przypisujemy wskaznik do krawedzi na odpowiednie pola macierzy sasiedztwa
//jezeli graf bylby nieskierowany to druga dyrektywa bylaby poprawna
  
    if (Array[vKey][wKey]==nullptr)
    {  
      Array[vKey][wKey] = adjPtr;
    //Array[wKey][vKey] = adjPtr;
//dodajemy krawedz na liste krawedzi
    this->listEdges.push_back(adjPtr);
    typename list<shared_ptr<Edge<T>>>::iterator edgeIter = --(this->listEdges.end());
    adjPtr->set_iter(edgeIter);
    this->eAmount++;
    }
    else 
      cout << "Edge between these vertex already exist.." << endl;
  }
  else
    cout << "This vertex is no part of graph.." << endl;
}

template<typename T>
void AdjacencyMatrixGraph<T>::removeVertex(shared_ptr<Vertex<T>>& v) 
{
//rzutujemy wskaznik w gore, uzyskujemy dostep do klucza
  auto newVPtr = static_pointer_cast<matrixVertex<T>>(v);
  auto vKey = newVPtr->return_key();

//zmniejszamy macierz sasiedztwa usuwajac wiersze i kolumny powiazane z kluczem
  this->reduceMatrix(vKey);

//redefiniujemy wartosc klucza kazdego wierzcholka nastepujacego po wierzcholku usunietym
  auto lst = this->vertices();
  typename list<shared_ptr<Vertex<T>>>::iterator it = ++(newVPtr->return_iter());
  typename list<shared_ptr<Vertex<int>>>::iterator it2 = lst.end();

  for (;*it!=*it2;it++)
  {
      auto VPtr = *it;
      auto matrixVPtr = static_pointer_cast<matrixVertex<T>>(VPtr);
      auto key = matrixVPtr->return_key();
      matrixVPtr->set_key(--key);
  }

  lst.erase(newVPtr->return_iter());
  this->vAmount--;
}

template<typename T>
void AdjacencyMatrixGraph<T>::removeEdge(shared_ptr<Edge<T>>& e) 
{
  auto startPtr = e->return_start();
  auto endPtr = e->return_end();

  auto matrixStartPtr = static_pointer_cast<matrixVertex<T>>(startPtr);
  auto matrixEndPtr = static_pointer_cast<matrixVertex<T>>(endPtr);

  Array[matrixStartPtr->return_key()][matrixEndPtr->return_key()] = nullptr;

  this->listEdges.erase(e->return_iter());
  this->eAmount--;
}

template<typename T>
list<shared_ptr<Edge<T>>> AdjacencyMatrixGraph<T>::incidentEdges(const shared_ptr<Vertex<T>>& v)
{
  list<shared_ptr<Edge<T>>> lst;
  auto matrixVertexPtr = static_pointer_cast<matrixVertex<T>>(v);
  auto key = matrixVertexPtr->return_key();

/*  krawedzie w grafie nieskierowanym
  for (int i=0;i<arraySize;i++)
  {
    if(Array[i][key]!=nullptr)
      lst.push_back(Array[i][key]);
  }
*/

  for(int j=0;j<arraySize;j++)
  {
    if(Array[key][j]!=nullptr)
      lst.push_back(Array[key][j]);
  }
  
  return lst;
}

template<typename T>
list<shared_ptr<Vertex<T>>> AdjacencyMatrixGraph<T>::vertices()
{
  return this->listVertices;
}

template<typename T>
list<shared_ptr<Edge<T>>> AdjacencyMatrixGraph<T>::edges()
{
  return this->listEdges;
}

template <typename T>
void AdjacencyMatrixGraph<T>::extendMatrix()
{
  if (!arraySize==0)
  {
    arraySize++;
    shared_ptr<Edge<T>> ** newArray = new shared_ptr<Edge<T>> * [arraySize];
    for (int i=0;i<arraySize;i++)
      newArray[i] = new shared_ptr<Edge<T>>[arraySize];
    for (int i=0;i<arraySize-1;i++){
      for(int j=0;j<arraySize-1;j++)
        newArray[i][j] = Array[i][j];
    }

    for (int i=0;i<arraySize;i++)
    {
      newArray[arraySize-1][i] = nullptr; 
      newArray[i][arraySize-1] = nullptr; 
    }

    for (int i=0;i<arraySize-1;i++)
      delete[] Array[i];
    delete[] Array;
    Array = newArray;
  }
  else
  {
    arraySize++;
    this->Array = new shared_ptr<Edge<T>> * [arraySize];
    for (int i=0;i<arraySize;i++)
      Array[i] = new shared_ptr<Edge<T>>[arraySize];
    for (int i=0;i<arraySize;i++){
      for(int j=0;j<arraySize;j++)
        Array[i][j] = nullptr;
    }  
  }  
}

template <typename T>
void AdjacencyMatrixGraph<T>::reduceMatrix(const int & index)
{
  for (int i=0;i<arraySize;i++){
    for(int j=0;j<arraySize;j++)
    {
      if ( (i==index || j==index) && Array[i][j]!=nullptr) 
      {
        this->listEdges.erase(Array[i][j]->return_iter());
        this->eAmount--;
      }
    }
  }

  arraySize--;  
  shared_ptr<Edge<T>> ** newArray = new shared_ptr<Edge<T>> * [arraySize];
  
    for (int i=0;i<arraySize;i++)
      newArray[i] = new shared_ptr<Edge<T>>[arraySize];
    for (int i=0;i<arraySize;i++) {
      for(int j=0;j<arraySize;j++)
        {
          if (i>=index && j<index)
            newArray[i][j] = Array[i+1][j];
          else if (i<index && j>=index)
            newArray[i][j] = Array[i][j+1];
          else if (i>=index && j>=index)
            newArray[i][j] = Array[i+1][j+1];
          else if (i<index && j<index)
            newArray[i][j] = Array[i][j];
        }
    }

    for (int i=0;i<arraySize+1;i++)
      delete[] Array[i];
    delete[] Array;
    Array = newArray;
}

template <typename T>
void AdjacencyMatrixGraph<T>::print_matrix()
{
  cout << "__|";
  for (int i=0;i<arraySize;i++)
    cout <<" "<< i;
  cout << endl;

  for (int i=0;i<arraySize;i++){
    cout << i << " | ";
        for(int j=0;j<arraySize;j++){
          if (Array[i][j]==nullptr)
            cout << "0 ";
          else 
            cout << "1 ";
        }
        cout <<  endl;   
  }
}

template <typename T>
bool AdjacencyMatrixGraph<T>::checkMember(const shared_ptr<Vertex<T>>& v)
{
  auto vp = *v->return_iter();
  if (vp!=nullptr)
    return true;
  else
    return false;
}


#endif /* ADJACENCY_MATRIX_GRAPH_HPP_ */
