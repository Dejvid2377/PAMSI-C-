/*  bazwa main()
    AdjacencyMatrixGraph<int> adj;
    shared_ptr<Edge<int>> eptr {new Edge<int> (2)};
    shared_ptr<Vertex<int>> vptr {new Vertex<int> (2)};
    for (int i=1;i<7;i++)
        adj.insertVertex(i);
    shared_ptr<Vertex<int>> ptr1 = adj.vertexID(1);
    shared_ptr<Vertex<int>> ptr2 = adj.vertexID(2);
    shared_ptr<Vertex<int>> ptr3 = adj.vertexID(3);
    shared_ptr<Vertex<int>> ptr4 = adj.vertexID(4);
    shared_ptr<Vertex<int>> ptr5 = adj.vertexID(5);
    shared_ptr<Vertex<int>> ptr6 = adj.vertexID(6);
    
    adj.insertEdge(ptr1,ptr2,100); //1
    adj.insertEdge(ptr1,ptr3,200); //2
    adj.insertEdge(ptr1,ptr4,300); //3
    adj.insertEdge(ptr2,ptr1,400); //4 
    adj.insertEdge(ptr2,ptr5,500); //5 
    adj.insertEdge(ptr2,ptr6,600); //6 
    adj.insertEdge(ptr3,ptr6,700); //7 
    adj.insertEdge(ptr4,ptr3,800); //8 
    adj.insertEdge(ptr4,ptr5,900); //9 
    adj.insertEdge(ptr6,ptr1,1000);//10  
    adj.print_matrix();
    cout << endl;

    shared_ptr<Edge<int>> Array[10];
    list<shared_ptr<Edge<int>>> lst = adj.edges();
    auto iter = lst.begin();

    for (int i=0;iter!=lst.end();iter++,i++)
        Array[i] = *iter;
*/
////////////////////////////////////////////////////////////////////////////////////////////////////
/* test endVertices()
    for (int i=0;i<10;i++)
    {
    auto lista = adj.endVertices(Array[i]);
    auto it1 = lista.begin();
    auto it2 = ++lista.begin();
    cout << (*it1)->return_value() <<" "<<(*it2)->return_value() <<" " << Array[i]->return_value()<< endl;
    }
*/  
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*  test opposite()
    cout << (*adj.opposite(ptr1,Array[0])).return_value() << endl;
    cout << (*adj.opposite(ptr1,Array[1])).return_value() << endl;
    cout << (*adj.opposite(ptr4,Array[2])).return_value() << endl;
    cout << (*adj.opposite(ptr2,Array[3])).return_value() << endl;
    cout << (*adj.opposite(ptr5,Array[4])).return_value() << endl;
    cout << (*adj.opposite(ptr2,Array[5])).return_value() << endl;
    cout << (*adj.opposite(ptr3,Array[6])).return_value() << endl;
    cout << (*adj.opposite(ptr3,Array[7])).return_value() << endl;
*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*  test areAdjacent()
    cout << adj.areAdjacent(ptr1,ptr2) << endl;
    cout << adj.areAdjacent(ptr1,ptr4) << endl;
    cout << adj.areAdjacent(ptr4,ptr6) << endl;
    cout << adj.areAdjacent(ptr2,ptr1) << endl;
    cout << adj.areAdjacent(ptr5,ptr2) << endl;
    cout << adj.areAdjacent(ptr2,ptr3) << endl;
    cout << adj.areAdjacent(ptr3,ptr4) << endl;
    cout << adj.areAdjacent(ptr3,ptr1) << endl;
*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*  test replaceV()
    cout << "bylo: "<<ptr5->return_value() << endl;
    adj.replaceV(ptr5,99);
    cout << "jest: " << ptr5->return_value() << endl;
*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*  test replaceE()
    cout << "bylo: "<<Array[2]->return_value() << endl;
         adj.replaceE(Array[2],99);
    cout << "jest: "<<Array[2]->return_value() << endl;
*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*  test removeVertex()
    adj.removeVertex(ptr6);
    adj.print_matrix();
*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*  test removeEdge()
    adj.removeEdge(Array[9]);
    adj.print_matrix();
*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*  test incidentEdges()
    auto lista = adj.incidentEdges(ptr6);
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