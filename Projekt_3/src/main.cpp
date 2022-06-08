#include "graph.hpp"
#include "adjacency_list_graph.hpp"
#include "adjacency_matrix_graph.hpp"
#include "shortest_path_algorithms.hpp"
#include "libraries.hh"
using ShortestPathResult = std::map<int, std::pair<int, std::vector<int>>>;

int main ()
{   
    AdjacencyListGraph<int> adj;
    ifstream in("test.txt");
    if(!in)
        cout << "nie ma takiego pliku" << endl;
    
    auto graphPtr = adj.createGraph(in);
    auto ptr = graphPtr->vertexID(7);
    ShortestPathResult result;
    dijkstra(*graphPtr,8,result);
    //map<int,pair<int,vector<int>>> result;
    //vector<int> v {1,2,3};
    //result.insert( { ptr->return_value(), make_pair(29 , v)}); 
    for(map<int,pair<int,vector<int>>>::const_iterator it = result.begin();it!=result.end();it++ )
    {
       cout << it->first <<" ";
       cout << it->second.first << " ";
       for (auto x : it->second.second)
        cout << x << " ";
       cout << endl;
    }
/*
    shared_ptr<Vertex<int>> Array[graphPtr->return_vAmount()];
    list<shared_ptr<Vertex<int>>> lst = graphPtr->vertices();
    auto iter = lst.begin();
    for (int i=0;iter!=lst.end();iter++,i++)
        Array[i] = *iter;

    for (auto x : Array)
      cout << x->return_value() << " ";
    cout << endl;

    auto iter2 = lst.begin();
    lst.erase(iter2);

    for (auto x : Array)
      cout << x->return_value() << " ";
    cout << endl;
*/
//using results =  map<typename list<shared_ptr<Vertex<int>>>::iterator, pair <int, shared_ptr<Vertex<int>>>>;

/*
//vector<iteratorow> iterV;
//vector<poprzednikow> prevV;
vector<int> indexV {1,5,6,7,8};
vector<int> costs {3,5,0,2,10,12,4,0,21,5};
int cost,index,i;
auto iterek = indexV.begin();

while (!indexV.empty())
{
    cost =__INT32_MAX__; 
    index=0;
    i = 0;
    for(auto iter=indexV.begin();iter!=indexV.end();++iter)
    {   
        int & value = *iter;

        if(costs[value] < cost)
        {
            cost = costs[value];
            index = value;
            iterek = iter;
        }
    }
    cout <<"cost: " <<cost << " " <<"index: "<< index << endl;
    indexV.erase(iterek);
}
*/
/*
    ShortestPathResult result;
    vector<vector <int>> v (10);
    result.insert({  80   ,  make_pair(99,v[0])     });
    cout<< (result[80]).first << endl;
    result[80].first = 20;
    cout<< (result[80]).first << endl;
   // cout << j.first << endl;
*/
    return 0;
}

// 0 5 6 7 4 1 9 8 2 3


/*
//inicjalizacja mapy dla wszystkich wierzcholkow, pierwsz korekta odleglosci dla wierzcholka startowego
    for(int i=0 ; iter!=waitingV.end(); iter++,i++)
      result.insert({ (*iter)->return_value() ,make_pair(INT32_MAX,v[i]) });
    result[sourceIndex].first = 0;
    result[sourceIndex].second.push_back(-1);
*/
