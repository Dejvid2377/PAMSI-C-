/*  bazwa main()
    AdjacencyListGraph<int> adj;

    ifstream in("test.txt");
    if(!in)
        cout << "nie ma takiego pliku" << endl;
    
    auto graphPtr = adj.createGraph(in);
    cout << endl;
    auto listGraph = static_pointer_cast<AdjacencyListGraph<int>>(graphPtr);
    
    shared_ptr<Edge<int>> Array[100];
    list<shared_ptr<Edge<int>>> lst = listGraph->edges();
    auto iter = lst.begin();
    for (int i=0;iter!=lst.end();iter++,i++)
        Array[i] = *iter;

    shared_ptr<Vertex<int>> Vrray[100];
    auto lista = listGraph->vertices();
    auto Viter = lista.begin();
    for (int i=0;Viter!=lista.end();Viter++,i++)
        Vrray[i] = *Viter;

    auto ptr = listGraph->vertexID(9);
    auto ptr2 = listGraph->vertexID(0);
*/
////////////////////////////////////////////////////////////////////////////////////////////////////
/* test endVertices()
    for (int i=0;i<10;i++)
    {
    auto lista = listGraph-> endVertices(Array[i]);
    auto it1 = lista.begin();
    auto it2 = ++lista.begin();
    cout << (*it1)->return_value() <<" "<<(*it2)->return_value() <<" " << Array[i]->return_value()<< endl;
    }
*/  
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*  test opposite()
    auto ptr = listGraph->vertexID(9);
    int j= 24;
    cout << ptr->return_value() << endl;
    cout << Array[j]->return_value() << endl;
    cout << (*(listGraph->opposite(ptr,Array[j]))).return_value() << endl;
    return 0;
*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*  test areAdjacent()
    auto ptr = listGraph->vertexID(9);
    auto ptr2 = listGraph->vertexID(0);
    cout << listGraph->areAdjacent(ptr,ptr2) << endl;
*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*  test replaceV()
    cout << "bylo: "<<ptr->return_value() << endl;
    listGraph-> replaceV(ptr,99);
    cout << "jest: " << ptr->return_value() << endl;
*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*  test replaceE()
    int i = 0;
    cout << "bylo: "<<Array[i]->return_value() << endl;
    listGraph-> replaceE(Array[i],99);
    cout << "jest: " << Array[i]->return_value() << endl;
*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*  test removeVertex()
    
    listGraph->print();
    listGraph->removeVertex(ptr);
    listGraph->print();
*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*  test removeEdge()
    
    listGraph->print();
    listGraph->removeEdge(Array[0]);
    listGraph->print();
*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*  test incidentEdges()
    auto lista = listGraph-> incidentEdges(ptr);
    auto iter1 = lista.begin();
    for (;iter1!=lista.end();iter1++)
    {
        cout << (*iter1)->return_value() << endl;
    }
*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* test createGraph()
AdjacencyMatrixGraph<int> adj;
    
    ifstream in("test.txt");
    if(!in)
        cout << "nie ma takiego pliku" << endl;
    
    auto graphPtr = adj.createGraph(in);
    graphPtr->print();
    cout << endl;
    auto matrixGraph = static_pointer_cast<AdjacencyMatrixGraph<int>>(graphPtr);
    matrixGraph->print_matrix();
    cout << endl;
    auto ptr = matrixGraph->vertexID(8);
    matrixGraph->removeVertex(ptr);
    matrixGraph->print();