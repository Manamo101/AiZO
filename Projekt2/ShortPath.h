#ifndef SHORTPATH_H
#define SHORTPATH_H

#include "graph_list.h"

class ShortPah{
    public:
        void Dijkstra_Matrix(int ** graph, int e, int v, int start);
        void Dijkstra_List(Graph_list ** graph, int edges, int vertices, int start);
};

#endif