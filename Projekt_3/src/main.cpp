#include "graph.hpp"
#include "adjacency_list_graph.hpp"
#include "adjacency_matrix_graph.hpp"
#include "shortest_path_algorithms.hpp"
#include "libraries.hh"
using ShortestPathResult = std::map<int, std::pair<int, std::vector<int>>>;

int main ()
{   
    AdjacencyMatrixGraph<int> adj;
    //AdjacencyListGraph<int> adj;
    bool test = false;
    ShortestPathResult resultDijkstra;
    ShortestPathResult resultBelllmanFord;

    ifstream in("test.txt");
    if(!in)
        cout << "nie ma takiego pliku" << endl;
    
    auto graphPtr = adj.createGraph(in);
    int start = (graphPtr->return_startVertex())->return_value();

    dijkstra(*graphPtr,start,resultDijkstra);
    test = bellmanFord(*graphPtr,start,resultBelllmanFord);

cout << "******************** DIJKSTRA *******************************************"<<endl;
    for(map<int,pair<int,vector<int>>>::const_iterator it = resultDijkstra.begin();it!=resultDijkstra.end();it++ )
    {
       cout << it->first <<" ";
       cout << it->second.first << " ";
       for (auto x : it->second.second)
        cout << x << " ";
       cout << endl;
    }  
cout << "******************** BELLMANFORD *******************************************"<<endl;

    for(map<int,pair<int,vector<int>>>::const_iterator it = resultBelllmanFord.begin();it!=resultBelllmanFord.end();it++ )
    {
       cout << it->first <<" ";
       cout << it->second.first << " ";
       for (auto x : it->second.second)
        cout << x << " ";
       cout << endl;
    }  

    if(test)
        cout << "algorytm ma ujemne sciezki\n";
    else
        cout << "Algorytm nie ma ujemnych sciezek\n";
    
 cout<<"******************************************************************************"<<endl;   
    return 0;
}