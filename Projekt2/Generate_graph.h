#ifndef GENERATE_GRAPH_H
#define GENERATE_GRAPH_H

#include "graph_list.h"

class Generate_graph {
    public:
        static int** complete_incidence_matrix(int vertices);
        static Graph_list* complete_adjacency_list(int vertices);

};
#endif