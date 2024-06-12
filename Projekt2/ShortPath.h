#ifndef SHORTPATH_H
#define SHORTPATH_H

#include "graph_list.h"

class ShortPath{
    public:
        void Dijkstra_Matrix(int ** graph, int e, int v, int start, int stop);
        void Dijkstra_List(Graph_list ** graph, int edges, int vertices, int start, int stop);
        void BF_Matrix(int ** graph, int e, int v, int start, int stop);
        void BF_List(Graph_list ** graph, int e, int v, int start, int stop);
};

#endif