#ifndef MST_H
#define MST_H

#include "Generate_graph.h"

class MST {
    public:
        enum print {
            yes,
            no
        };
        int** Prim_Matrix(int ** graph, int e, int v, Generate_graph::graph_type type, print p);
        int** Kruskal_Matrix(int ** graph, int e, int v, Generate_graph::graph_type type, print p);
        Graph_list** Prim_List(Graph_list** graph, int e, int v, print p);
};

#endif