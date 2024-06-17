#ifndef MST_H
#define MST_H

#include "Generate_graph.h"

// zawiera algorytmy znajdujące minimalne drzewo spinające
class MST {
    public:
        // informacja czy wypisać wynik na ekran
        enum print {
            yes,
            no
        };

        // algorytm Prima, postać macierzowa
        int** Prim_Matrix(int ** graph, int e, int v, Generate_graph::graph_type type, print p);
        
        // algorytm Prima, postać listowa
        Graph_list** Prim_List(Graph_list** graph, int e, int v, print p);
};

#endif