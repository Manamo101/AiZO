#ifndef SHORTPATH_H
#define SHORTPATH_H

#include "graph_list.h"

// zawiera algorytmy najkrótszej drogi
class ShortPath{
    public:
        // algorytm Dijkstry, postać macierzowa
        void Dijkstra_Matrix(int ** graph, int e, int v, int start, int stop);
        
        // algorytm Dijkstry, postać listowa
        void Dijkstra_List(Graph_list ** graph, int edges, int vertices, int start, int stop);
        
        // algorytm Bellmana-Forda, postać macierzowa
        void BF_Matrix(int ** graph, int e, int v, int start, int stop);
        
        // algorytm Bellmana-Forda, postać listowa
        void BF_List(Graph_list ** graph, int e, int v, int start, int stop);
};

#endif